// Rational.h : включаемый файл для стандартных системных включаемых файлов
// или включаемые файлы для конкретного проекта.

#pragma once

#ifndef RATIONAL
#define RATIONAL

#include <iostream>

struct Rational {
	int m;
	int n;

	static const char divchar{ '/' };

	Rational() : m(0), n(1) {}
	Rational(int a) : m(a), n(1) {}
	Rational(int a, int b) : m(a), n(b) {}

	Rational& operator+=(const Rational& n);
	Rational& operator+=(const int n);
	Rational& operator-=(const Rational& n);
	Rational& operator-=(const int n);
	Rational& operator*=(const Rational& n);
	Rational& operator*=(const int n);
	Rational& operator/=(const Rational& n);
	Rational& operator/=(const int n);

	bool operator==(const Rational& n);
	bool operator!=(const Rational& n);
	bool operator>(const Rational& n);
	bool operator<(const Rational& n);
};

Rational operator+(Rational lh, const Rational& rh);
Rational operator-(Rational lh, const Rational& rh);
Rational operator*(Rational lh, const Rational& rh);
Rational operator/(Rational lh, const Rational& rh);

inline std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs);
inline std::istream& operator>>(std::istream& istrm, Rational& rhs);

#endif
