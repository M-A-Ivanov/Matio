#pragma once
#include "Test.h"
#include "SortingSearchingUtils.h"

class SortingTest : public Test {

protected:
	SortingTest(string name, sortfunc_t func) : Test(name), func{ func } {}

	virtual void declare_test_cases() = 0;
	virtual bool run();

	vector<vector<int>> test_cases;
	sortfunc_t func;
};