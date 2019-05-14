#pragma once

namespace itertools {
	
	template <typename T>
	
	class _range
	{
		//range funcation
	private:
		T start;
		T stop;
	public:
		_range(T start, T stop) {
			this->start = start;
			this->stop = stop;
		}
		class iterator {
		private:
			T data;
		public:

			iterator(T start):data(start) {
			}
			// Note that the method is const as this operator does not
		// allow changing of the iterator.
		// Note that it returns T& as it allows to change what it points to.
		// A const_iterator class will return const T&
		// and the method will still be const
	
			const T& operator*() const {
				return data;
			}

			T* operator->() const {
				return &(data);
			}
			
		// ++i;
			iterator& operator++() {
				data++;
				return *this;
			}

			// i++;
			// Usually iterators are passed by value and not by const& as they are small.
			const iterator operator++(int) {
				iterator tmp = *this;
				++data;
				return tmp;
			}

			bool operator==(const iterator& rhs) const {
				return data == rhs.data;
			}

			bool operator!=(const iterator& rhs) const {
				return data != rhs.data;
			}
		};  // END OF CLASS ITERATOR

		_range::iterator begin() const{
			return _range::iterator{ start };
		}

		_range::iterator end() const{
			return _range::iterator{ stop };
		}
	};
	template <typename T>
	_range<T> range(T start, T stop) {
		return _range<T>(start, stop);
	}
};