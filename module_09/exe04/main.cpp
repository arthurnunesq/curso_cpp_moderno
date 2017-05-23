#include <iostream>
#include <string>

#include "Employee.h"

int main()
{
	std::cout << "Lib version: " << my_lib::getVersion() << std::endl;

	my_lib::Employee employee("Joe");
	std::cout << "Employee name: " << employee.getName() << std::endl;

    return 0;
}

// Compile and test with v1
// g++ -c -Wall -Werror -fpic Employee.cpp
// g++ -shared -o libEmployee.so Employee.o
// g++ -L"/home/arthur/curso_cpp_moderno/module_09/exe04" -Wall -o main main.cpp -lEmployee
// export LD_LIBRARY_PATH=/home/arthur/curso_cpp_moderno/module_09/exe04:$LD_LIBRARY_PATH
// ./main

// Compile with v1 and test with v2
// g++ -c -Wall -Werror -fpic Employee.cpp
// g++ -shared -o libEmployee.so Employee.o
// g++ -L"/home/arthur/curso_cpp_moderno/module_09/exe04" -Wall -o main main.cpp -lEmployee
// g++ -c -Wall -Werror -fpic Employee_v2.cpp
// g++ -shared -o libEmployee.so Employee_v2.o
// export LD_LIBRARY_PATH=/home/arthur/curso_cpp_moderno/module_09/exe04:$LD_LIBRARY_PATH
// ./main

// Fonte:
// http://www.cprogramming.com/tutorial/shared-libraries-linux-gcc.html


