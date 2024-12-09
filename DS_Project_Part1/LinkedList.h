#pragma once
#include <stdexcept>
#include"Music.h"
template<typename T>
class Node

{
	T data;
	Node<T>* next;
	Node<T>* prev;
public:
	Node(const T& data) : data(data)
	{
		next = nullptr;
		prev = nullptr;
	}
	Node() {
		next = prev = nullptr;
	}
	T& getData() {
		return this->data;
	}
	Node<T>*& getNext() {
		return this->next;
	}
	Node<T>*& getPrev() {
		return this->prev;
	}
	template<typename>
	friend class LinkedList;
};
template <typename T>
class LinkedList
{
public:
	LinkedList();
	LinkedList(const LinkedList<T>&);
	bool empty() const;
	const T& front() const;
	const T& back() const;
	void push_front(const T&);
	void push_back(const T&);
	void pop_front();
	void pop_back();
	void pop_node(Node<T>*&);
	void print();
	~LinkedList();
	Node<T>*& GetHead();
	Node<T>*& GetTail();
private:
	Node<T>* head;
	Node<T>* tail;
	
};

template<typename T>
bool LinkedList<T>::empty() const
{
	if (!head) {
		return true;
	}
	return false;
}
template<typename T>
Node<T>*& LinkedList<T>::GetHead(){
	return head;
}
template<typename T>
inline Node<T>*& LinkedList<T>::GetTail()
{
	return tail;
}
template<typename T>
LinkedList<T>::LinkedList() {
	head = tail = nullptr;
}
template<typename T>
inline LinkedList<T>::LinkedList(const LinkedList<T>& other)
{
	Node<T>* current = other.head; 
	this->head = nullptr;
	this->tail = nullptr;
	while (current) {
		this->push_back(current->data);
		current = current->next;
	}
}

template <typename T>
const T& LinkedList<T>::front()const {
	if (this->empty()) {
		throw(out_of_range("queue is empty"));	
	}
	return head->data;
}
template <typename T>
const T& LinkedList<T>::back()const {
	if (this->empty()) {
		throw(out_of_range("queue is empty"));
	}
	return tail->data;
}

template<typename T>
void LinkedList<T>::push_front(const T& data)
{
	Node<T>* node = new Node<T>(data);
	if (this->empty()) {
		head = tail = node;
		return;
	}
	node->next = head;
	head->prev = node;
	head = node;
}

template<typename T>
void LinkedList<T>::push_back(const T& data)
{
	Node<T>* node = new Node<T>(data);
	if (this->empty()) {
		head = tail = node;
		return;
	}
	node->prev = tail;
	tail->next = node;
	tail = node;
}

template<typename T>
void LinkedList<T>::pop_front()
{
	if (this->empty()) {
		throw std::out_of_range("LinkedList is empty");
	}
	if (head == tail) {
		delete head;
		head = tail = nullptr;
		return;
	}
	Node<T>* temp = head;
	head = head->next;
	head->prev = nullptr;
	delete temp;
}

template<typename T>
void LinkedList<T>::pop_back()
{
	if (this->empty()) {
		throw std::out_of_range("LinkedList is empty");
	}

	if (head == tail) {
		delete tail;
		head = tail = nullptr;
	}
	Node<T>* temp = tail;
	tail = tail->prev;
	tail->next = nullptr;
	delete temp;
}

template<typename T>
inline void LinkedList<T>::pop_node(Node<T>*& delnode)
{
	auto prev = delnode->getPrev();
	auto next = delnode->getNext();
	if (prev == nullptr && next == nullptr) {
		head = nullptr;
		tail = nullptr;
		return;
	}
	if (prev == nullptr) {
		head = next;
		return;
	}
	if (next == nullptr) {
		prev->next = nullptr;
		tail = prev;
		delete delnode;
		delnode = nullptr;
		return;
	}
	prev->getNext() = next;
	next->getPrev() = prev;
	delete delnode;
	delnode = nullptr;
}

template<typename T>
void LinkedList<T>::print()
{
	std::cout << std::endl;
	if (!empty()) {
		for (Node<T>* i = head; i != nullptr; i = i->next) {
			std::cout << i->getData() << " ";
		}
		std::cout << std::endl;
	}
}
template<>
inline void LinkedList<Music>::print() {
	for (Node<Music>* i = head; i != nullptr; i = i->next) {
		std::cout << "Name: " << i->getData().getName() << std::endl;
		std::cout << "Lyrics: " << i->getData().getLyrics() << std::endl;
		cout << "year : " << i->getData().getYear()<<endl;
	}
}
template<typename T>
LinkedList<T>::~LinkedList() {
}
