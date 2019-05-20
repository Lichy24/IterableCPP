#pragma once
/**
*	range give starting number and ending number
*	the function will reach end with incremention of 1
*	Example: range(1,4)
*   Result: 1,2,3
*/
namespace itertools {
	
	template <typename T>
	
	class _range
	{
		//range funcation
	private:
		const T& start;
		const T& stop;
	public:
		_range(const T& _start,const T& _stop) :start{ _start }, stop{ _stop }{}
		class iterator {
		private:
			T data;
		public:

			iterator(T _data):data(_data) {
			}
			T operator*() const{
				return data;
			}

		// ++i;
			iterator& operator++() {
				++data;
				return *this;
			}

			bool operator!=(iterator const &rhs) const {
				return data != rhs.data;
			}
		};  // END OF CLASS ITERATOR

		iterator begin() const {
			return iterator{start};
		}

		iterator end() const{
			return iterator{ stop };
		}
	};
	template <typename T>
	_range<T> range(const T& start, const T& stop) {
		return _range<T>(start, stop);
	}
};