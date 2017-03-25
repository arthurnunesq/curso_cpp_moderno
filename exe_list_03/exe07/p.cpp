#include <string>
#include <iostream>

struct PersonPOD{
	const char* name_;
	size_t age_;
};

struct Person{
	Person(const std::string& name, size_t age=0)
	 : name_(name), age_(age){}
	std::string name_;
	size_t age_;
};

int main(){
	// PersonPOD a;
	// PersonPOD b();
	// PersonPOD c{};
	// Person d;
	// Person e("eu");
	// PersonPOD f("eu");
	// Person g{"eu"};
	// PersonPOD h{"eu"};
	// Person i("eu", 30);
	// Person j{"eu", 30};
	// PersonPOD k("eu", 30);
	PersonPOD l{"eu", 30};

	std::cout << "name_: " << l.name_ << std::endl ;
	std::cout << "age_: " << l.age_ << std::endl << std::endl;

}


