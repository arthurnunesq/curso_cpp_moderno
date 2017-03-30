#include <string>

#define SETTER(NAME, TYPE) 	\
void set##NAME(TYPE p){		\
	NAME##_ = p;			\
}							\

template <typename T1, typename T2> 
struct Tuple { 
  T1 t1; 
  T2 t2; 
}; 

struct Cat{
	//SETTER(name, std::string)
	//std::string name_;

	SETTER(age, int);
	int age_;

	SETTER(property, Tuple<int, double>);
	Tuple<int, double> property_;
};

void f(){
	Cat cat;
	// cat.setname("garfield");
	cat.setage(1);
}

int main(){
	void f();
	return 0;
}