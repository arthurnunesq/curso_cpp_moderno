#include <string>
#include <iostream>

struct Id{
	Id(const char* c)
	:v_(c){}
	std::string v_;
};


void secret(Id* id){
	delete id;
}

void f(){
	static Id id("id");

	secret(&id);

	std::cout << id.v_ << std::endl;
}

int main(){
	f();

	return 0;
}