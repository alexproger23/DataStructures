// Rational.h : включаемый файл для стандартных системных включаемых файлов
// или включаемые файлы для конкретного проекта.

#ifndef RATIONAL_HPP
#define RATIONAL_HPP

#include <cmath>
#include <iostream>

class Rational {
private:
	int m;
	int n;
	static const char divchar{ '/' };

	void normalize();
	void normalize_sign();
public:
	Rational() : m(0), n(1) {}
	explicit Rational(int a, int b = 1);
	Rational(const Rational& rhs) = default;
	Rational& operator=(const Rational& rhs) = default;

	Rational& operator+=(const Rational& n);
	Rational& operator+=(const int n);
	Rational& operator-=(const Rational& n);
	Rational& operator-=(const int n);
	Rational& operator*=(const Rational& n);
	Rational& operator*=(const int n);
	Rational& operator/=(const Rational& n);
	Rational& operator/=(const int n);

	Rational operator-();

	bool operator==(const Rational& n) const;
	bool operator<(const Rational& n) const;

	std::istream& readFrom(std::istream& istr);
	std::ostream& writeTo(std::ostream& osrt) const;

	~Rational() = default;
};

Rational operator+(Rational lh, const Rational& rh);
Rational operator-(Rational lh, const Rational& rh);
Rational operator*(Rational lh, const Rational& rh);
Rational operator/(Rational lh, const Rational& rh);
bool operator!=(const Rational& lhs, const Rational& rhs);
bool operator>(const Rational& lhs, const Rational& rhs);
bool operator<=(const Rational& lhs, const Rational& rhs);
bool operator>=(const Rational& lhs, const Rational& rhs);


std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs);
std::istream& operator>>(std::istream& istrm, Rational& rhs);

#endif
