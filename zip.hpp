#pragma once
#include <utility>
namespace itertools {
template <typename T,typename U>
class _zip
{
private:
	T iterable1;
	U iterable2;
public:
	_zip(T _iterable1, U _iterable2) :iterable1{ _iterable1 }, iterable2{ _iterable2 } {
	}
	/*
	template <typename IT1,typename IT2>
	class iterator {
	private:
		IT1 iterator1;
		IT2 iterator2;
	public:

		iterator(IT1 _iterator1, IT2 _iterator2) :iterator1{ _iterator1 }, iterator2{ _iterator2 } {
		}
		// Note that the method is const as this operator does not
	// allow changing of the iterator.
	// Note that it returns T& as it allows to change what it points to.
	// A const_iterator class will return const T&
	// and the method will still be const
		decltype(*iterator1) operator*() const {
			return *iterator1;
		}
		// ++i;
		iterator& operator++() {
			iterator1++;
			iterator2++;
			return *this;
		}

		// i++;
		// Usually iterators are passed by value and not by const& as they are small.
		const iterator operator++(int) {
			iterator tmp = *this;
			++iterator1;
			++iterator2;
			return tmp;
		}

		bool operator!=(const iterator& rhs) const {
			return false;
			//return iterator1 != rhs.iterator1;
		}
	};  // END OF CLASS ITERATOR
	*/
	int* begin() const {
		return nullptr;
		//return iterator<decltype(iterable1.begin()),decltype(iterable2.begin())>(iterable1.begin(),iterable2.begin());
	}

	int* end() const {
		return nullptr;
		//return iterator<decltype(iterable1.end()), decltype(iterable2.end())>{iterable1.end(), iterable2.end()};
	}

};
template <typename T, typename U>
_zip<T, U> zip(T iterator1, U iterator2) {
	return _zip<T, U>(iterator1, iterator2);
}
};