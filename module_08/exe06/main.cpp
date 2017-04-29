#include <iostream>
#include "unique_ptr.h"
#include "shared_ptr.h"
#include <string>

int main()
{
	shared_ptr<std::string> ptr(new std::string("Hello world"));
	shared_ptr<std::string> ptr2 = ptr;

    return 0;
}

