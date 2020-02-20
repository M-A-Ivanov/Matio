#include "InsertionSort.h"
using namespace std;

void insertionSortIteration(vector<int>& arr) {
	int temp;
	for (int i = 0; i < arr.size() - 1; i++) {
		if (arr[i] > arr[i + 1]) {
			temp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = temp;
		};
	}
}

void insertionSort(vector<int>& arr)
{
	for (int i = 0; i < arr.size(); i++) {
		insertionSortIteration(arr);
	}
}