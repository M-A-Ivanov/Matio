#include "IOUtils.h"
#include "List.h"
#include <sstream>

string printArray(vector<int> arr) {
	stringstream result;
	for (int x : arr) {
		result << x;
		result << ", ";
	}
	return result.str();
}

string printList(List& l) {
	stringstream result;
	for (int i = 0; i < l.size(); i++) {
		result << l.at(i);
		result << ", ";
	}
	return result.str();
}