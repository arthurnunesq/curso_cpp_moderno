#include <iostream>
#include "../exe02/printtype.h"

struct B{};
struct D : B {};

auto infer(
	int n, 
	B* b, 
	D* d
) -> decltype(b)
{
	if(n % 2 == 0)
		return b;
	return d;
}

int main()
{
	B b;
	D d;

	infer(0, &b, &d);

    return 0;
}

