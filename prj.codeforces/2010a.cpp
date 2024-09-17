#include <iostream>
 
int main() {
	int n = 0;
	std::cin >> n;
	int t = 0;
	while (n--) {
		std::cin >> t;
		int a = 0;
		std::cin >> a;
		int res = a;
		for (int i = 1; i < t; i++) {
			std::cin >> a;
			res += i % 2 == 0 ? a : -a;
		}
		std::cout << res << std::endl;
	}
}
