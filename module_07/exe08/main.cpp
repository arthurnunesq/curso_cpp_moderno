#include <iostream>
#include <functional> 
#include "Ref.h"

void mutate(int a, int& b) { b = a; }

int main()
{
	int i = 1, j = 0;
	std::bind(mutate, std::placeholders::_1, std::ref(j)) (i);

	std::cout << "j = " << j << std::endl;

	i = 2;
	std::bind(mutate, std::placeholders::_1, ref(j)) (i);

	std::cout << "j = " << j << std::endl;

    return 0;
}

