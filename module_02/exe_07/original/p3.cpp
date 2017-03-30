#include <string>

#define MYCLASS(TYPE)			\
struct MyClass_##TYPE {			\
	MyClass_##TYPE(TYPE){}		\
	TYPE data_;					\
};								\

using namespace std;
MYCLASS(int)
// MYCLASS(string)
MYCLASS(double)

void h(){
	MyClass_int m(10);
	// MyClass_string n("foo");
	MyClass_double p(10.0);
}

int main(){
	h();
	return 0;
}
