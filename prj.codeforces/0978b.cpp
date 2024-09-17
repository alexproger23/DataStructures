#include <iostream>
#include <string>
 
int main() {
	std::string s = "";
	int n = 0;
	std::cin >> n >> s;
	int k = 0;
	while (s.find("xxx") < s.size()) {
		s.erase(s.find("xxx"),1);
		k++;
	}
	std::cout << k;
}
