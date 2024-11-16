#include <iostream>

#include <rational/rational.hpp>

int main() {
	Rational r(4, 6);
	int n;
	std::cout << r << std::endl;
	Rational r2(1, 3);
	r = r - r2;
	Rational r3(2, 4);
	std::cout << r3 << std::endl;
	std::cout << r << std::endl;
	try {
		Rational r(0, 0);
	}
	catch (std::exception) { std::cout << "Mistake catchen"; }
}