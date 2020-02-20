#pragma once
#include "SortingTest.h"
#include "InsertionSort.h"

class InsertionSortTest : public SortingTest {
public:
	InsertionSortTest() :
		SortingTest("InsertionSortTest", insertionSort) {}

	virtual void declare_test_cases() {
		test_cases.push_back({ 4589, 34, 7, 4, 6, 7, 4, 2, 2, 32, 6, 32, 1, 5 });
		test_cases.push_back({ -1235, 2, 3, -35, 2, 5, -6464, 3, 6, 500 });
		test_cases.push_back({ 0, 1, 0, 1, 0, 1, 0, 1, -1 });
	}
};

class InsertionSortIterationTest : public SortingTest {
public:
	InsertionSortIterationTest() :
		SortingTest("InsertionSortIterationTest", insertionSortIteration) {}

	virtual void declare_test_cases() {
		test_cases.push_back({ 9, 0, 1, 2, 3, 4, 5, 6, 7, 8 });
		test_cases.push_back({ 0, 0, 1, 4, 3, 3, 5, 6, 7, 8 });
		test_cases.push_back({ 0, 1, 2, 4, 4, 5, 6, 7, 8, 9 });
	}
};