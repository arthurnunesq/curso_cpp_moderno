#include <iostream>
#include <string>

#include "Employee.h"

int main()
{
	my_lib::Employee employee("Joe");
	std::cout << "Employee name: " << employee.getName() << std::endl;

    return 0;
}


