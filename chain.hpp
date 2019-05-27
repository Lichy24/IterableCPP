#pragma once
/**
* chain bind two containers to one container
*	Example: chain(string("hel"),string("lo"))
*	Result: h,e,l,l,o
*/
namespace itertools {
	template <class T, class U>
	class _chain
	{
	private:
		const T& iterable1;
		const U& iterable2;
	public:
		_chain(const T& start, const U& stop) :iterable1{ start }, iterable2{ stop } {}
		
		//iterator for iterators
		template <typename IT1, typename IT2>
		class iterator {
		private:
			IT1 iterator1;
			IT2 iterator2;
			bool first;

		public:

			iterator(IT1 _iterator1, IT2 _iterator2) :iterator1{ _iterator1 }, iterator2{ _iterator2 }, first{ true }{
			}
			decltype(*iterator1) operator*() const {
				if (first)
					return *iterator1;
				return *iterator2;
			}
		// ++i;
			_chain::iterator<IT1,IT2>& operator++() {
				if (first)
					++iterator1;
				else
					++iterator2;
			return *this;
			}
			bool operator!=(iterator const &rhs){
				if (first && !(iterator1 != rhs.iterator1))
					first = false;
				if (first)
					return iterator1 != rhs.iterator1;
				return iterator2 != rhs.iterator2;

			}
		};  // END OF CLASS ITERATOR
		
		auto begin() const {
			return _chain::iterator<decltype(iterable1.begin()), decltype(iterable2.begin())>(iterable1.begin(), iterable2.begin());
		}

		auto end() const {
			return _chain::iterator<decltype(iterable1.end()), decltype(iterable2.end())>{iterable1.end(), iterable2.end()};
		}
	};
	template <typename T,typename U>
	_chain<T, U> chain(const T& start, const U& stop) {
		return _chain<T,U>(start,stop);
	}
};