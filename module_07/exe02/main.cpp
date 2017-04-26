#include <iostream>
#include <vector>
#include <iterator>

void f() {
	auto r = []() -> std::vector<int> {
		int a = 10, b = 26, c = 20;
		return {a, b, c};
	}();

	std::copy(
		begin(r), end(r),
		std::ostream_iterator<int>(std::cout, " ")
	);
}

int main()
{
    f();

    return 0;
}



 

