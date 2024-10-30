#include <iostream>

int main() {
	int t = 0;
	std::cin >> t;
	while (t--) {
		int n = 0;
		std::cin >> n;
		int ai = 0;
		int mina = std::numeric_limits<int>::max();
		int prod = 1;
		int count0 = 0;
		for (int i = 0; i < n; i++) {
			std::cin >> ai;
			if (mina > ai) mina = ai;
			if (ai == 0) count0++;
			else prod *= ai;
		}
		if (count0 == 0) std::cout << (prod / mina) * (mina + 1);
		else if (count0 == 1) std::cout << prod;
		else std::cout << 0;
		std::cout << std::endl;
	}
}
