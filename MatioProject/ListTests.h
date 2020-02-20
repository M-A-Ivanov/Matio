#pragma once

#include "Test.h"
#include "List.h"
#include "IOUtils.h"
#include "Random.h"
#include <vector>
#include <functional>
using namespace std;

template <class L>
class ListTest : public Test {
	Random<T>* r;

protected:
	ListTest(string name, string list_class):Test(name + " " + list_class){
		r = new Random<T>(-5000, 5000);
	}

	// Need to have List::at() implemented to use this
	static bool areEqual(List &l, vector<T> &v)
	{
		for (int i = 0; i < v.size(); i++) {
			if (v[i] != l.at(i))
				return false;
		}

		return true;
	}

	typedef std::function<void(L&, vector<T>&, int, Random<T>*)> Fill;
	typedef std::function<bool(L&, vector<T>&)> Check;

	bool testSkeleton(int iterations, int size, Fill fill_lambda, Check check_lambda) {
		bool result = true;

		for (int i = 0; i < iterations; i++) {

			L l = *(new L());
			vector<int> v;

			fill_lambda(l, v, size, r);
			bool res_i = check_lambda(l, v);
			if (!res_i) {
				report << "Case:   " << printArray(v) << endl;
				report << "Result: " << printList(l) << endl;
			}
			result &= res_i;

		}
		return result;
	}
	
	virtual bool run() = 0;
};

template <class L>
class InsertionTest : public ListTest<L> {
	typedef std::function<void(L&, vector<T>&, int, Random<T>*)> Fill;
	typedef std::function<bool(L&, vector<T>&)> Check;

public:
	InsertionTest(string list_class) :ListTest<L>("InsertionTest", list_class) {}

	virtual bool run() {
		auto ret = true;
		ListTest<L>::report << "Testing Push Front" << endl;
		ret &= testPushFront(100, 20);
		ListTest<L>::report << "Testing Push Back" << endl;
		ret &= testPushBack(100, 20);
		ListTest<L>::report << "Testing Assign" << endl;
		ret &= testAssign(100, 20);
		ListTest<L>::report << "Testing Insert" << endl;
		return ret;
	}

	bool testInsert(int iterations, int size) {

		Fill fill_lambda = [](auto& l, auto& v, int size, auto r) {
			v.assign(size, 0);
			l.assign(size, 0);
			for (int j = 0; j < size; j++) {
				auto k = r->get();
				v.insert(v.begin() + j, k);
				l.insert(j, k);
			}
		};

		return ListTest<L>::testSkeleton(iterations, size, fill_lambda, ListTest<L>::areEqual);
	}
	

	bool testAssign(int iterations, int size) {

		Fill fill_lambda = [](auto& l, auto &v, int size, auto* r) {
			auto n = r->get();
			v.assign(size, n);
			l.assign(size, n);
		};

		return ListTest<L>::testSkeleton(iterations, size, fill_lambda, ListTest<L>::areEqual);
	}

	bool testPushFront(int iterations, int size) {

		Fill fill_lambda = [](auto& l, auto& v,  int size, auto* r) {
			for (int j = 0; j < size; j++) {
				auto k = r->get();
				v.push_back(k);
				l.push_front(k);
			}
		};

		Check check_lambda = [](auto& l, auto& v) {
			auto size = v.size();
			auto res_i = true;
			for (int j = 0; j < size; j++) {
				res_i &= (v[size - 1 - j] == l.at(j));
			}
			return res_i;
		};

		return ListTest<L>::testSkeleton(iterations, size, fill_lambda, check_lambda);
	}

	bool testPushBack(int iterations, int size) {
		Fill fill_lambda = [](auto& l, auto&v, int size, auto* r) {
			for (int j = 0; j < size; j++) {
				auto k = r->get();
				v.push_back(k);
				l.push_back(k);
			}
		};

		return ListTest<L>::testSkeleton(iterations, size, fill_lambda, ListTest<L>::areEqual);
	}

};