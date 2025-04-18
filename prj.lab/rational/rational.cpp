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

void Rational::normalize_sign() {
	if (n < 0) {
		m = -m;
		n = -n;
	}
}

Rational::Rational(int a, int b) : m(a) {
	if (b == 0) throw std::exception("can't divide by zero");
	else n = b;
	normalize_sign();
	normalize();
}

Rational& Rational::operator+=(const Rational& rhs) {
	m = m * rhs.n + n * rhs.m;
	n *= rhs.n;
	normalize_sign();
	normalize();
	return *this;
}
Rational& Rational::operator+=(const int rhs) { return operator+=(Rational(rhs)); }

Rational& Rational::operator-=(const Rational& rhs) {
	m = m * rhs.n - n * rhs.m;
	n *= rhs.n;
	normalize_sign();
	normalize();
	return *this;
}
Rational& Rational::operator-=(const int rhs) { return operator-=(Rational(rhs)); }

Rational& Rational::operator*=(const Rational& rhs) {
	m *= rhs.m;
	n *= rhs.n;
	normalize_sign();
	normalize();
	return *this;
}
Rational& Rational::operator*=(const int rhs) { return operator*=(Rational(rhs)); }

Rational& Rational::operator/=(const Rational& rhs) {
	if (rhs.m == 0) throw std::exception("can't divide by zero");
	m *= rhs.n;
	n *= rhs.m;
	normalize_sign();
	normalize();
	return *this;
}
Rational& Rational::operator/=(const int rhs) { return operator/=(Rational(rhs)); }

Rational Rational::operator-() {
	return Rational(-m, n);
}


bool Rational::operator==(const Rational& rhs) const { return ((m == rhs.m) && (n == rhs.n)); }
bool Rational::operator==(const int rhs) const { return this->operator==(Rational(rhs)); }
bool Rational::operator<(const Rational& rhs) const { return (m*rhs.n < rhs.m*n); }
bool Rational::operator<(const int rhs) const { return this->operator<(Rational(rhs)); }


std::istream& Rational::readFrom(std::istream& istr) {
	char divch(0);
	int tempm = 0, tempn = 0;

	istr >> tempm >> divch >> tempn;
	if (istr.good() || istr.rdstate() == std::ios::eofbit) {
		if (divch == divchar) {
			*this = Rational(tempm, tempn);
			normalize_sign();
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

Rational operator+(Rational lh, const int rh) { return lh += rh; }
Rational operator+(const int lh, Rational rh) { return rh += lh; }
Rational operator-(Rational lh, const int rh) { return lh -= rh; }
Rational operator-(const int lh, Rational rh) { return rh -= lh; }
Rational operator*(Rational lh, const int rh) { return lh *= rh; }
Rational operator*(const int lh, Rational rh) { return rh *= lh; }
Rational operator/(Rational lh, const int rh) { return lh /= rh; }
Rational operator/(const int lh, Rational rh) { return rh /= lh; }


bool operator!=(const Rational& lhs, const Rational& rhs) { return !(lhs == rhs); }
bool operator>(const Rational& lhs, const Rational& rhs) { return !(lhs < rhs); }
bool operator<=(const Rational& lhs, const Rational& rhs) {	return (lhs < rhs || lhs == rhs); }
bool operator>=(const Rational& lhs, const Rational& rhs) { return (lhs > rhs || lhs == rhs); }

bool operator!=(const Rational& lhs, const int rhs) { return lhs != Rational(rhs); }
bool operator!=(const int lhs, const Rational& rhs) { return Rational(lhs) != rhs; }
bool operator>(const Rational& lhs, const int rhs) { return lhs > Rational(rhs); }
bool operator>(const int lhs, const Rational& rhs) { return Rational(lhs) > rhs; }
bool operator<=(const Rational& lhs, const int rhs) { return lhs <= Rational(rhs); }
bool operator<=(const int lhs, const Rational& rhs) { return Rational(lhs) <=  rhs; }
bool operator>=(const Rational& lhs, const int rhs) { return lhs >= Rational(rhs); }
bool operator>=(const int lhs, const Rational& rhs) { return Rational(lhs) >= rhs; }


std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs) {
	return rhs.writeTo(ostrm);
}
std::istream& operator>>(std::istream& istrm, Rational& rhs) {
	return rhs.readFrom(istrm);
}