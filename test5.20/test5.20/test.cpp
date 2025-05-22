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
	}//Ĭ�Ϲ��캯��
	Vector(T const* A, Rank lo, Rank hi)
	{
		copyFrom(A, lo, hi);
	}//���ƹ��캯����������A������Ϊlo��hi��Ԫ��
	Vector(Vector<T> const& V, Rank lo, Rank hi)
	{
		copyFrom(V._elem, lo, hi);
	}//���ƹ��캯����������V������Ϊlo��hi��Ԫ��
	Vector(Vector<T> const& V)
	{
		copyFrom(V._elem, 0, V._size);
	}//��V���帴�Ƶ�������
	~Vector() { delete[]_elem; }//�����������ͷ��ڴ�ռ䣬��ֹҰָ��


	void copyFrom(T const* A, Rank lo, Rank hi);//����ԭ��Ԫ��
	void expend();//�ӱ������㷨
	void shrink();//�԰������㷨
	T& operator[](Rank r) { return _elem[r]; }//T������& Ŀ����Ϊ����ʹ�ô˲����������޸ĵ���ֵ���ã�������һ��ֵ�ĸ�����
	const T& operator[](Rank r)const { return _elem[r]; }//��ֵ���ʣ�ֻ������constΪ�˱��⿽�������Ч�ʣ�

	Rank insert(Rank r, T const& e);
	Rank remove(Rank lo, Rank hi);
	T remove(Rank T);//remove���غ������Ƴ�����Ԫ�أ�������
	Rank find(T const& e, Rank lo, Rank hi)const;
	Rank deduplicate();
	void traverse(void (*visit)(T&));
	template<typename VST> void traverse(VST& visit);

	int disordered()const;
	void bubbleSort(Rank lo, Rank hi);
	bool bubble(Rank lo, Rank hi);
};
template<typename T> struct Increase { virtual void operator()(T& e){e++;} };//����
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
	expend();//���Ҫ�������ݣ�
	for (Rank i = _size;r < i;i--)
		_elem[i] = _elem[i - 1];
	_elem[r] = e;_size++;return r;
}
template<typename T> Rank Vector<T>::remove(Rank lo, Rank hi)
{
	if (lo == hi)return 0;//û����Ҫɾ����Ԫ��
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
template<typename T> Rank Vector<T>::find(T const& e, Rank lo, Rank hi) const//������Ա������const���Ͷ���ֻ�ܵ��ô��ຯ�������Ҵ˺��������޸ĳ�Ա����
{
	while ((lo < hi--) && (e != _elem[hi]));
	return hi;//����������Ԫ�ص��ȣ��������ڸ�Ԫ�أ��򷵻�lo-1��������������޹�
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
}//���ú���ָ����ƣ�ֻ����ֲ��޸�
template<typename T> template<typename VST> 
void Vector<T>::traverse(VST& visit)
{
	for (int i = 0;i < _size;i++) visit(_elem[i]);
}//���ú���������ƣ���ȫ���޸�
template<typename T> int Vector<T>::disordered() const
{
	int n = 0;//������
	for (int i = 1;i < _size;i++)
		n += (_elem[i - 1] > _elem[i]);//������ͳ��
	return n;
}//��ֻ��Ҫ�ж��Ƿ��������״���������Ժ󣬼���������ֹ
template<typename T> bool Vector<T>::bubble

int main()
{
	int A[10] = { 1,2,3,4,5,6,7,8,9,10 };
	Vector<int> v(A, 0, 10);
	Print<int> p;
	v.traverse(p);
	return 0;
}