#pragma once

#include <iostream>
#include "List.h"

class Node {
public:
	Node(T elem) {
		next = NULL;
		element = elem;
	}

	T& get() {
		return element;
	}

	void set(T elem) {
		element = elem;
	}

	Node* next;

private:
	T element;
};

class LinkedList: public List {
public:

	LinkedList() {
		this->head = NULL;
	}

	// Returns whether the list is currently empty()
	virtual bool empty() const;

	// Returns the size of the list
	virtual size_type size() const;

	// Returns the item at the front of the list
	virtual T front() const;

	// Returns the item at the back of the list
	virtual T back() const;

	/*
	Returns the item at position pos
	The spooooky & after T means that whatever value this returns
		will be a reference, i.e. you can modify it (think pointer/array)
		Basically, you will be able to do List.at(pos) = 5
		and the list will change.
		It will never. Be. The. Same. Again.
	*/
	virtual T& at(size_type pos);

	// Fills the list with n copies of value n
	// Any previous values in the list are removed/overwritten
	virtual void assign(size_type n, T value);

	// Removes item at front of the list
	virtual void pop_front();

	// Adds item at front of the list
	virtual void push_front(T value);

	// Removes item at back of the list
	virtual void pop_back();

	// Adds item at back of the list
	virtual void push_back(T value);

	// Inserts the item at position pos
	virtual void insert(size_type pos, T value);

	// Clears list
	// List should be empty after call
	virtual void clear();


private:
	Node* head;
};