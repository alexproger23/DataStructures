#include <iostream>
#include <string>
 
int main() {
	std::string x = "";
	std::cin >> x;
	if (x.length() == 1) {
		std::cout << 0;
		return 0;
	}
	long long int s = 0;
	for (auto ch : x) s += int(ch)-48;
	int res = 1;
	while (std::to_string(s).length() > 1) {
		long long int news = 0;
		while (s > 0) {
			news += s % 10;
			s /= 10;
		}
		s = news;
		res++;
	}
	std::cout << res;
}
