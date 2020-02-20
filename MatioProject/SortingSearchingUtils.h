#pragma once
#include <vector>
using namespace std;

typedef void (*sortfunc_t)(vector<int>&);
bool isSorted(vector<int> arr);