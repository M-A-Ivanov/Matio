#pragma once

#include <string>
#include <sstream>
#include <iostream>

using namespace std;

typedef bool (*runfunc)();

class Test {
protected:
	Test(string name) :name{ name }, report{ "" }{}

	void declare_result(bool ok);
	virtual bool run() = 0;
	string name;
	stringstream report;

public:
	void execute();
}; 

class TestFunction : public Test {
public:
	TestFunction(string name, runfunc func): Test(name), func{func} {}

protected:
	virtual bool run()
	{
		return func();
	}

	runfunc func;
};