#include <iostream>
#include <vector>
#include <string>
 
 
int main() {
	std::string s;
	std::cin >> s;
	std::string sub;
	int c = std::count(s.begin(),s.end(), '/');
	int count = 0;
	std::vector<char> exes;
	exes.push_back(' ');
	for (auto a : s) {
		if (a == '>') {
			if (exes.back() == *--sub.end() && *(sub.end()-2) == '/') {
				count--;
				for (int i = 0; i < count; i++) std::cout << "  ";
				std::cout << sub + '>' << std::endl;
				sub = "";
				exes.pop_back();
			}
			else {
				for (int i = 0; i < count; i++) std::cout << "  ";
				std::cout << sub + '>' << std::endl;
				count += 1;
				exes.push_back(*--sub.end());
				sub = "";
			}
		} else sub += a;
	}
}
