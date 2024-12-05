#pragma once
#include "Playlist.h"
template<typename T>
class Queue {
	T* arr;
	int capacity;
	//int size;
	int front;
	int rear;
public:
	Queue(int);
	void push(T&);
	void pop();
	T* front();
	T* rear();
};


template<typename T>
inline Queue<T>::Queue(int _capacity) : capacity(_capacity) ,size(0),front(0),rear(0)
{
	arr = new T[capacity];
}

template<typename T>
inline void Queue<T>::push(T& data)
{
	if ((rear+1) % capacity == front) {
		////2*capacity
		//auto temp = arr;
		//delete arr;
		//arr = new T[2 * capacity];
		///*for (int i = 0; i <= rear; ++i) {
		//	arr[i] = temp[i];
		//}*/
		//delete temp;
	}
	rear = (rear + 1) % capacity;
	arr[rear] = data;
	//size++;
}

template<typename T>
inline void Queue<T>::pop()
{
	//destructor arr[front]
	front = (front + 1) % capacity;
}

template<typename T>
inline T* Queue<T>::front()
{
	return arr[front];
}

template<typename T>
inline T* Queue<T>::rear()
{
	return arr[rear];
}
