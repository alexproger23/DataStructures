// Rational.h : ���������� ���� ��� ����������� ��������� ���������� ������
// ��� ���������� ����� ��� ����������� �������.

#ifndef RATIONAL_HPP
#define RATIONAL_HPP

#include <cmath>
#include <iostream>

class Rational {
private:
	int m = 0;
	int n = 1;
	static const char divchar{ '/' };

	void normalize();
	void normalize_sign();
public:
	Rational() = default;
	explicit Rational(const int a) noexcept : m(a) {}
	Rational(int a, int b);

	Rational(const Rational& rhs) = default;
	Rational& operator=(const Rational& rhs) = default;

	Rational& operator+=(const Rational& n);
	Rational& operator+=(const int rhs);
	Rational& operator-=(const Rational& n);
	Rational& operator-=(const int rhs);
	Rational& operator*=(const Rational& n);
	Rational& operator*=(const int rhs);
	Rational& operator/=(const Rational& n);
	Rational& operator/=(const int rhs);

	Rational operator-();

	bool operator==(const Rational& rhs) const;
	bool operator==(const int rhs) const;
	bool operator<(const Rational& rhs) const;
	bool operator<(const int rhs) const;

	std::istream& readFrom(std::istream& istr);
	std::ostream& writeTo(std::ostream& osrt) const;

	~Rational() = default;
};

Rational operator+(Rational lh, const Rational& rh);
Rational operator+(Rational lh, const int rh);
Rational operator+(const int lh, Rational rh);
Rational operator-(Rational lh, const Rational& rh);
Rational operator-(Rational lh, const int rh);
Rational operator-(const int lh, Rational rh);
Rational operator*(Rational lh, const Rational& rh);
Rational operator*(Rational lh, const int rh);
Rational operator*(const int lh, Rational rh);
Rational operator/(Rational lh, const Rational& rh);
Rational operator/(Rational lh, const int rh);
Rational operator/(const int lh, Rational rh);


bool operator!=(const Rational& lhs, const Rational& rhs);
bool operator!=(const Rational& lhs, const int rhs);
bool operator!=(const int lhs, const Rational& rhs);
bool operator>(const Rational& lhs, const Rational& rhs);
bool operator>(const Rational& lhs, const int rhs);
bool operator>(const int lhs, const Rational& rhs);
bool operator<=(const Rational& lhs, const Rational& rhs);
bool operator<=(const Rational& lhs, const int rhs);
bool operator<=(const int lhs, const Rational& rhs);
bool operator>=(const Rational& lhs, const Rational& rhs);
bool operator>=(const Rational& lhs, const int rhs);
bool operator>=(const int lhs, const Rational& rhs);


std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs);
std::istream& operator>>(std::istream& istrm, Rational& rhs);

#endif
