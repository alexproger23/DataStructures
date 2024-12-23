#include <iostream>
#include <algorithm>
#include <vector>
#include <set>


int main() {
	using namespace std;
	int t;
	int n, m, k;
	int h;


	cin >> t;
	while (t--) {
		cin >> n >> m >> k;
		vector<int> a(m);
		set<int> q;
		for (int i = 0; i < m; i++) cin >> a[i];
		for (int i = 0; i < k; i++) {
			cin >> h;
			q.insert(h);
		}
		if (k < n - 1) for (int i = 0; i < m; i++) std::cout << '0';
		else if (k == n) for (int i = 0; i < m; i++) std::cout << '1';
		else for (auto i : a) {
			if (q.find(i) == q.end()) cout << '1';
			else cout << '0';
		}
		std::cout << std::endl;
	}
}