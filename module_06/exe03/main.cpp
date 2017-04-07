#include <iostream>
#include "../exe02/printtype.h"

void conv(){
	auto a = 1U;
	auto b = 9;
	auto c = 3.14;
	auto d = &b;
	auto& e = d;
	auto &&f = 10;
	auto g = a + b;
	auto h = a + c;
	auto i = a + d;
	const auto j = f;
	auto& k = e;
	auto& l = f;


    std::cout << "a => " << Printtype<decltype(a)>().name() << std::endl;
    std::cout << "b => " << Printtype<decltype(b)>().name() << std::endl;
    std::cout << "c => " << Printtype<decltype(c)>().name() << std::endl;
    std::cout << "d => " << Printtype<decltype(d)>().name() << std::endl;
    std::cout << "e => " << Printtype<decltype(e)>().name() << std::endl;
    std::cout << "f => " << Printtype<decltype(f)>().name() << std::endl;
    std::cout << "g => " << Printtype<decltype(g)>().name() << std::endl;
    std::cout << "h => " << Printtype<decltype(h)>().name() << std::endl;
    std::cout << "i => " << Printtype<decltype(i)>().name() << std::endl;
    std::cout << "j => " << Printtype<decltype(j)>().name() << std::endl;
    std::cout << "k => " << Printtype<decltype(k)>().name() << std::endl;
    std::cout << "l => " << Printtype<decltype(l)>().name() << std::endl;
}

int main()
{
	conv();

    return 0;
}

