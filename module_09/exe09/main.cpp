#include <iostream>
#include <array>

class ApiVersion {
public:
	static constexpr int major(){
		return 1;
	}
	static constexpr int minor(){
		return 2;

	}
	static constexpr int patch(){
		return 3;
	}
};

int main()
{
	std::array<int, ApiVersion::major()> major;
	std::array<int, ApiVersion::minor()> minor;
	std::array<int, ApiVersion::patch()> patch;

	std::cout << "Version (compile time): " 
		<< major.size() << "."
		<< minor.size() << "."
		<< patch.size() << std::endl;

	std::cout << "Version (run time): " 
		<< ApiVersion::major() << "."
		<< ApiVersion::minor() << "."
		<< ApiVersion::patch() << std::endl;

    return 0;
}



