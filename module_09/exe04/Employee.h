#include <string>

namespace my_lib{

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

} // end namespace my_lib

