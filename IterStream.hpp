#pragma once
#include <utility>
#include <vector>
#include <iostream>
/**
* function to help us stream the results
* because pair and vector dont have default << stream
* we can control how it will display the values of incoming input
*/
namespace itertools {
	template <typename T, typename U>
	std::ostream& operator<<(std::ostream & os,const std::pair<T,U> &p) {
		os << p.first << "," << p.second;
		return os;
	}
	template <typename T>
	std::ostream& operator<<(std::ostream & os, const std::vector<T> &vec) {
		if (vec.empty())
		{
			os << "{" << "}";
			return os;
		}
		size_t i = 0;
		os << "{";
		while (i < vec.size() - 1) {
			os << vec[i] << ",";
			i++;
		}
		os << vec[i] << "}";
		return os;
	}
}