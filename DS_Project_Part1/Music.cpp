#include "Music.h"
#include <algorithm>
int Music::GId = 0;


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

//void Music::RadixSort(Suffix*& suffixes, int n, int maxValue, int step) {
//	Suffix* temp = new Suffix[n];
//	int* start = new int[maxValue + 2](); 
//	for (int i = 0; i < n; ++i) {
//		start[suffixes[i].Rank[step] + 1]++; 
//	}
//	for (int i = 1; i <= maxValue + 1; ++i) {
//		start[i] += start[i - 1];
//	}
//	for (int i = n - 1; i >= 0; --i) {
//		int rankVal = suffixes[i].Rank[step] + 1; 
//		temp[start[rankVal] - 1] = suffixes[i];   //error
//		start[rankVal]--;
//	}
//	for (int i = 0; i < n; ++i) {
//		suffixes[i] = temp[i];
//	}
//
//	delete[] temp;
//	delete[] start;
//}
void Music::RadixSort(Suffix*& suffixes, int n, int maxValue, int step) {
	int minValue = 0; 
	for (int i = 0; i < n; ++i) {
		if (suffixes[i].Rank[step] < minValue) {
			minValue = suffixes[i].Rank[step];
		}
	}

	int offset = -minValue; 
	int range = maxValue + offset + 1;

	Suffix* temp = new Suffix[n];
	int* start = new int[range + 1]();

	
	for (int i = 0; i < n; ++i) {
		start[suffixes[i].Rank[step] + offset + 1]++;
	}
	
	for (int i = 1; i <= range; ++i) {
		start[i] += start[i - 1];
	}
	
	for (int i = n - 1; i >= 0; --i) {
		int rankVal = suffixes[i].Rank[step] + offset + 1;
		temp[start[rankVal] - 1] = suffixes[i];
		start[rankVal]--;
	}
	
	for (int i = 0; i < n; ++i) {
		suffixes[i] = temp[i];
	}

	delete[] temp;
	delete[] start;
}

int Music::cmp(Suffix a, Suffix b)
{
	if (a.Rank[0] == b.Rank[0]) {
		return a.Rank[1] < b.Rank[1];  
	}
	return a.Rank[0] < b.Rank[0];  
}
void Music::build_SuffixArray() {
	string str = lyrics;
	int len = mystring.len(str);
	Suffix* suffixes = new Suffix[len];

	for (int i = 0; i < len; ++i) {
		suffixes[i].index = i;
		suffixes[i].Rank[0] = str[i] - 'َa';
		suffixes[i].Rank[1] = (i + 1 < len) ? str[i + 1] - 'a' : -1;
	}

	RadixSort(suffixes, len, 256, 1);
	RadixSort(suffixes, len, 256, 0);

	/*sort(suffixes, suffixes + len, [this](Suffix a, Suffix b) {
		return cmp(a, b);
		});
	sort(suffixes, suffixes + len, [this](Suffix a, Suffix b) {
		return cmp(a, b);
		});*/
	int* index = new int[len];
	for (int k = 4; k < 2 * len; k *= 2) {
		int rank = 0;
		int prevRank = suffixes[0].Rank[0];
		suffixes[0].Rank[0] = rank;
		index[suffixes[0].index] = 0;

		for (int i = 1; i < len; ++i) {
			if (suffixes[i].Rank[0] == prevRank &&
				suffixes[i].Rank[1] == suffixes[i - 1].Rank[1]) {
				suffixes[i].Rank[0] = rank;
			}
			else {
				prevRank = suffixes[i].Rank[0];
				suffixes[i].Rank[0] = ++rank;
			}
			index[suffixes[i].index] = i;
		}

		for (int i = 0; i < len; ++i) {
			int nextIndex = suffixes[i].index + k / 2;
			suffixes[i].Rank[1] = (nextIndex < len) ? suffixes[index[nextIndex]].Rank[0] : -1;
		}

		RadixSort(suffixes, len, rank + 1, 1);
		RadixSort(suffixes, len, rank + 1, 0);
		/*sort(suffixes, suffixes + len, [this](Suffix a, Suffix b) {
			return cmp(a, b);  
			});
		sort(suffixes, suffixes + len, [this](Suffix a, Suffix b) {
			return cmp(a, b);  
			});*/
		
	}
	for (int i = 0; i < len; ++i) {
		SuffixArray[i] = suffixes[i].index;
	}
	for (int i = 0; i < len; ++i) {
		cout << SuffixArray[i] << " ";
	}

	delete[] suffixes;
	delete[] index;
}
int Music::search(const string& word)
{
	int start = 0;
	
	int end = mystring.len(lyrics) - 1; 
	while (start <= end) {
		int mid = start + (end - start) / 2;
		int index = SuffixArray[mid];
		string str = mystring.substr(lyrics, index, mystring.len(word));
		if (mystring.equal(str,word)) {  
			return index;
		}
		if (mystring.smaller(str, word)) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	return -1;
}

int Music::countw(const string& word)
{
	int start = 0;
	int end = mystring.len(lyrics);
	int count = 0;
	int len = mystring.len(word);
	while (start <= end) {
		int mid = start + (end - start) / 2;
		int index = SuffixArray[mid];
		string str = mystring.substr(lyrics, index, len);
		if (mystring.equal(str, word)) { 
			int left = mid - 1;
			int right = mid + 1;
			count++;
			while (left >= start) {
				index = SuffixArray[left];
				str = mystring.substr(lyrics, index, len);
				if (mystring.equal(str, word)) {
					count++;
					left--;
				}
				else {
					break;
				}
			}
			while (right <= end) {
				index = SuffixArray[left];
				str = mystring.substr(lyrics, index, len);
				if (mystring.equal(str, word)) {
					count++;
					right++;
				}
				else {
					break;
				}
			}
			if (mystring.smaller(str,word)) { 
				start = mid + 1;
			}
			else {
				end = mid - 1;
			}
		}
		return count;
	}
}
