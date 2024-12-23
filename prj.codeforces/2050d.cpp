#include <iostream>
#include <algorithm>
#include <string>
#include <list>

int main() {
	using namespace std;
	int t;
	string s;
	cin >> t;
	while (t--) {
		cin >> s;
		list<int> lst;
		for (int i = 0; i < s.size(); i++) {
			lst.push_back(int(s[i]) - 48);
		}
		list<int>::iterator st = lst.begin();
		while (st != lst.end()) {
			int m = *st;
			list<int>::iterator mn = st;
			list<int>::iterator ls = st;
			ls++;
			int i = 1;
			while (i < 9 && ls != lst.end()) {
				if (*ls - i > m) {
					m = *ls - i;
					mn = ls;
				}
				i += 1;
				//cout << *ls << " " << *st << endl;
				ls++;
			}
			if (mn != st) {
				lst.insert(st, m);
				//for (auto i : lst) cout << char(i + 48) << " ";
				//cout << *mn << " ";
				lst.erase(mn);
			}
			else st++;
			//st++;
			/*string ans = "";
			for (auto i : lst) ans += char(i + 48);
			cout << ans << endl;*/
		}

		string ans = "";
		for (auto i : lst) ans += char(i + 48);
		cout << ans << endl;
	}
}