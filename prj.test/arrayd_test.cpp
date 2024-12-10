#include <iostream>

#include "arrayd/arrayd.h"

int main() {
	ArrayD a(3);
	for (int i = 0; i < a.Size(); i++) {
		a[i] = i;
	}
	ArrayD b = a;
	b[0] = 9;
	b.Insert(1,12.1);
	for (int i = 0; i < b.Size(); i++) {
		std::cout << b[i] << " ";
	}
	std::cout << std::endl;
	b.Insert(4, 321);
	for (int i = 0; i < b.Size(); i++) {
		std::cout << b[i] << " ";
	}
}