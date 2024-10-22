#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <ostream>
#include <istream>

struct Complex {
	double re;
	double im;

	static const char leftBrace{ '{' };
	static const char separator{ ',' };
	static const char rightBrace{ '}' };

	Complex() : re(0.0), im(0.0) {}
	explicit Complex(const double& real);
	Complex(const double& real, const double& imag);

	Complex& operator+=(const Complex& rhs);
	Complex& operator+=(const double& rhs);
	Complex& operator-=(const Complex& rhs);
	Complex& operator-=(const double& rhs);
	Complex& operator*=(const Complex& rhs);
	Complex operator-() const { return Complex(-re, -im); }

	~Complex() {};
};

std::ostream& operator<<(std::ostream& ostr, const Complex& cmpl);
std::istream& operator>>(std::istream& ostr, Complex& cmpl);

Complex operator+(const Complex& lhs, const Complex& rhs);
Complex operator-(const Complex& lhs, const Complex& rhs);
Complex operator*(const Complex& lhs, const Complex& rhs);


#endif // !COMPLEX.HPP