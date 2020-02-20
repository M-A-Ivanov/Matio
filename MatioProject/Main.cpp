#include "ListTests.h"
#include "LinkedList.h"

void run_tests() {
	vector<Test*> tests;
	tests.push_back(new InsertionTest<DummyList>("Dummy List"));
	tests.push_back(new InsertionTest<LinkedList>("Matio's Linked List"));

	for (auto test : tests)
		test->execute();
}

int main() {
	run_tests();
	return 0;
}