#include <iostream>
#include <string>
 
int main() {
	int n, k = 0;
	std::cin >> n >> k;
	std::string s = "";
	std::string ans = "";
	std::cin >> s;
	if (s.size() == 1 && k > 0) {
		std::cout << 0;
		return 0;
	}
	for (int i = 0; i < n; i++) {
		if (i < k) {
			if ((i == 0 && s[i] == '1') || (i != 0 && s[i] == '0')) {
				k++;
				ans += s[i];
			}
			else {
				if (i == 0)	ans += '1';
				else ans += '0';
			}
		}
		else ans += s[i];
		if (ans.size() == n) break;
	}
	std::cout << ans;
}
