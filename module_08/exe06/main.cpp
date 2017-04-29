#include <iostream>
#include "unique_ptr.h"
#include "shared_ptr.h"
#include <string>

int main()
{
	unique_ptr<std::string> uptr(new std::string("Hello world"));
	//unique_ptr<std::string> uptr2(uptr);					// exception, copy not allowed
	//unique_ptr<std::string> uptr3 = uptr;				// exception, copy not allowed
	unique_ptr<std::string> uptr4(std::move(uptr)); 	// ptr2 gets empty
	unique_ptr<std::string> uptr5 = std::move(uptr4);	// ptr3 gets empty

	shared_ptr<std::string> ptr(new std::string("Hello world"));
	shared_ptr<std::string> ptr2(ptr);
	shared_ptr<std::string> ptr3 = ptr;
	shared_ptr<std::string> ptr4(std::move(ptr2)); 	// ptr2 gets empty
	shared_ptr<std::string> ptr5 = std::move(ptr3);	// ptr3 gets empty

    return 0;
}

