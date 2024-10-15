#include <iostream>


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

int main() {
	Complex c(0.1, 0.45);
	Complex b;
	b = c -= 0.2;
	b += c;
	Complex a = b * c;
	std::cout << b << " " << c << " " << a << " " << -a << std::endl;
	Complex g;
	std::cin >> g;
	if (std::cin.rdstate() == std::ios_base::goodbit) std::cout << "Correct input: " << g << std::endl;
	else std::cout << "Error input" << std::endl;
}


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
	if (istr.good()) {
		if (leftBrace == cmpl.leftBrace && separator == cmpl.separator && rightBrace == cmpl.rightBrace) {
			cmpl.re = real;
			cmpl.im = imag;
		}
		else istr.setstate(std::ios_base::failbit);
	}
	return istr;
}

Complex operator+(const Complex& lhs, const Complex& rhs) {
	Complex cmpl;
	cmpl += lhs;
	cmpl += rhs;

	return cmpl;
}

Complex operator-(const Complex& lhs, const Complex& rhs) {
	Complex cmpl;
	cmpl -= lhs;
	cmpl -= rhs;

	return cmpl;
}

Complex operator*(const Complex& lhs, const Complex& rhs) {
	Complex cmpl(lhs);
	cmpl *= rhs;

	return cmpl;
}


//Определения конструкторов
Complex::Complex(const double& real) : re(real), im(0.0) {}
Complex::Complex(const double& real, const double& imag) : re(real), im(imag) {}


//Определения методов
Complex& Complex::operator+=(const Complex& rhs) {
	re += rhs.re;
	im += rhs.im;

	return *this;
}

Complex& Complex::operator+=(const double& real) {
	re += real;

	return *this;
}

Complex& Complex::operator-=(const Complex& rhs) {
	*this += -rhs;

	return *this;
}

Complex& Complex::operator-=(const double& rhs) {
	*this += -rhs;

	return *this;
}

Complex& Complex::operator*=(const Complex& rhs) {
	re = re * rhs.re - im * rhs.im;
	im = im * rhs.re + re * rhs.im;

	return *this;
}
