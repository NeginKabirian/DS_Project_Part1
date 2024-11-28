#pragma once
#include "Singer.h"
template <typename T>
class SparseSet
{
	int* sparse;
	T* dense;
	int size;
	int capacity;
	int maxValue;
public:
	SparseSet(int , int);
	void addsname(Singer&);
	void delseId(int id);
	void findId(int id);
	void prints();
};

template<typename T>
inline SparseSet<T>::SparseSet(int _capacity , int _maxValue) : capacity(_capacity) , maxValue(_maxValue)
{
	sparse = new int[maxValue + 1];
	dense = new T[capacity];
	size = 0;
}
template<>
inline void SparseSet<Singer>::addsname(Singer& singer)
{
	int id = singer.getId();
	if (id > maxValue) {
		throw std::out_of_range("Invalid id for deletion.");
		return;
	}
	if (size >= capacity) {
		cout << "Sparese is Full";
	}
	//search
	dense[size] = singer;
	sparse[id] = size++;
}
template<>
inline void SparseSet<Singer>::delseId(int id)
{
	if (id < 0 || sparse[id] == -1) {
		throw std::out_of_range("Invalid id for deletion.");
	}
		Singer temp = dense[size - 1];
		dense[sparse[id]] = temp;
		sparse[temp.getId()] = sparse[id];
		sparse[id] = -1;
		size--;
}

template<>
inline void SparseSet<Singer>::findId(int id)
{
	if (sparse[id] == -1 || id < 0) {
		throw std::out_of_range("Invalid id for searching.");
	}
	Singer singer = dense[sparse[id]];
	singer.print();
}
template<>
inline void SparseSet<Singer>::prints() {
	for (int i = 0; i < size; ++i) {
		dense[i].printAllInfo();
	}
}

