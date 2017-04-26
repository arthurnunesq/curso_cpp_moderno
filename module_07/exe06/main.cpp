#include <iostream>
#include <algorithm> 

int main()
{
	std::string s = "eiAiLjaOQl";
	std::sort(s.begin(), s.end(),
		[] (char c1, char c2) {
			return tolower(c1) < tolower(c2);
	});

    std::cout << "s: \t" << s << std::endl;

    return 0;
}

