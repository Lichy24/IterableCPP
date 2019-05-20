#pragma once
#include "IterStream.hpp"
/**
*	zip binding two variables in pair by the order of container variables.
*	Example: zip(string("hello"),string("olleh"))
*	Result: (h,o) (e,l) (l,l) (l,e) (o,h)
*/
namespace itertools {
template <typename T,typename U>
class _zip
{
private:
	const T& iterable1;
	const U& iterable2;
public:
	_zip(const T& _iterable1,const U& _iterable2) :iterable1{ _iterable1 }, iterable2{ _iterable2 } {
	}
	
	template <typename IT1,typename IT2>
	class iterator {
	private:
		IT1 iterator1;
		IT2 iterator2;
	public:

		iterator(IT1 _iterator1, IT2 _iterator2) :iterator1{ _iterator1 }, iterator2{ _iterator2 } {
		}
		pair<decltype(*iterator1),decltype(*iterator2)> operator*() const {
			return pair<decltype(*iterator1), decltype(*iterator2)>(*iterator1, *iterator2);
		}
		// ++i;
		iterator& operator++() {
			++iterator1;
			++iterator2;
			return *this;
		}
		bool operator!=(iterator const &rhs) const {
			return iterator1 != rhs.iterator1;
		}
	};  // END OF CLASS ITERATOR
	
	iterator<decltype(iterable1.begin()), decltype(iterable2.begin())> begin() const {
		return iterator<decltype(iterable1.begin()),decltype(iterable2.begin())>(iterable1.begin(),iterable2.begin());
	}

	iterator<decltype(iterable1.end()), decltype(iterable2.end())> end() const {
		return iterator<decltype(iterable1.end()), decltype(iterable2.end())>{iterable1.end(), iterable2.end()};
	}

};
template <typename T, typename U>
_zip<T, U> zip(const T& iterator1, const U& iterator2) {
	return _zip<T, U>(iterator1, iterator2);
}
};