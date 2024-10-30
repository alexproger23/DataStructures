#include <iostream>
#include <string>
#include <vector>

int main() {
	int t = 0;
	std::cin >> t;
	while (t--) {
		std::string s = "";
		std::vector<int> tags(8);
		std::vector<std::string> strs(8);
		for (int i = 0; i < 8; i++) {
			std::cin >> s;
			strs[i] = s;
			tags[i] = count(s.begin(), s.end(), '#');
		}
		for (int i = 1; i < 7; i++)
			if (tags[i - 1] == 2 && tags[i + 1] == 2 && tags[i] == 1) 
				for (int j = 0; j < 8; j++) 
					if (strs[i][j] == '#') 
						std::cout << i + 1 << " " << j + 1 << std::endl;
	}
	return 0;
}
