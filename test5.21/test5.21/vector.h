//代码复现，Vector向量复习
#pragma once
#include"head.h"
using  Rank = unsigned int; //秩
#define DEFAULT_CAPACITY 3 //默认初始容量

template<typename T> class Vector {//向量模板类
protected://内部数据，保护类
	Rank _size; Rank _capacity; T* _elem;//规模、容量、数据区
	void copyFrom(T const* A, Rank lo, Rank hi);//复制数组区间[lo,hi)
	void expand();//空间不足时扩容
	void shrink();//装填因子过小时缩容
	bool bubble(Rank lo, Rank hi);//扫描交换
	void bubbleSort(Rank lo, Rank hi);//冒泡排序法
	Rank maxItem(Rank lo, Rank hi);//选取最大元素
	void selectionSort(Rank lo, Rank hi);//选择排序法
	void merge(Rank lo,Rank mi,Rank hi);//归并算法
	void mergeSort(Rank lo, Rank hi);//归并排序法
	void heapSort(Rank lo, Rank hi);//堆排序
	Rank partition(Rank lo, Rank hi);//轴点构造算法
	void quickSort(Rank lo, Rank hi);//快速排序算法
	void shellSort(Rank lo, Rank hi);//希尔排序算法
public://接口
	//构造函数
	Vector(Rank c=DEFAULT_CAPACITY) { _elem = new T[_capacity = c];_size = 0; }//默认构造容量为c的向量
	Vector(Rank c, Rank s, T v) { _elem = new T[_capacity = c];for (_size = 0;_size < s;_elem[_size++] = v); }
	//构造容量为c,规模为s,所有元素初始值为v；
	Vector(T const* A, Rank n) { copyFrom(A, 0, n); }//整体复制
	Vector(T const*A,Rank lo,Rank hi) { copyFrom(A, lo, hi); }//复制区间
	Vector(Vector<T> const& V) { copyFrom(V._elem, 0, V._size); }//用另一个容器初始化
	Vector(Vector<T> const& V, Rank lo, Rank hi) { copyFrom(V._elem, lo, hi); }//区间
	~Vector() { delete[]_elem; }//析构函数
	//只读访问接口
	Rank size() const { return _size; }//规模
	bool empty()const { return !_size; }//判空
	Rank find(T const& e)const { return find(e, 0, _size); }//无序向量整体查找
	Rank find(T const& e, Rank lo, Rank hi)const;//无序向量区间查找
	Rank select(Rank k) { return quickSelect(_elem, _size, k); }//从无需向量中找到第k大的元素
	Rank search(T const& e)const { return (0 >= _size) ? -1 : search(e, 0, _size); }//有序向量整体查找
	Rank search(T const& e, Rank lo, Rank hi)const ;//有序向量区间查找
	//可写访问接口
	T& operator[](Rank r) { return _elem[r]; }//重载下标操作符
	const T& operator[](Rank r) const { return _elem[r]; }//仅限于做右值重载
	Vector<T>& operator=(Vector<T>const& V) {
		if (this == &V)return *this;
		delete[]_elem;
		copyFrom(V._elem, 0, V._size);
		return *this;
	}//重载赋值操作符，以便直接克隆向量,this为对象指针，指向对象起始地址，可以用this->xx的方法来返回对象私有数据；
	T remove(Rank r);//删除秩为r的元素
	Rank remove(Rank lo, Rank hi);//区间删除[lo,hi)
	Rank insert(Rank r, T const& e);//e插入秩r
	Rank insert(T const& e) { return insert(_size, e); }//末尾插入
	void sort(Rank lo, Rank hi);//区间排序
	void sort() { sort(0._size); }//默认整体排序
	void unsort(Rank lo, Rank hi);//区间乱序
	void unsort() { unsort(0, _size); }//整体乱序
	Rank dedup();//无序去重
	Rank uniquify();//有序去重

	void traverse(void(*visit)(T&));//遍历：函数指针，只读或局部性修改可用
	template<typename VST>void traverse(VST& visit);//遍历：函数对象，可全局修改

};


template<typename T> void Vector<T>::copyFrom(T const* A, Rank lo, Rank hi) {
	_elem = new T[_capacity = maximum(DEFAULT_CAPACITY, (hi - lo) << 1)];
	for (_size = 0;lo < hi;_size++, lo++)
		_elem[_size] = A[lo];
}//使用const修饰A为了防止A被篡改
template<typename T> void Vector<T>::expand()
{
	if (_size < _capacity)return;
	T* oleElem = _elem;
	copyFrom(oleElem, 0, _capacity);
	delete[]oldElem;
}
template<typename T> void Vector<T>::shrink()
{
	if (_capacity < DEFAULT_CAPACITY << 1) return;
	if (_size << 2 > _capacity)return;
	T* oldElem = _elem;
	_elem = new T[_capacity >>= 1];
	for (Rank i = 0;i < _size;i++)_elem[i] = oldElem[i];
	delete[]oldElem;
}
template<typename T> bool Vector<T>::bubble(Rank lo, Rank hi) {
	for (bool sorted = true;lo < hi-1;lo++)
	{
		if (_elem[lo] > _elem[lo + 1])swap(_elem[lo], _elem[lo + 1]);
		sorted = false;
	}
}
template<typename T> void Vector<T>::bubbleSort(Rank lo, Rank hi) {
	for(Rank last;lo<hi;hi=last)
		for(Rank i=(last=lo)+1;i<hi;i++)
			if (_elem[i - 1] > _elem[i])
			{
				swap(_elem[i - 1], _elem[i]);last = i;
			}
}
template<typename T> Rank Vector<T>::maxItem(Rank lo, Rank hi) {
	Rank max = lo;
	for (int i = lo;lo < hi;lo++)
		if (_elem[max] <= _elem[i])
			max = i;
	return max;
}
template<typename T> void Vector<T>::merge(Rank lo,Rank mi,Rank hi) {
	T* A = _elem + lo;//最终容器地址
	int lb = mi - lo;T* B = new T[lb];//将前半部分移动至新的容器B中
	for (Rank i = 0;i < lb;B[i] = A[i++]);//移动前半部分到容器B中
	int lc = hi - mi;T* C = _elem + mi;//后半部分起始地址C，元素个数lc
	for (Rank i = 0, j = 0, k = 0;j < lb) {
		if (lc <= k || B[j] <= C[k])A[i++] = B[j++];
		if (k < lc && C[k] < B[j])A[i++] = C[k++];
	}
	delete[]B;
}
template<typename T> void Vector<T>::mergeSort(Rank lo, Rank hi)
{
	if (hi - lo < 2)return;
	Rank mi = (lo + hi) >> 1;
	mergeSort(lo, mi);
	mergeSort(mi, hi);
	merge(lo, mi, hi);
}
template<typename T> Rank Vector<T>::find(T const& e, Rank lo, Rank hi) const {
	while ((lo < hi--) && (e != _elem[hi]));
	return hi;
}
template<typename T> Rank Vector<T>::search(T const& e, Rank lo, Rank hi)const {
	while (lo<hi) {
		Rank mi = (lo + hi) >> 1;
		e < _elem[mi] ? hi = mi : lo = mi + 1;
	}
	return lo - 1;
}
template<typename T> T Vector<T>::remove(Rank r) {
	T e = _elem[r];
	remove(r, r + 1);
	return e;
}
template<typename T> Rank Vector<T>::remove(Rank lo, Rank hi) {
	if (lo == hi)return 0;
	while (hi < _size)_elem[lo++] = _elem[hi++];
	_size = lo;
	shrink();
	return hi - lo;
}
template<typename T> Rank Vector<T>::insert(Rank r, T const& e) {
	expand();
	for (Rank i = _size;r < i;i--)
		_elem[i] = _elem[i - 1];
	_elem[r] = e;_size++;return r;
}
template<typename T> void Vector<T>::sort(Rank lo, Rank hi) {
	mergeSort(lo, hi);
}
template<typename T> Rank Vector<T>::dedup() {
	Rank oldSize = _size;
	for (Rank i = 1;i < _size) {
		if (-1 == find(_elem[i], 0, i))
			i++;
		else {
			remove(i);_size--;
		}
	}
	return oldSize - _size;
}
template<typename T> Rank Vector<T>::uniquify() {
	Rank i = 0, j = 0;
	while (++j < _size)
		if (_elem[i] != _elem[j])
			_elem[++i] = _elem[j];
	_size = ++i;
	shrink();
	return j - i
}
template<typename T> void Vector<T>::traverse(void(*visit)(T&)) {
	for (Rank i = 0;i < _size;i++)visit(_elem[i]);
}
template<typename T> template<typename VST> void Vector<T>::traverse(VST& visit) {
	for (Rank i = 0;i < _size;i++)visit(_elem[i]);
}