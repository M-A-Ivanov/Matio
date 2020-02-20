#include "SortingTest.h"
#include "IOUtils.h"

bool SortingTest::run() {
	bool failed = false;

	declare_test_cases();
	for (auto arr : test_cases)
	{
		string local;
		local = printArray(arr);
		func(arr);
		if (!isSorted(arr)) {
			report << "Case: " << local << endl;
			report << "Result " << printArray(arr) << endl;
			failed = true;
		}
	}
	return !failed;
}