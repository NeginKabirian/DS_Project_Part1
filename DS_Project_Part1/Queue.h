#pragma once
#include "Playlist.h"
template<typename T>
class Queue {
	T* arr;
	int capacity;
	int front;
	int rear;
public:
	Queue(int);
	void push(const T&);
	void pop();
	T& getFront()const;
	T& getRear()const;
};


template<typename T>
inline Queue<T>::Queue(int _capacity) : capacity(_capacity) ,front(0),rear(0)
{
	if (capacity < 1) {
		throw exception("Queue capacity must be greather than one");
	}
	arr = new T[capacity];
}

template<typename T>
inline void Queue<T>::push(const T& data)
{
	if ((rear+1) % capacity == front) {
		T* NewArr = new T[2 * capacity];
		int start = (front + 1) % capacity;
		if (start <= rear) {
			for (int i = 0; i < rear - start + 1; ++i) {
				NewArr[i] = arr[(start + i) % capacity];
			}
		}
		else {
			int i = 0;
			for (; i < start < capacity; ++i , ++start) {
				NewArr[i] = arr[start];
			}
			for (int j = 0; j < rear + 1; ++j , ++i) {
				NewArr[i] = arr[j];
			}
		}
		front = 2 * capacity - 1;
		rear = capacity - 2;
		capacity *= 2;
		delete[] arr;
		arr = NewArr;
		cout << "here";
	}
	rear = (rear + 1) % capacity;
	arr[rear] = data;
	cout << "PlayList Pushed successfully!\n";
	
}

template<typename T>
inline void Queue<T>::pop()
{
	if (rear == front) {
		throw exception("Queue is empty\n");
	}
	front = (front + 1) % capacity;
	cout << "PlayList Poped successfully!\n";
}

template<typename T>
inline T& Queue<T>::getFront() const
{
	if (rear == front) {
		throw exception("Queue is empty\n");
	}
	return arr[(front + 1) % capacity];
}

template<typename T>
inline T& Queue<T>::getRear() const
{
	if (rear == front) {
		throw exception("Queue is empty\n");
	}
	return arr[rear];
}
