#ifndef MEMORY_POOL_H
#define MEMORY_POOL_H

#include <vector>
#include <new> 
#include <iterator>
#include <iostream>

template <class T>
class MemoryPool
{
private:
	static constexpr size_t POOL_SIZE = 1000;
	std::vector<size_t> freed_;
	size_t next_ = 0;
	T pool_[POOL_SIZE];

public:
	MemoryPool(){}
	virtual ~MemoryPool(){}

	void* allocate(size_t){
		int index = 0;

		if(freed_.empty()){

			if(next_ >= POOL_SIZE){
				throw std::bad_alloc();
			}

			index = next_++;

			std::cout << "MemoryPool.allocate: using new memory." << std::endl;

		} else{

			// http://stackoverflow.com/questions/12600330/pop-back-return-value
			index = freed_.back();
			freed_.pop_back();
			
			std::cout << "MemoryPool.allocate: using freed memory." << std::endl;

		}

		std::cout << "MemoryPool.allocate: index = " << index << std::endl;

		void* p = &pool_[index];
		return p;

	}

	void release(void* p){
		freed_.push_back( std::distance(pool_, (T*)p));
	}
};




#endif // MEMORY_POOL_H

