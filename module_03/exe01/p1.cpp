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

void h(){
	Id* id = new Id("id");

	secret(id);

	std::cout << id->v_ << std::endl;
}

int main(){
	h();

	return 0;
}