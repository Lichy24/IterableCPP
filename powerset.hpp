#pragma once
namespace itertools {

	template <typename T>
	class _powerset
	{
	private:
		T iterable1;
	public:
		_powerset(T _iterable1) :iterable1{_iterable1} {
		
		}
		/*
		//iterator
		template <typename IT>
		class iterator {
		private:
			IT iterator1;
		public:

			iterator(IT _iterator1) :iterator1{_iterator1} {
			}
			// Note that the method is const as this operator does not
		// allow changing of the iterator.
		// Note that it returns T& as it allows to change what it points to.
		// A const_iterator class will return const T&
		// and the method will still be const
			// ++i;
			decltype(*iterator1) operator*() const {
				return *iterator1;
			}
			iterator& operator++() {
				iterator1++;
				return *this;
			}

			bool operator==(const iterator& rhs) const {
				return iterator1 == rhs.iterator1;
			}

			bool operator!=(const iterator& rhs) const {
				return false;
			}
		};  // END OF CLASS ITERATOR
		*/
		int* begin() const {
			return nullptr;
			//return iterator<decltype(iterable1.begin())>(iterable1.begin());
		}

		int* end() const {
			return nullptr;
			//return iterator<decltype(iterable1.end())>(iterable1.end());
		}
	};
	template <typename T>
	_powerset<T> powerset(T iterator1) {
		return _powerset<T>(iterator1);
	}
};