#pragma once
#include "Singer.h"
#include "PlayList.h"
#include "Queue.h"
#include <type_traits>
template <typename T>
class SparseSet
{
	int* sparse;
	T* dense;
	int size;
	int capacity;
	int maxValue;
	Queue<PlayList>* queue;
public:
	SparseSet(int , int);
	void addsname(const string&);
	void addpname(const string&);
	void delseId(int id);
	void findId(int id);
	void prints();
	void cls();
	void addmp(int, int, SparseSet<Singer>& singer);
	void addms(const string, int,const string, int);
	void findmname(const string);
	Music& searchmId(int music_id);
	void delm(int, int, SparseSet<PlayList>&);
	int search(int, int,const string&);
	int countw(int, int,const string&);
	Music& searchm(int, int);
	void delmp(int, int);
	int getSize();
	T*& getDense();
	void searchpid(int id);
	void showp(int playlist_id);
	void addqpid(int id);
	void pop();

};

template<typename T>
inline SparseSet<T>::SparseSet(int _capacity , int _maxValue) : capacity(_capacity) , maxValue(_maxValue)
{
	sparse = new int[maxValue + 1];
	dense = new T[capacity];
	size = 0;
}
template<>
inline SparseSet<PlayList>::SparseSet(int _capacity, int _maxValue) : capacity(_capacity), maxValue(_maxValue)
{
	sparse = new int[maxValue + 1];
	dense = new PlayList[capacity];
	size = 0;
	queue = new Queue<PlayList>(2);
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
inline void SparseSet<Singer>::addms(const string music_name, int year, const string lyrics, int artist_id)  //handele lyrics input  //suffix array
{
	Music* music = new Music(music_name, year, lyrics);
	   //cout <<"id" << music->getId();
	if (artist_id < 0 || artist_id > maxValue|| artist_id >= size|| sparse[dense[artist_id].getId()] == -1 ) {
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
template<>
inline Music& SparseSet<Singer>::searchmId(int music_id)
{
	Singer s;
	Node<Music>* temp = nullptr;
	for (int i = 0; i < size; ++i) {
		s = dense[i];
		temp = s.getMusic().GetHead();
		while (temp) {
			if (temp->getData().getId() == music_id) {
				return temp->getData();
				}
			temp = temp->getNext();
			}
	}
	if (temp == nullptr) {
		throw exception("music not found");
	}
}
template<>
inline void SparseSet<Singer>::delm(int artist_id, int music_id, SparseSet<PlayList>& playlist)
{
	if (artist_id < 0 || artist_id > maxValue || artist_id >= size|| sparse[dense[artist_id].getId()] == -1) {
		throw std::out_of_range("Invalid artist_id.");
		return;
	}
	/*sparse[dense[artist_id].getId()] = sparse[dense[size].getId()];
	dense[artist_id] = dense[size];
	sparse[dense[size].getId()] = -1;
	size--;*/
	
	Singer& singer = dense[artist_id];
	LinkedList<Music>& music = singer.getMusic();
	auto temp = music.GetHead();
	while (temp) {
		if (music_id == temp->getData().getId()) {
			//del Node LinkedList
			music.pop_node(temp);
			int size = playlist.getSize();
			for (int i = 0; i < size; ++i) {
				int playlist_id = playlist.getDense()[i].getId();
				playlist.delmp(playlist_id, music_id);
			return;
		}
		temp = temp->getNext();
	}
		cout << "music_id Not Found";
	}
}
template<>
inline int SparseSet<Singer>::countw(int artist_id, int music_id, const string& word)
{
	auto singer = dense[artist_id];
	auto temp = singer.getMusic().GetHead();
	while (temp) {
		if (temp->getData().getId() == music_id) {
			Music music = temp->getData();
			return music.countw(word);
		}
		temp = temp->getNext();
	}
	if (temp == nullptr) {
		throw exception("music not found");
	}
}
template<>
inline int SparseSet<Singer>::search(int artist_id, int music_id,const string& word)
{
	auto singer = dense[artist_id];
	auto temp = singer.getMusic().GetHead();
	while (temp) {
		if (temp->getData().getId() == music_id) {
			Music music = temp->getData();
			return music.search(word);
		}
		temp = temp->getNext();
	}
	if (temp == nullptr) {
		throw exception("music not found");
	}
}
template<>
inline void SparseSet<PlayList>::addmp(int music_id, int playlist_id, SparseSet<Singer>& singer) //search ig in All LinkedList>
{
	auto&  playlist = dense[playlist_id];
	if (music_id < 0 || playlist_id < 0 || playlist_id > maxValue || playlist_id >= size  ||  sparse[playlist.getId()] == -1) {  //error
		throw std::out_of_range("Invalid Id.");
	}
	auto& music = singer.searchmId(music_id);
	
	playlist.getMusic().push_front(music);
	
}
template<>
inline Music& SparseSet<PlayList>::searchm(int playlist_id, int music_id)
{
	auto  playlist = dense[playlist_id];
	if (music_id < 0 || playlist_id < 0 || playlist_id > maxValue || playlist_id >= size || sparse[playlist.getId()] == -1) {
		throw std::out_of_range("Invalid Id.");
	}
	auto& temp = playlist.getMusic().GetHead();
	while (temp) {
		if (temp->getData().getId() == music_id) {
			return temp->getData();
		}
		temp = temp->getNext();
	}
	if (temp == nullptr) {
		//throw exception("music not found");
		cout << "music not found";
		
	}
}

template<typename T>
inline void SparseSet<T>::delmp(int playlist_id, int music_id)
{
	auto&  playlist = dense[playlist_id];
	auto& temp = playlist.getMusic().GetHead();
	while (temp) {
		if (temp->getData().getId() == music_id) {
			break; temp->getData();
		}
		temp = temp->getNext();
	}
	playlist.getMusic().pop_node(temp);
}

template<typename T>
inline int SparseSet<T>::getSize()
{
	return size;
}

template<typename T>
inline T*& SparseSet<T>::getDense()
{
	return dense;
}

template<>
inline void SparseSet<PlayList>::searchpid(int id)
{
	int start = 0;
	int end = 0;
	while (start <= end) {
		int mid = start + (end - start)/ 2;
		if (dense[mid].getId() == id) {
			//print
			dense[mid].printAllInfo();
			return;
		}
		if (dense[mid].getId() < id) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	
}

template<>
inline void SparseSet<PlayList>::showp(int playlist_id)
{
	auto& playlist = dense[playlist_id];
	auto& music = playlist.getMusic();
	playlist.quickSort(music.GetHead(), music.GetTail());
	music.print();
}

template<typename T>
inline void SparseSet<T>::addqpid(int id)
{
	auto& playlist = dense[id];
	queue->push(playlist);

}

template<typename T>
inline void SparseSet<T>::pop()
{
	queue->pop();
}
