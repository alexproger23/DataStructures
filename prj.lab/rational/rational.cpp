#include "rational.hpp"


void Rational::normalize() {
	int a = abs(m), b = abs(n);
	while (a != 0 && b != 0) {
		if (a > b) a %= b;
		else b %= a;
	}
	int gcd = std::max(a, b);
	m /= gcd;
	n /= gcd;
}

Rational::Rational(int a, int b) : m(a) {
	if (b == 0) throw std::exception("can't divide by zero");
	else n = b;
	if (n < 0) {
		n = -n;
		m = -m;
	}
	normalize();
}


Rational& Rational::operator+=(const Rational& rhs) {
	m = m * rhs.n + n * rhs.m;
	n *= rhs.n;
	normalize();
	return *this;
}
Rational& Rational::operator+=(const int rhs) { return operator+=(Rational(rhs)); }

Rational& Rational::operator-=(const Rational& rhs) {
	m = m * rhs.n - n * rhs.m;
	n *= rhs.n;
	normalize();
	return *this;
}
Rational& Rational::operator-=(const int rhs) { return operator-=(Rational(rhs)); }

Rational& Rational::operator*=(const Rational& rhs) {
	m *= rhs.m;
	n *= rhs.n;
	normalize();
	return *this;
}
Rational& Rational::operator*=(const int rhs) { return operator*=(Rational(rhs)); }

Rational& Rational::operator/=(const Rational& rhs) {
	if (rhs.m == 0) throw std::exception("can't divide by zero");
	m *= rhs.n;
	n *= rhs.m;
	normalize();
	return *this;
}
Rational& Rational::operator/=(const int rhs) { return operator/=(Rational(rhs)); }

Rational& Rational::operator-() {
	return Rational(-m, n);
}


bool Rational::operator==(const Rational& rhs) const { return ((m == rhs.m) && (n == rhs.n)); }
bool Rational::operator<(const Rational& rhs) const { return (m*rhs.n < rhs.m*n); }


std::istream& Rational::readFrom(std::istream& istr) {
	char divch(0);
	int tempm = 0, tempn = 0;

	istr >> tempm >> divch >> tempn;
	if (istr.good()) {
		if (divch == divchar) {
			*this = Rational(tempm, tempn);
			normalize();
		}
		else istr.setstate(std::ios_base::failbit);
	}
	return istr;
}

std::ostream& Rational::writeTo(std::ostream& ostr) const {
	ostr << m << divchar << n;
	return ostr;
}


Rational operator+(Rational lh, const Rational& rh) { return lh += rh; }
Rational operator-(Rational lh, const Rational& rh) { return lh -= rh; }
Rational operator*(Rational lh, const Rational& rh) { return lh *= rh; }
Rational operator/(Rational lh, const Rational& rh) { return lh /= rh; }

bool operator!=(const Rational& lhs, const Rational& rhs) { return !(lhs == rhs); }
bool operator>(const Rational& lhs, const Rational& rhs) { return !(lhs < rhs); }
bool operator<=(const Rational& lhs, const Rational& rhs) {	return (lhs < rhs || lhs == rhs); }
bool operator>=(const Rational& lhs, const Rational& rhs) { return (lhs > rhs || lhs == rhs); }


std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs) {
	return rhs.writeTo(ostrm);
}
std::istream& operator>>(std::istream& istrm, Rational& rhs) {
	return rhs.readFrom(istrm);
}