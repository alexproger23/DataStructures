#include <iostream>

int main() {
	int n = 0;
	int k = 0;
	std::cin >> n >> k;
	int mx = 0;
	int a = 0;
	for (int i = 0; i < n; i++) {
		std::cin >> a;
		if (k % a == 0)
			if (a > mx) mx = a;
	}
	std::cout << k/mx;
}
