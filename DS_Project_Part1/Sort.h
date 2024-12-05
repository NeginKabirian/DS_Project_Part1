#pragma once
#include "LinkedList.h"
#include <cmath>
template <typename T>
class Sort {
public:
	void Radix(int* , int );
};

template<typename T>
inline void Sort<T>::Radix(int* arr,int n)
{
	int max = arr[0] , T,d = 0;
	LinkedList<int>* temp = new LinkedList<int>[10];
	for (int i = 0; i < n; ++i) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	while (max) {
		max /= 10;
		d++;
	}
	for (int j = 0; j < d; ++j) {
		for (int i = 0; i < n; ++i) {
			temp[(static_cast<int>(arr[i] / pow(10, j))) % 10].push_back(arr[i]);
		}
		int index = 0;
		for (int k = 0; k < 10; ++k) {
			while (!temp[k].empty()) {
				arr[index++] = temp[k].front();
				temp[k].pop_front();
			}
		}
	}
	delete[] temp;
}