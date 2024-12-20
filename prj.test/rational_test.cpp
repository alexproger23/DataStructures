#include <iostream>

#include <rational/rational.hpp>

int main() {
	Rational r(4, 6);
	int n;
	std::cin >> r;
	std::cout << -r << std::endl;
	Rational r2(-1, 3);
	std::cout << r2 << std::endl;
	bool b = Rational(1, 1) == Rational(1);
	try {
		Rational r(0, 0);
	}
	catch (std::exception) { std::cout << "Mistake catchen"; }
}