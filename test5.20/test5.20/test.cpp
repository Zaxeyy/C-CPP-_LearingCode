#include<iostream>
using namespace std;
#define DEFAULT_CAPACITY 3
typedef int Rank;

template<typename T>
class Vector {
private:
	Rank _size;Rank _capacity;T* _elem;
public:
	Vector(int c = DEFAULT_CAPACITY)
	{
		_elem = new T[_capacity = c];_size = 0;
	}//默认构造函数
	Vector(T const* A, Rank lo, Rank hi)
	{
		copyFrom(A, lo, hi);
	}//复制构造函数，从数组A复制秩为lo到hi的元素
	Vector(Vector<T> const& V, Rank lo, Rank hi)
	{
		copyFrom(V._elem, lo, hi);
	}//复制构造函数，从向量V复制秩为lo到hi的元素
	Vector(Vector<T> const& V)
	{
		copyFrom(V._elem, 0, V._size);
	}//将V整体复制到此向量
	~Vector() { delete[]_elem; }//析构函数，释放内存空间，防止野指针


	void copyFrom(T const* A, Rank lo, Rank hi);//复制原有元素
	void expend();//加倍扩容算法
	void shrink();//对半缩容算法
	T& operator[](Rank r) { return _elem[r]; }//T的引用& 目的是为了能使用此操作符做可修改的左值引用，而不是一个值的副本；
	const T& operator[](Rank r)const { return _elem[r]; }//右值访问，只读，加const为了避免拷贝，提高效率；

	Rank insert(Rank r, T const& e);
	Rank remove(Rank lo, Rank hi);
	T remove(Rank T);//remove重载函数，移除单独元素，返回秩
	Rank find(T const& e, Rank lo, Rank hi)const;
	Rank deduplicate();
	void traverse(void (*visit)(T&));
	template<typename VST> void traverse(VST& visit);

	int disordered()const;
	void bubbleSort(Rank lo, Rank hi);
	bool bubble(Rank lo, Rank hi);
};
template<typename T> struct Increase { virtual void operator()(T& e){e++;} };//自增
template<typename T> struct Print { virtual void operator()(T& e){cout << e << endl;} };


template<typename T> void Vector<T>::copyFrom(T const* A, Rank lo, Rank hi)
	{
		_elem = new T[_capacity = max(DEFAULT_CAPACITY, (hi - lo) * 2)];
		for (_size = 0;lo < hi;_size++, lo++)
			_elem[_size] = A[lo];
	}
template<typename T> void Vector<T>::expend()
{
	if (_size < _capacity) return;
	T* oldElem = _elem;
	copyFrom(oldElem, 0, _capacity);
	delete[]oldElem;
}
template<typename T> void Vector<T>::shrink()
{
	if (4 * _size >= _capacity || _capacity <= DEFAULT_CAPACITY)return;
	T* oldElem = _elem;
	copyFrom(oldElem, 0, _size);
	delete[]oldElem;
}
template<typename T> Rank Vector<T>::insert(Rank r, T const& e)
{
	expend();//如必要，先扩容；
	for (Rank i = _size;r < i;i--)
		_elem[i] = _elem[i - 1];
	_elem[r] = e;_size++;return r;
}
template<typename T> Rank Vector<T>::remove(Rank lo, Rank hi)
{
	if (lo == hi)return 0;//没有需要删除的元素
	while (hi < _size)_elem[lo++] = _elem[hi++];
	_size = lo;
	shrink();
	return hi - lo;
}
template<typename T> T Vector<T>::remove(Rank r)
{
	T e = _elem[r];
	remove(r, r + 1);
	return e;
}
template<typename T> Rank Vector<T>::find(T const& e, Rank lo, Rank hi) const//常量成员函数，const类型对象只能调用此类函数，并且此函数不能修改成员变量
{
	while ((lo < hi--) && (e != _elem[hi]));
	return hi;//返回秩最大的元素的秩，若不存在该元素，则返回lo-1的数，代表查找无果
} 
template<typename T> Rank Vector<T>::deduplicate()
{
	Rank oldSize = _size;
	for (Rank i = 1;i < _size;)
		if (-1 == find(_elem[i], 0, i))
			i++;
		else remove(i);
	return oldSize - _size;
} 
template<typename T> void Vector<T>::traverse(void (*visit)(T&))
{
	for (int i = 0;i < _size;i++)visit(_elem[i]);
}//利用函数指针机制，只读或局部修改
template<typename T> template<typename VST> 
void Vector<T>::traverse(VST& visit)
{
	for (int i = 0;i < _size;i++) visit(_elem[i]);
}//利用函数对象机制，可全局修改
template<typename T> int Vector<T>::disordered() const
{
	int n = 0;//计数器
	for (int i = 1;i < _size;i++)
		n += (_elem[i - 1] > _elem[i]);//逆序数统计
	return n;
}//若只需要判断是否有序，则首次遇到逆序对后，即可立即终止
template<typename T> bool Vector<T>::bubble

int main()
{
	int A[10] = { 1,2,3,4,5,6,7,8,9,10 };
	Vector<int> v(A, 0, 10);
	Print<int> p;
	v.traverse(p);
	return 0;
}