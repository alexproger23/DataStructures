#include <iostream>
#include <algorithm>
#include <vector>

int main() {
	using namespace std;
	int t;
	int n, x, y;
	cin >> t;
	while (t--) {
		cin >> n >> x >> y;
		vector<int> a(n);
		int s = 0;
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
			s += a[i];
		}
		sort(a.begin(), a.end());
		int c = 0;
		for (int i = n - 1; i >= 0; i--) {
			int qx = s - a[i] - x;
			int qy = s - a[i] - y;
			auto ub = std::lower_bound(a.begin(), a.begin() + i + 1, qx);
			auto lb = std::lower_bound(a.begin(), a.begin() + i + 1, qy);
			if (qx == qy) auto lb = std::upper_bound(a.begin(), a.begin() + i + 1, qy);
			std::cout << std::distance(a.begin(), ub) << " " << *ub << std::endl;
			std::cout << std::distance(a.begin(), lb) << " " << *lb << std::endl;
			c += std::abs(std::distance(ub, lb));
			//if (i >= 1) {
			//	if (s - a[i] - a[i - 1] > y) break;
			//}
		}
		std::cout << c << std::endl;
	}
}