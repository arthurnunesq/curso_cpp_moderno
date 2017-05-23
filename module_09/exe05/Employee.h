#include <string>
#include <memory>

namespace my_lib{

class Employee {
public:
	Employee(const std::string&);
	~Employee();
	const std::string& getName();

private:
	class EmployeeImpl;
	std::unique_ptr<EmployeeImpl> impl_;
};

std::string getVersion();

} // end namespace my_lib

