#include <iostream>
#include "smart_ptr.h"
#include <string>

int main()
{
	smart_ptr<std::string> ptr(new std::string("Hello world"));

    return 0;
}

