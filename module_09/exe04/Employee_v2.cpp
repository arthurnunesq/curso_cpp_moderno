#include "Employee_v2.h"

namespace my_lib{

namespace my_lib_v1{	

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
	delete impl_;
}

const std::string& Employee::getName(){
	return impl_->name_;
}

std::string getVersion(){
	return "v1";
}

} // end namespace my_lib_v1

namespace my_lib_v2{	

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
	delete impl_;
}

const std::string& Employee::getName(){
	return impl_->name_;
}

std::string Employee::getNameWithPrefix(const std::string& prefix){
	return prefix + " " + impl_->name_;
}

std::string getVersion(){
	return "v2";
}

} // end namespace my_lib_v2


} // end namespace my_lib


