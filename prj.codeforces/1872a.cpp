#include <iostream>
#include <string>
#include <cmath>
 
int main() {
	int n = 0;
	std::cin >> n;
	int a, b, c = 0;
	for (int i = 0; i < n; i++) {
		std::cin >> a >> b >> c;
		std::cout << ceil(abs(a - b) / 2.0 / c) << std::endl;
	}
}
