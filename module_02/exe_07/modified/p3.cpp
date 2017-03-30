#include <string>

template<typename T>
struct MyClass {	
	MyClass(T){}
	T data_;					
};

using namespace std;
typedef MyClass<int> MyClass_int;
typedef MyClass<string> MyClass_string;

void h(){
	MyClass_int m(10);
	MyClass_string n("foo");
}

int main(){
	h();
	return 0;
}