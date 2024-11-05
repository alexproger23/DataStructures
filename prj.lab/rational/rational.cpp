// Rational.cpp: определяет точку входа для приложения.
//

#include "Rational.h"

Rational& Rational::operator+=(const Rational& rhs) {
	m = m * rhs.n + n * rhs.m;
	n *= rhs.n;
	return *this;
}
Rational& Rational::operator+=(const int rhs) { return operator+=(Rational(rhs)); }

Rational& Rational::operator-=(const Rational& rhs) {
	m = m * rhs.n - n * rhs.m;
	n *= rhs.n;
	return *this;
}
Rational& Rational::operator-=(const int rhs) { return operator-=(Rational(rhs)); }

Rational& Rational::operator*=(const Rational& rhs) {
	m *= rhs.m;
	n *= rhs.n;
	return *this;
}
Rational& Rational::operator*=(const int rhs) { return operator*=(Rational(rhs)); }

Rational& Rational::operator/=(const Rational& rhs) {
	m *= rhs.n;
	n *= rhs.m;
	return *this;
}
Rational& Rational::operator/=(const int rhs) { return operator/=(Rational(rhs)); }


bool Rational::operator==(const Rational& rhs) { return (m == rhs.m) && (n == rhs.n); }

bool Rational::operator!=(const Rational& rhs) { return (m != rhs.m) || (n != rhs.n); }

bool Rational::operator>(const Rational& rhs) { return (double(m) / n > double(rhs.m) / rhs.n); }

bool Rational::operator<(const Rational& rhs) { return (double(m) / n < double(rhs.m) / rhs.n); }



Rational operator+(Rational lh, const Rational& rh) { return lh += rh; }
Rational operator-(Rational lh, const Rational& rh) { return lh -= rh; }
Rational operator*(Rational lh, const Rational& rh) { return lh *= rh; }
Rational operator/(Rational lh, const Rational& rh) { return lh /= rh; }


inline std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs) {
	ostrm << double(rhs.m) / rhs.n;
	return ostrm;
}


inline std::istream& operator>>(std::istream& istrm, Rational& rhs) {
	char divchar(0);
	int m = 0, n = 0;
	
	istrm >> m >> divchar >> n;
	if (istrm.good()) {
		if (divchar == rhs.divchar) {
			rhs.m = m;
			rhs.n = n;
		}
		else istrm.setstate(std::ios_base::failbit);
	}
	return istrm;
}

int main() {
	Rational rt(0);
	Rational b(1, 4);

	std::cin >> rt;
	std::cout << b << " " << rt << std::endl;
	std::cout << b + rt;
}