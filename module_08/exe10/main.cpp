#include <iostream>
#include "MemoryPool.h"
#include <vector>

struct A{
	int value_ = 0;
	A(){}
	A(int value) : value_(value){

	}
	virtual ~A(){};
};

void* operator new (size_t n, MemoryPool<A>* pool) {
	std::cout << "new: custom memory pool."<< std::endl;
	void* p = pool->allocate(n);

	return p;
}

void operator delete (void* p, MemoryPool<A>* pool) {
	std::cout << "delete: custom memory pool."<< std::endl;
	pool->release(p);
}

MemoryPool<A> pool;

int main()
{
	std::vector<A*> instances;

	for (int i = 0; i < 10; i++){;
		instances.push_back(new (&pool) A(i));
		std::cout << "\tA.value = " << instances[i]->value_ << std::endl;
	}

	for (int i = 0; i < 10; i+=2){
		std::cout << "\tdeleting i = " << i << ", A = " << instances[i]->value_ << std::endl;
		operator delete(instances[i], &pool);
	}

	for (int i = 0; i < 10; i+=2){
		instances[i] = new (&pool) A(i+10);
		std::cout << "\tA.value = " << instances[i]->value_ << std::endl;
	}

	std::cout << "RESULT:" << std::endl;
	for (int i = 0; i < 10; i++){;
		std::cout << "\tA.value = " << instances[i]->value_ << std::endl;
	}

    return 0;
}

