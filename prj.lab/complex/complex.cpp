#include <iostream>
#include "complex.hpp"

//Перегрузка операций вне структуры
std::ostream& operator<<(std::ostream& ostr, const Complex& cmpl) {
	ostr << cmpl.leftBrace << cmpl.re << cmpl.separator << cmpl.im << cmpl.rightBrace;
	return ostr;
}

std::istream& operator>>(std::istream& istr, Complex& cmpl) {
	char leftBrace(0);
	char separator(0);
	char rightBrace(0);
	double real(0.0);
	double imag(0.0);

	istr >> leftBrace >> real >> separator >> imag >> rightBrace;
	if (istr.good() || istr.rdstate() == std::ios::eofbit) {
		if (leftBrace == cmpl.leftBrace && separator == cmpl.separator && rightBrace == cmpl.rightBrace) {
			cmpl.re = real;
			cmpl.im = imag;
		}
		else istr.setstate(std::ios_base::failbit);
	}
	return istr;
}

Complex operator+(const Complex& lhs, const Complex& rhs) {
	return Complex(lhs).operator+=(rhs);
}

Complex operator+(const Complex& lhs, const double& rhs) {
	return lhs + Complex(rhs);
}
Complex operator+(const double& lhs, const Complex& rhs) {
	return Complex(lhs) + rhs;
}


Complex operator-(const Complex& lhs, const Complex& rhs) {
	return Complex(lhs) -= rhs;
}

Complex operator-(const double& lhs, const Complex& rhs) {
	return Complex(lhs) - rhs;
}
Complex operator-(const Complex& lhs, const double& rhs) {
	return lhs - Complex(rhs);
}

Complex operator*(const Complex& lhs, const Complex& rhs) {
	return Complex(lhs) *= rhs;
}

Complex operator*(const double& lhs, const Complex& rhs) {
	return Complex(lhs) * rhs;
}
Complex operator*(const Complex& lhs, const double& rhs) {
	return Complex(rhs) * lhs;
}

Complex operator/(const Complex& lhs, const Complex& rhs) {
	return Complex(lhs) /= rhs;
}
Complex operator/(const double& lhs, const Complex& rhs) {
	return Complex(lhs) / rhs;
}
Complex operator/(const Complex& lhs, const double& rhs) {
	return lhs / Complex(rhs);
}



//Определения методов
Complex& Complex::operator+=(const Complex& rhs) {
	re += rhs.re;
	im += rhs.im;

	return *this;
}

Complex& Complex::operator+=(const double& real) {
	return operator+=(Complex(real));
}

Complex& Complex::operator-=(const Complex& rhs) {
	return (*this).operator+=(-rhs);
}

Complex& Complex::operator-=(const double& rhs) {
	*this += -rhs;

	return *this;
}

Complex& Complex::operator*=(const Complex& rhs) {
	double tempre = re;
	re = re * rhs.re - im * rhs.im;
	im = im * rhs.re + tempre * rhs.im;

	return *this;
}

Complex& Complex::operator*=(const double& rhs) {
	*this *= Complex(rhs);
	return *this;
}

Complex& Complex::operator/=(const Complex& rhs) {
	if (pow(rhs.re, 2) + pow(rhs.im, 2) != 0) {
		double t = re;
		re = (re * rhs.re + im * rhs.im) / (pow(rhs.re, 2) + pow(rhs.im, 2));
		im = (im * rhs.re - t * rhs.im) / (pow(rhs.re, 2) + pow(rhs.im, 2));
	}
	else {
		std::cerr << "Error: dividing by 0. ";
		re = NAN;
		im = NAN;
	}
	return *this;
}

Complex& Complex::operator/=(const double& rhs) {
	*this /= Complex(rhs);
	return *this;
}

bool Complex::operator==(const Complex& rhs) const {
	return abs(re - rhs.re) < 2 * std::numeric_limits<double>::epsilon() && abs(im - rhs.im) < 2 * std::numeric_limits <double>::epsilon();
}

bool Complex::operator!=(const Complex& rhs) const {
	return !(*this == rhs);
}
