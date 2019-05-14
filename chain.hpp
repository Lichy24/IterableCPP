#pragma once

namespace itertools {
	template <class T, class U>
	class _chain
	{
	private:
		T iterable1;
		U iterable2;
	public:
		_chain(T start, U stop) :iterable1{ start }, iterable2{ stop } {}
		/*
		//iterator for iterators
		template <typename IT1, typename IT2>
		class iterator {
		private:
			IT1 iter1;
			IT2 iter2;
			bool one_left;

		public:

			iterator(IT1 _iter1, IT2 _iter2) :iter1{ _iter1 }, iter2{ _iter2 }, one_left{ false } {
			}

			// Note that the method is const as this operator does not
		// allow changing of the iterator.
		// Note that it returns T& as it allows to change what it points to.
		// A const_iterator class will return const T&
		// and the method will still be const
			decltype (*iter1) operator*() const {
				if (one_left)
					return *iter2;
				return *iter1;
			}
		// ++i;
			_chain::iterator<IT1,IT2>& operator++() {
			/*
				if (one_left)
					iter2++;
				else
					iter1++;
			return *this;
			}

			// i++;
			// Usually iterators are passed by value and not by const& as they are small.
			const iterator<IT1,IT2> operator++(int) {
				iterator tmp = *this;
				if (one_left)
					++iter2;
				else
					++iter1;
				return tmp;
			}

			bool operator!=(_chain::iterator<IT1,IT2> const &rhs){
				return false;
				if (one_left && !(iter1 != rhs.iter1))
					one_left = true;
				if (one_left)
					return iter2 != rhs.iter2;
				return iter1 != rhs.iter1;

			}
		};  // END OF CLASS ITERATOR
		*/
		int* begin() const {
			return nullptr;
			//return iterator<decltype(iterable1.end()), decltype(iterable2.end())>(iterable1.begin(), iterable2.begin());
		}

		int* end() const {
			return nullptr;
			//return iterator<decltype(iterable1.end()), decltype(iterable2.end())>{iterable1.end(), iterable2.end()};
		}
	};
	template <typename T,typename U>
	_chain<T, U> chain(T start, U stop) {
		return _chain<T,U>(start,stop);
	}
};