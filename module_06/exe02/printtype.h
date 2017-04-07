// extern "C" not handled
#include <typeinfo>
#include <type_traits>
#include <string>
template<class...> struct Printtype;
template<> struct Printtype<> {
	std::string name() {
		return "";
	}
};
template<class T> struct Printtype<T> {
	std::string name(std::string append="") {
		return typeid(T).name()+append;
	}
};
template<class T1, class T2, class...U> struct Printtype<T1,T2,U...> {
	std::string name() {
		return Printtype<T1>().name()+","+Printtype<T2,U...>().name();
	}
};

#define BASIC_TYPE(X) \
template<> struct Printtype<X> { \
	std::string name(std::string append="") { \
		return std::string( #X )+append; \
	} \
}
BASIC_TYPE(void);
BASIC_TYPE(bool);
BASIC_TYPE(char);
BASIC_TYPE(signed char);
BASIC_TYPE(unsigned char);
BASIC_TYPE(short);
BASIC_TYPE(unsigned short);
BASIC_TYPE(int);
BASIC_TYPE(unsigned);
BASIC_TYPE(long);
BASIC_TYPE(unsigned long);
BASIC_TYPE(long long);
BASIC_TYPE(unsigned long long);
BASIC_TYPE(float);
BASIC_TYPE(double);
BASIC_TYPE(long double);
BASIC_TYPE(wchar_t);
BASIC_TYPE(char16_t);
BASIC_TYPE(char32_t);
#undef BASIC_TYPE

#define SUFFIX(X,Y) \
template<class T> struct Printtype<T X> { \
	std::string name(std::string append="") { \
		return Printtype<T>().name( Y +append); \
	} \
}
#define SUFFIX1(X) SUFFIX(X, #X )
#define SUFFIX2(X) SUFFIX(X, " " #X )

SUFFIX1(*);
SUFFIX1(&);
SUFFIX1(&&);
SUFFIX2(const);
SUFFIX2(volatile);
SUFFIX2(const volatile);
#undef SUFFIX
#undef SUFFIX1
#undef SUFFIX2

std::string eatspace(std::string s){
	if(!s.empty() && s[0]==' ') s.erase(0,1);
	return s;
}

template<class T,class...U> struct Printtype<T(U...)> {
	std::string name(std::string append="") {
		return Printtype<T>().name(
			(append.empty()?append:("("+eatspace(append)+")"))+
			"("+Printtype<U...>().name()+")");
	}
};

template<class T,class...U> struct Printtype<T(U...,...)> {
	std::string name(std::string append="") {
		std::string args=Printtype<U...>().name();
		if(!args.empty()) args+=",";
		args+="...";
		return Printtype<T>().name(
			(append.empty()?append:("("+eatspace(append)+")"))+
			"("+args+")");
	}
};

template<class T,class F> struct Printtype<T F::*> {
	std::string name(std::string append="") {
		return Printtype<T>().name(" "+
			Printtype<F>().name()+"::*"+append);
	}
};

namespace {
template<class U,bool=std::is_array<U>::value>
struct Print_from_array:Printtype<U>{};
template<class U> struct Print_from_array<U,true>{
	std::string name(std::string append="") {
		return Printtype<U>().name(append,true);
	}
};

template<class T>
struct Printarraytype {
	std::string name(std::string append,bool fromarray,std::string dim) {
		return Print_from_array<T>().name(
			((append.empty()||fromarray)?append:("("+eatspace(append)+")"))+
			"[" + dim + "]");
	}
};
}

template<class T>
struct Printtype<T[]> {
	std::string name(std::string append="",bool fromarray=false) {
		return Printarraytype<T>().name(append,fromarray,"");
	}
};

template<class T,int d>
struct Printtype<T[d]> {
	std::string name(std::string append="",bool fromarray=false) {
		return Printarraytype<T>().name(append,fromarray,std::to_string(d));
	}
};




