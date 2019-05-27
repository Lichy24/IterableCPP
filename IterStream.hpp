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
	template <typename K>
	std::ostream& operator<<(std::ostream & os, const std::vector<K> &vec) {//overload vector output stream
		
		os << "{";
		auto iter = vec.begin();
		if (iter != vec.end()) {
			os << *iter;
			++iter;
		}
		while (iter!=vec.end())
		{
			os << "," << *iter;
			++iter;
		}
		os << "}";
		return os;
	}

	template <typename T, typename U>
	std::ostream& operator<<(std::ostream & os,const std::pair<T,U> &p) {//overload pair output stream
		os << p.first << "," << p.second;
		return os;
	}
}