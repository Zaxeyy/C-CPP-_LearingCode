//���븴�֣�Vector������ϰ
#pragma once
#include"head.h"
using  Rank = unsigned int; //��
#define DEFAULT_CAPACITY 3 //Ĭ�ϳ�ʼ����

template<typename T> class Vector {//����ģ����
protected://�ڲ����ݣ�������
	Rank _size; Rank _capacity; T* _elem;//��ģ��������������
	void copyFrom(T const* A, Rank lo, Rank hi);//������������[lo,hi)
	void expand();//�ռ䲻��ʱ����
	void shrink();//װ�����ӹ�Сʱ����
	bool bubble(Rank lo, Rank hi);//ɨ�轻��
	void bubbleSort(Rank lo, Rank hi);//ð������
	Rank maxItem(Rank lo, Rank hi);//ѡȡ���Ԫ��
	void selectionSort(Rank lo, Rank hi);//ѡ������
	void merge(Rank lo,Rank mi,Rank hi);//�鲢�㷨
	void mergeSort(Rank lo, Rank hi);//�鲢����
	void heapSort(Rank lo, Rank hi);//������
	Rank partition(Rank lo, Rank hi);//��㹹���㷨
	void quickSort(Rank lo, Rank hi);//���������㷨
	void shellSort(Rank lo, Rank hi);//ϣ�������㷨
public://�ӿ�
	//���캯��
	Vector(Rank c=DEFAULT_CAPACITY) { _elem = new T[_capacity = c];_size = 0; }//Ĭ�Ϲ�������Ϊc������
	Vector(Rank c, Rank s, T v) { _elem = new T[_capacity = c];for (_size = 0;_size < s;_elem[_size++] = v); }
	//��������Ϊc,��ģΪs,����Ԫ�س�ʼֵΪv��
	Vector(T const* A, Rank n) { copyFrom(A, 0, n); }//���帴��
	Vector(T const*A,Rank lo,Rank hi) { copyFrom(A, lo, hi); }//��������
	Vector(Vector<T> const& V) { copyFrom(V._elem, 0, V._size); }//����һ��������ʼ��
	Vector(Vector<T> const& V, Rank lo, Rank hi) { copyFrom(V._elem, lo, hi); }//����
	~Vector() { delete[]_elem; }//��������
	//ֻ�����ʽӿ�
	Rank size() const { return _size; }//��ģ
	bool empty()const { return !_size; }//�п�
	Rank find(T const& e)const { return find(e, 0, _size); }//���������������
	Rank find(T const& e, Rank lo, Rank hi)const;//���������������
	Rank select(Rank k) { return quickSelect(_elem, _size, k); }//�������������ҵ���k���Ԫ��
	Rank search(T const& e)const { return (0 >= _size) ? -1 : search(e, 0, _size); }//���������������
	Rank search(T const& e, Rank lo, Rank hi)const ;//���������������
	//��д���ʽӿ�
	T& operator[](Rank r) { return _elem[r]; }//�����±������
	const T& operator[](Rank r) const { return _elem[r]; }//����������ֵ����
	Vector<T>& operator=(Vector<T>const& V) {
		if (this == &V)return *this;
		delete[]_elem;
		copyFrom(V._elem, 0, V._size);
		return *this;
	}//���ظ�ֵ���������Ա�ֱ�ӿ�¡����,thisΪ����ָ�룬ָ�������ʼ��ַ��������this->xx�ķ��������ض���˽�����ݣ�
	T remove(Rank r);//ɾ����Ϊr��Ԫ��
	Rank remove(Rank lo, Rank hi);//����ɾ��[lo,hi)
	Rank insert(Rank r, T const& e);//e������r
	Rank insert(T const& e) { return insert(_size, e); }//ĩβ����
	void sort(Rank lo, Rank hi);//��������
	void sort() { sort(0._size); }//Ĭ����������
	void unsort(Rank lo, Rank hi);//��������
	void unsort() { unsort(0, _size); }//��������
	Rank dedup();//����ȥ��
	Rank uniquify();//����ȥ��

	void traverse(void(*visit)(T&));//����������ָ�룬ֻ����ֲ����޸Ŀ���
	template<typename VST>void traverse(VST& visit);//�������������󣬿�ȫ���޸�

};


template<typename T> void Vector<T>::copyFrom(T const* A, Rank lo, Rank hi) {
	_elem = new T[_capacity = maximum(DEFAULT_CAPACITY, (hi - lo) << 1)];
	for (_size = 0;lo < hi;_size++, lo++)
		_elem[_size] = A[lo];
}//ʹ��const����AΪ�˷�ֹA���۸�
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
	T* A = _elem + lo;//����������ַ
	int lb = mi - lo;T* B = new T[lb];//��ǰ�벿���ƶ����µ�����B��
	for (Rank i = 0;i < lb;B[i] = A[i++]);//�ƶ�ǰ�벿�ֵ�����B��
	int lc = hi - mi;T* C = _elem + mi;//��벿����ʼ��ַC��Ԫ�ظ���lc
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