#include <string>
#include <vector>
#include <iostream>

struct Id{
	Id(const char* c)
	:v_(c){}
	std::string v_;
};


void secret(Id* id){
	delete id;
}

void g(){
	std::vector<Id> v (1, "id");
	Id& id = v.back();

	secret(&v[0]);

	std::cout << id.v_ << std::endl;
}

int main(){
	g();

	return 0;
}