#include <iostream>
#include "Closure.h"

int main()
{
	int a = 0;

	auto closure = make_closure(a);
	auto ref_closure = make_closure(&a);

	a = 1;

	std::cout << "Closure = " << closure.value << std::endl;
	std::cout << "RefClosure = " << ref_closure.value << std::endl;

    return 0;
}

