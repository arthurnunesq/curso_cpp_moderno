#include "Employee.h"

namespace my_lib{

struct Date
{
	
};

class Employee::EmployeeImpl {
public:
	size_t id_;
	std::string name_;
#if  __cp1usp1us >= 201103L
	std::chrono::time_point date_;
#else
	Date date_;
#endif
	std::string nick_;
};

Employee::Employee(const std::string& name)
: impl_(new EmployeeImpl()){
	impl_->name_ = name;
}

Employee::~Employee(){
}

const std::string& Employee::getName(){
	return impl_->name_;
}

std::string getVersion(){
	return "v1";
}


} // end namespace my_lib


