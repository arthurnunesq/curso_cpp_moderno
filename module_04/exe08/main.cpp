#include <iostream>
#include <string>

struct Complex{
    double imaginary_ = 0.0;
    double real_ = 0.0;

    constexpr Complex(double real, double imaginary)
        : real_(real), imaginary_(imaginary){ }
};

constexpr Complex operator"" _i(long double value){
    return Complex(0, value);
}

std::ostream& operator<<(std::ostream& stream,
                     const Complex& complex) {
    stream << "(" << complex.real_ << ", " << complex.imaginary_ << "i)";
    return stream;
 }

Complex operator+(const Complex& a, const Complex& b)
{
    return Complex(a.real_ + b.real_, a.imaginary_ + b.imaginary_);
}

int main()
{
    Complex a(1.0, 0.0);
    Complex b = 1.0_i;
    Complex c = a+b;

    std::cout << "a =  " << a << "\nb = " << b << "\nc = " << c << "\n";

    return 0;
}

