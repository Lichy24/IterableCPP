#pragma once
#include "IterStream.hpp"
#include <math.h>
/**
* powerset order by binary
* for example "abc" -> {} = 000,{a} = 001,..
* and so on...
*/
namespace itertools {

	template <class T>
	class _powerset
	{
	private:
		T iterable1;
	public:
		_powerset(T _iterable1) :iterable1{_iterable1} {
		
		}
		//iterator
		template <typename U>
		class iterator {
		private:
			U start;
			U stop;
			unsigned int power_size;
			unsigned int index;
		public:

			iterator(U _start, U _stop) :start{ _start }, stop{ _stop },power_size{ 0 }, index{ 0 }{
				U temp_start = start;
					while (temp_start != stop)
					{
						++power_size;
						++temp_start;
					}
					power_size = pow(2, power_size);
			}
			auto operator*() const {
				std::vector<typename std::remove_const<typename std::remove_reference<decltype(*start)>::type>::type> ith;// start
				U temp_start = start;// begin point for variables
				unsigned int i = index;//index point for powerset
				while (i != 0 && temp_start != stop) {//if index is zero stop becaues it while finsh or index number was zero
					unsigned int currentBit = i % 2;// take lsb(less significant bit) check if its 1 or 0
					i  = i >> 1;// shift left or divide by 2 inorder to remove lsb from current index number 
					if (currentBit == 1)//if bit is 1 then insert current variable in to set
						ith.emplace_back(*temp_start);
					++temp_start;//move forward for each bit
				}
				
				return ith;//return set
			}
			_powerset::iterator<U>& operator++() {
				++index;//move powerset index forward
				return *this;
			}

			bool operator!=(const iterator& rhs){
				return index != rhs.power_size;//stop when index reach power_size
			}
		};  // END OF CLASS ITERATOR
		
		auto begin() const {
			return _powerset::iterator<decltype(iterable1.begin())>(iterable1.begin(), iterable1.end());
		}

		auto end() const {
			return _powerset::iterator<decltype(iterable1.end())>(iterable1.begin(), iterable1.end());
		}
	};
	template <typename T>
	_powerset<T> powerset(T iterator1) {
		return _powerset<T>(iterator1);
	}
};