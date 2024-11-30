#pragma once
#include "Singer.h"
#include "PlayList.h"
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
	void addsname(const string&);
	void addpname(const string&);
	void delseId(int id);
	void findId(int id);
	void prints();
	void cls();
	//void addmp(int, int);
	void addms(string, int, string, int);
	void findmname(const string);

};

template<typename T>
inline SparseSet<T>::SparseSet(int _capacity , int _maxValue) : capacity(_capacity) , maxValue(_maxValue)
{
	sparse = new int[maxValue + 1];
	dense = new T[capacity];
	size = 0;
}
template<>
inline void SparseSet<Singer>::addsname(const string& name)
{
	Singer* singer = new Singer(name);
	if (size >= capacity) {
		cout << "Sparese is Full";
	}
	//search
	dense[size] = *singer;
	if (singer->getId() > maxValue) {
		throw std::out_of_range("Invalid id for deletion.");
		return;
	}
	sparse[singer->getId()] = size++;
}
template<>
inline void SparseSet<Singer>::delseId(int id)
{
	if (id < 0 || sparse[dense[id].getId()] == -1) {
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
	if (id < 0 || sparse[dense[id].getId()] == -1) {
		throw std::out_of_range("Invalid id for searching.");
	}
	Singer singer = dense[sparse[id]];
	singer.print();
}
template<>
inline void SparseSet<Singer>::prints() { //change to generic
	for (int i = 0; i < size; ++i) {
		dense[i].printAllInfo();
	}
}

template<typename T>
inline void SparseSet<T>::cls()
{
	size = 0;
}

template<>
inline void SparseSet<PlayList>::addpname(const string& name)
{
	PlayList* p = new PlayList(name);
	if (size >= capacity) {
		cout << "Sparese is Full";
	}
	//search
	dense[size] = *p;
	if (p->getId() > maxValue) {
		throw std::out_of_range("Invalid id for deletion.");
		return;
	}
	sparse[p->getId()] = size++;
}
template<>
inline void SparseSet<Singer>::addms(const string music_name, int year,const string lyrics, int artist_id)  //handele lyrics input  //suffix array
{
	Music* music = new Music(music_name, year, lyrics);
	if (artist_id < 0 || artist_id > maxValue||sparse[dense[artist_id].getId()] == -1 ) {
		throw std::out_of_range("Invalid artist_id.");
		return;
	}
	dense[artist_id].getMusic().push_front(*music);
}
template<>
inline void SparseSet<Singer>::findmname(const string music_name)  //order ?
{
	for (int i = 0 ; i < size ; ++i) {
		auto music = dense[i].getMusic();
		auto temp = music.GetHead();
		while (temp) {
			if (temp->getData().getName() == music_name) {
				temp->getData().print();
			}
			temp = temp->getNext();
		}
	}
}
//template<typename T>
//inline void SparseSet<T>::addmp(int music_id, int playlist_id) //search ig in All LinkedList>
//{
//
//}