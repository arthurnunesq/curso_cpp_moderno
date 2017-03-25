#include <iostream>
#include "Entropy.h"

extern Entropy entropy;

struct RandNum
{
	RandNum(const Entropy* entropy){
		std::cout << "RandNum" << std::endl;
	}
};

RandNum randNum(&entropy);