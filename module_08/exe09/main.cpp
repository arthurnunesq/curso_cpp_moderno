#include <iostream>
#include <string>
#include <memory>
#include <map>
#include <vector>

// http://www.dreamincode.net/forums/topic/73544-how-to-determine-the-size-of-what-a-void-pointer-is-pointing-at/
// http://stackoverflow.com/questions/8186018/how-to-properly-replace-global-new-delete-operators

// int memory_usage = 0;
// std::map<void*, size_t> allocated_objects;

void* operator new (size_t n) {
	void* p = malloc(n);

	std::cout << "new: memory = " << n << std::endl;

	// The code below throws a segmentation fault due to stackoverflow. 
	// memory_usage += n;
	// allocated_objects[p] = n;
	// std::cout << "new: memory usage = " << memory_usage << std::endl;

	return p;
}

void operator delete(void* p) {
	free(p);

	std::cout << "delete" << std::endl;

	// memory_usage-=allocated_objects[p];
	// allocated_objects.erase(p);
	// std::cout << "delete: memory usage = " << memory_usage << std::endl;
}


struct A{
	int value1;
};

struct B{
	int value1;
	int value2;
};

struct C{
	int value1;
	int value2;
	int value3;
};


int main()
{
	A* a = new A();
	B* b = new B();
	C* c = new C();
	delete(a);
	delete(b);
	delete(c);

    return 0;
}

