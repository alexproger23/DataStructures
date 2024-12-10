#include <iostream>

#include "complex/complex.hpp"

int main() {
	Complex c(0.1, 0.45);
	Complex b(0.1);
	b = c -= 0.2;
	b += c;
	Complex a = b * c;
	std::cout << b << " " << c << " " << a << " " << -a << std::endl;
	Complex g(10);
	std::cin >> g;
	if (std::cin.rdstate() == std::ios_base::goodbit) std::cout << "Correct input: " << g << std::endl;
	else std::cout << "Error input" << std::endl;
}