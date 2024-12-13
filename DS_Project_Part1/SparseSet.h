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
	void searchpid(int id);
	void showp(int playlist_id);
	void addqpid(int id);
	void pop();
	int getSize();
	T*& getDense();

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
	if (id < 0 || size <= 0) {
		throw std::out_of_range("Invalid id for deletion.\n");
	}
	try {
		Singer& temp = dense[size - 1];
		dense[sparse[id]] = temp;
		sparse[temp.getId()] = sparse[id];
		sparse[id] = -1;
		size--;
	}
	catch (const std::exception& x) {
		cout << x.what();
	}
		
}

template<>
inline void SparseSet<Singer>::findId(int id)
{
	if (id < 0 || size <= 0) {
		throw std::out_of_range("Invalid id for searching.\n");
	}
	Singer& singer = dense[sparse[id]];
	singer.getMusic().print();
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
	/*for (int i = 0; i < size; ++i) {
		sparse[dense[i].getId()] = -1;
	}*/
	size = 0;
}

template<>
inline void SparseSet<PlayList>::addpname(const string& name)
{
	PlayList* p = new PlayList(name);
	if (size >= capacity) {
		cout << "Sparese is Full\n";
	}
	//search
	dense[size] = *p;
	if (p->getId() > maxValue) {
		throw std::out_of_range("Invalid id for deletion.\n");
		return;
	}
	sparse[p->getId()] = size++;
}
template<>
inline void SparseSet<Singer>::addms(const string music_name, int year, const string lyrics, int artist_id)  //handele lyrics input  //suffix array
{
	Music* music = new Music(music_name, year, lyrics);
	   //cout <<"id" << music->getId();
	if (artist_id < 0 || artist_id > maxValue|| sparse[dense[artist_id].getId()] == -1  || size <= 0) {
		throw std::out_of_range("Invalid artist_id.\n");
		return;
	}
	dense[artist_id].getMusic().push_front(*music);
}
template<>
inline void SparseSet<Singer>::findmname(const string music_name)  
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
			    temp->getData().print();
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
	if (artist_id < 0 || artist_id > maxValue || artist_id >= size || size <=0) {
		throw std::out_of_range("Invalid artist_id.");
		return;
	}
	
	
	//Singer& singer = dense[sparse[artist_id]]; //here

	int denseIndex = sparse[artist_id];
	if (denseIndex == -1) {
		throw std::out_of_range("Artist ID not found in sparse set.");
	}
	Singer& singer = dense[denseIndex];
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
		     }
			return;
		}
	temp = temp->getNext();
	}
	cout << "music_id Not Found";
}
template<>
inline int SparseSet<Singer>::countw(int artist_id, int music_id, const string& word)
{
	/*auto singer = dense[artist_id];*/
	int denseIndex = sparse[artist_id];
	if (denseIndex == -1) {
		throw std::out_of_range("Artist ID not found in sparse set.");
	}
	Singer& singer = dense[denseIndex];
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
	/*auto singer = dense[artist_id];*/
	int denseIndex = sparse[artist_id];
	if (denseIndex == -1) {
		throw std::out_of_range("Artist ID not found in sparse set.");
	}
	Singer& singer = dense[denseIndex];
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
	//auto&  playlist = dense[playlist_id];
	int denseIndex = sparse[playlist_id];
	if (denseIndex == -1) {
		throw std::out_of_range("Artist ID not found in sparse set.");
	}
	auto& playlist = dense[denseIndex];
	if (music_id < 0 || playlist_id < 0 || playlist_id > maxValue || playlist_id >= size || size <= 0) {  //error
		throw std::out_of_range("Invalid Id.\n");
	}
	auto& music = singer.searchmId(music_id);
	
	playlist.getMusic().push_front(music);
	
}
template<>
inline Music& SparseSet<PlayList>::searchm(int playlist_id, int music_id)
{
	//auto  playlist = dense[playlist_id];
	int denseIndex = sparse[playlist_id];
	if (denseIndex == -1) {
		throw std::out_of_range("Artist ID not found in sparse set.");
	}
	auto& playlist = dense[denseIndex];
	if (music_id < 0 || playlist_id < 0 || playlist_id > maxValue || playlist_id >= size || sparse[playlist.getId()] == -1 || size <=0) {
		throw std::out_of_range("Invalid Id.\n");
	}
	auto& temp = playlist.getMusic().GetHead();
	while (temp) {
		if (temp->getData().getId() == music_id) {
			temp->getData().print();
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
	//auto&  playlist = dense[playlist_id];
	int denseIndex = sparse[playlist_id];
	if (denseIndex == -1) {
		throw std::out_of_range("Artist ID not found in sparse set.");
	}
	auto& playlist = dense[denseIndex];
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
	//auto& playlist = dense[playlist_id];
	int denseIndex = sparse[playlist_id];
	if (denseIndex == -1) {
		throw std::out_of_range("Artist ID not found in sparse set.");
	}
	auto& playlist = dense[denseIndex];
	auto& music = playlist.getMusic();
	playlist.quickSort(music.GetHead(), music.GetTail());
	music.print();
}

template<typename T>
inline void SparseSet<T>::addqpid(int id)
{
	//auto& playlist = dense[id];
	int denseIndex = sparse[id];
	if (denseIndex == -1) {
		throw std::out_of_range("Artist ID not found in sparse set.");
	}
	auto& playlist = dense[denseIndex];
	queue->push(playlist);

}

template<typename T>
inline void SparseSet<T>::pop()
{
	queue->pop();
}
