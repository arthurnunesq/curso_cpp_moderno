#include <iostream>
#include <functional> 

int main()
{
	// http://stackoverflow.com/questions/13799550/how-to-compose-functors-with-stl
	auto f = std::bind(std::plus<int>(), std::bind(std::multiplies<int>(), std::placeholders::_1, 10), 5);

    std::cout << "f(5): \t" << f(5) << std::endl;

    return 0;
}

