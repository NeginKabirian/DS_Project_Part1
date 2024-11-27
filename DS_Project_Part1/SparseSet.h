#pragma once
#include "Singer.h"
template <typename T>
class SparseSet
{
	int* sparse;
	T* dense;
	int n;
	int capacity;
	int maxValue;
public:
	SparseSet(int , int);
	void addsname(Singer&);
};

template<typename T>
inline SparseSet<T>::SparseSet(int _capacity, int _maxValue) : capacity(_capacity) , maxValue(_maxValue)
{
	sparse = new int(maxValue + 1);
	dense = new T(capacity);
	n = 0;
}
template<>
inline void SparseSet<Singer>::addsname(Singer& singer)
{
	int id = singer.getId();
	if (id > maxValue) {
		cout << "Id is not Vallid";
		return;
	}
	if (n >= capacity) {
		cout << "Sparese is Full";
	}
	//search
	dense[n] = singer;
	sparse[id] = n++;
}
;
