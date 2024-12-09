#include "PlayList.h"
int PlayList::GId = 0;
void PlayList::swap(Node<Music>* A, Node<Music>* B)
{
	int temp = A->getData().getYear();
	A->getData().getYear() = B->getData().getYear();
	B->getData().getYear() = temp;
}

Node<Music>* PlayList::partition(Node<Music>* low, Node<Music>* high)
{
	int pivot = high->getData().getYear();
	Node<Music>* i = low->getPrev();
	for (Node<Music>* j = low; j != high ; j = j->getNext()) {
		if (j->getData().getYear() <= pivot) {
			i = (i == nullptr) ? low : i->getNext();
			swap(i, j);
		}
	}
	i = (i == nullptr) ? low : i->getNext();
	swap(i, high);
	return i;
}

void PlayList::quickSort(Node<Music>* low, Node<Music>* high) {
	if (low != nullptr && high != nullptr && low != high && low != high->getNext()) {
		Node<Music>* pivot = partition(low, high);
		quickSort(low, pivot->getPrev());
		quickSort(pivot->getNext(), high);
	}
}


