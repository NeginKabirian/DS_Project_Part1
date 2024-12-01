#include "Music.h"
int Music::GId = 0;

int Music::len(char* arr)
{
	/*int size = 0;
	while (arr[size] != '\0') {
		size++;
	}
	return size;*/
	return std::strlen(arr);
}
bool Music::strcomp(int i, int j)
{
	char* a = substr[SuffixArray[i]];
	char* b = substr[SuffixArray[j]];
	int k = 0;
	while (a[k] != '\0' && b[k] != '\0') {
		if (a[k] < b[k]) {
			return true;
		}
		else if (a[k] > b[k]) {
			return false;
		}
		k++;
	}
	return len(a) < len(b);
}
void Music::merge(int p, int q, int r)
{
	int n1 = (q - p) + 1;
	int n2 = r - q ;
	char** left = new char*[n1];
	char** right = new char*[n2];
	int* leftIndices = new int[n1];
	int* rightIndices = new int[n2];
	for (int i = 0; i < n1; ++i) {
		leftIndices[i] = SuffixArray[ p + i];
		left[i] = substr[p + i];
	}
	for (int i = 0; i < n2; ++i) {
		rightIndices[i] = SuffixArray[q + 1 + i];
		right[i] = substr[q + 1 + i];
	}
	int i = 0, j = 0 , k = p;
	while (i < n1 && j < n2) {
		if (strcmp(left[i],right[j]) < 0) {
			substr[k] = left[i];
		    SuffixArray[k] = leftIndices[i];
			i++;
		}
		else {
			SuffixArray[k] = rightIndices[j];
			substr[k] = right[j];
			j++;
		}
		k++;
	}
	while (i < n1) {
		substr[k] = left[i];
      SuffixArray[k] = leftIndices[i];
		i++;k++;
	}
	while (j < n2) {
		substr[k] = right[j];
		SuffixArray[k] = rightIndices[j];
		j++;
	}
	delete[] left;
	delete[] right;
	delete[] leftIndices;
	delete[] rightIndices;
}
void Music::mergeSort(int p, int r)
{
	if(p < r) {
		int q = p + (r - p) / 2;
		mergeSort(p, q);
		mergeSort(q + 1, r);
		merge(p, q, r);
	}
}
void Music::build_SuffixArray() {
	size_t bufferSize = lyrics.size() + 1;
	char* temp = new char[bufferSize];     
	strcpy_s(temp, bufferSize, lyrics.c_str());
	int size = len(temp);
	strcpy_s(temp, bufferSize, lyrics.c_str());
	substr = new char* [size+1];
	SuffixArray = new int[size];
	
	for (int i = 0; i < size; ++i) {
		substr[i] = temp + i;
		/*cout << substr[i];*/
		SuffixArray[i] = i;
	}
	substr[size] = nullptr;
	mergeSort(0, size - 1);
	/*for (int i = 0; i < size; ++i) {
		cout<<SuffixArray[i]<<endl;
		cout << substr[i];
	}*/
	cout << endl;
	delete[] temp;
}
//
//Music::~Music() {
//	delete[] SuffixArray;
//	delete[] substr;
//}
