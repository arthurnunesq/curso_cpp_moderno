#include <iostream>
#include <string>

class Type {
public:
	Type() {
		std::cout << "Type: Default constructor\n";
	}
	Type& operator=(Type&& t){
		std::cout << "Type: Transfer assignement\n";
		return *this;
	}
	Type(const Type&){
		std::cout << "Type: Copy constructor\n";
	}
};

int main()
{
	Type t1;
	Type t2(t1);
	Type t3(std::move(t1));
	Type t4;
	//t4= t1; 	// main.cpp:4:7: note: ‘Type& Type::operator=(const Type&)’ 
				// is implicitly declared as deleted because ‘Type’ declares 
				// a move constructor or move assignment operator
	Type t5; 
	t5 = std::move(t1);
	Type t6 = std::move(t1);	// Why does this call the copy constructor? 
								// Implicitly conversion

    return 0;
}

