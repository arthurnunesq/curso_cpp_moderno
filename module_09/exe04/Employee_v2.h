#include <string>

namespace my_lib{

namespace my_lib_v1{	

class Employee {
public:
	Employee(const std::string&);
	~Employee();
	const std::string& getName();

private:
	class EmployeeImpl;
	EmployeeImpl* impl_;
};

std::string getVersion();
 
} // end namespace my_lib_v1

inline namespace my_lib_v2{	

class Employee {
public:
	Employee(const std::string&);
	~Employee();
	const std::string& getName();
	std::string getNameWithPrefix(const std::string& prefix);

private:
	class EmployeeImpl;
	EmployeeImpl* impl_;
};

std::string getVersion();

} // end namespace my_lib_v2

} // end namespace my_lib

