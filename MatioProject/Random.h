#pragma once
#include <random>

template<typename T>
class Random {
	default_random_engine* generator;
	uniform_int_distribution<T>* distribution;

public:
	Random(T from, T to) {
		this->generator = new std::default_random_engine();
		this->distribution = new uniform_int_distribution<T>(from, to);
	}

	T get() {
		return (*distribution)(*generator);
	}
};