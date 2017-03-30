#include <string>
#include <cstring>

void extendTemporary(){
	std::string a, b;
	std::string& s = a + b;
	std::strlen(s.c_str());
}

int main(){
	extendTemporary();

	return 0;
}