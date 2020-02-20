#include <string>
#include <iostream>
#include "Test.h"
using namespace std;


void Test::declare_result(bool ok) {
	if (ok) {
		cout << report.str();
		cout << "Test " << name << " passed";
	}
	else {
		cout << report.str();
		cout << "Test " << name << " failed" << endl;
	}
	cout << endl << endl;
}

void Test::execute() {
		cout << "Running test " << name << endl;
		declare_result(run());
}