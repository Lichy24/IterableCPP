#pragma once
#include "IterStream.hpp"
/**
* product(Cartesian product) from given container
*	is a mathematical operation that returns a set (or product set or simply product) from multiple sets.
*   That is, for sets A and B, the Cartesian product A ª B is the set of all ordered pairs (a, b) where a belongs to A and b belongs to B.
*   Example: (a,b)x(c,d)
*   result (a,c) (a,d) (b,c) (b,d)
*/
namespace itertools {

	template <class T, class U>
	class _product
	{
	private:
		const T& iterable1;
	    const U& iterable2;
	public:
		_product(const T& _iterable1,const U& _iterable2) :iterable1{ _iterable1 }, iterable2{_iterable2} {
		}
		//iterator
		template <typename IT1,typename IT2>
		class iterator {
		private:
			IT1 iterator1;
			IT2 iterator2;

			IT2 start_over;
			bool isEmptyIt2;
		public:
			iterator(IT1 _iterator1, IT2 _iterator2) :iterator1{ _iterator1 }, iterator2{ _iterator2 }, start_over{ _iterator2 }, isEmptyIt2{true} {}

			std::pair<decltype(*iterator1), decltype(*iterator2)> operator*() const {
				return std::pair<decltype(*iterator1), decltype(*iterator2)>(*iterator1, *iterator2);
			}
			
			_product::iterator<IT1,IT2>& operator++() {
				++iterator2;
				return *this;
			}

			bool operator!=(iterator const &rhs){
				if (isEmptyIt2)
				{
					if (!(iterator2!=rhs.iterator2))
					{
						return false;
					}
					isEmptyIt2 = false;
				}
				if (iterator1 != rhs.iterator1 && !(iterator2 != rhs.iterator2))
				{
					iterator2 = start_over;
					++iterator1;
				}
				return iterator1 != rhs.iterator1;
			}
		};  // END OF CLASS ITERATOR
		auto begin() const{
			return _product::iterator<decltype(iterable1.begin()), decltype(iterable2.begin())>(iterable1.begin(), iterable2.begin());
		}

		auto end() const{
			return _product::iterator<decltype(iterable1.end()), decltype(iterable2.end())>(iterable1.end(),iterable2.end());
		}
	};
	template <typename T, typename U>
	_product<T, U> product(const T& iterator1,const U& iterator2) {
		return _product<T, U>(iterator1, iterator2);
	}
};