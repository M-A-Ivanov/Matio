#include "SortingSearchingUtils.h"

bool isSorted(vector<int> arr) {
	for (size_t i = 0; i < arr.size() - 1; i++) {
		if (arr[i] > arr[i + 1])
			return false;
	}
	return true;
}