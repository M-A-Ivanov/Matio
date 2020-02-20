#pragma once
#include <vector>
using namespace std;

// Type of values inserted in List - for now let's keep it an int
typedef int T;

class List {
public:
	typedef size_t size_type;

	/*
		All these functions must be implemented to have a functional List <3
	*/
	
	// Returns whether the list is currently empty()
	virtual bool empty() const = 0;

	// Returns the size of the list
	virtual size_type size() const = 0;

	// Returns the item at the front of the list
	virtual T front() const = 0;

	// Returns the item at the back of the list
	virtual T back() const = 0;

	/* 
	Returns the item at position pos
	The spooooky & after T means that whatever value this returns
		will be a reference, i.e. you can modify it (think pointer)
		Basically, you will be able to do List.at(pos) = 5
		and the list will change.
		It will never. Be. The. Same. Again.
	*/
	virtual T& at(size_type pos) = 0;
	
	// Fills the list with n copies of value n
	// Any previous values in the list are removed/overwritten
	virtual void assign(size_type n, T value) = 0;

	// Removes item at front of the list
	virtual void pop_front() = 0;

	// Adds item at front of the list
	virtual void push_front(T value) = 0;

	// Removes item at back of the list
	virtual void pop_back() = 0;

	// Adds item at back of the list
	virtual void push_back(T value) = 0;

	// Inserts the item at position pos
	virtual void insert(size_type pos, T value) = 0;

	// Clears list
	// List should be empty after call
	virtual void clear() = 0;

};


class DummyList : public List {
public:

	typedef size_t size_type;

	vector<T> v;

	DummyList() {}

	/*
		All these functions must be implemented to have a functional List <3
	*/

	// Returns whether the list is currently empty()
	virtual bool empty() const {
		return v.empty();
	}

	// Returns the size of the list
	virtual size_type size() const {
		return v.size();
	}

	// Returns the item at the front of the list
	virtual T front() const {
		return v.front();
	}

	// Returns the item at the back of the list
	virtual T back() const {
		return v.back();
	}

	/*
	Returns the item at position pos
	The spooooky & after T means that whatever value this returns
		will be a reference, i.e. you can modify it (think pointer)
		Basically, you will be able to do List.at(pos) = 5
		and the list will change.
		It will never. Be. The. Same. Again.
	*/
	virtual T& at(size_type pos) {
		return v[pos];
	}

	// Fills the list with n copies of value n
	// Any previous values in the list are removed/overwritten
	virtual void assign(size_type n, T value) {
		v.assign(n, value);
	}

	// Removes item at front of the list
	virtual void pop_front() {
		v.erase(v.begin());
	}

	// Adds item at front of the list
	virtual void push_front(T value) {
		v.insert(v.begin(), value);
	}

	// Removes item at back of the list
	virtual void pop_back() {
		v.pop_back();
	}

	// Adds item at back of the list
	virtual void push_back(T value) {
		v.push_back(value);
	}

	// Inserts the item at position pos
	virtual void insert(size_type pos, T value) {
		v.insert(v.begin() + pos, value);
	}

	// Clears list
	// List should be empty after call
	virtual void clear() {
		v.clear();
	}
};