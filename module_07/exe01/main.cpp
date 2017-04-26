#include <iostream>
#include <functional>

int main()
{
	std::function<int(int)> f = [&f] (int v) {
		if (!v)
			return f(v - 1);
		return 0;
	};

    std::cout << "f(v): \t" << f(1) << std::endl;

    return 0;
}

