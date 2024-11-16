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
	Complex(const double& real, const double& imag = 0.0) : re(real), im(imag) {}
	Complex(const Complex& comp) = default;
	Complex& operator=(const Complex& comp) = default;

	Complex& operator+=(const Complex& rhs);
	Complex& operator+=(const double& rhs);
	Complex& operator-=(const Complex& rhs);
	Complex& operator-=(const double& rhs);
	Complex& operator*=(const Complex& rhs);
	Complex& operator*=(const double& rhs);
	Complex& operator/=(const Complex& rhs);
	Complex& operator/=(const double& rhs);
	
	Complex operator-() const { return Complex(-re, -im); }

	bool operator==(const Complex& rhs) const;
	bool operator!=(const Complex& rhs) const;

	~Complex() {};
};

std::ostream& operator<<(std::ostream& ostr, const Complex& cmpl);
std::istream& operator>>(std::istream& ostr, Complex& cmpl);

Complex operator+(const Complex& lhs, const Complex& rhs);
Complex operator+(const Complex& lhs, const double& rhs);
Complex operator+(const double& lhs, const Complex& rhs);

Complex operator-(const Complex& lhs, const Complex& rhs);
Complex operator-(const double& lhs, const Complex& rhs);
Complex operator-(const Complex& lhs, const double& rhs);

Complex operator*(const Complex& lhs, const Complex& rhs);
Complex operator*(const double& lhs, const Complex& rhs);
Complex operator*(const Complex& lhs, const double& rhs);

Complex operator/(const Complex& lhs, const Complex& rhs);
Complex operator/(const double& lhs, const Complex& rhs);
Complex operator/(const Complex& lhs, const double& rhs);


#endif // !COMPLEX.HPP
