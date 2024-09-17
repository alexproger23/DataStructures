#include <iostream>
#include <vector>
#include <set>
 
int main() {
	int n = 0;
	std::cin >> n;
	std::vector<int> nums(n);
	for (int i = 0; i < n; i++) std::cin >> nums[i];
	std::set<int> ex;
	std::vector<int> result;
	for (int i = nums.size() - 1; i >= 0; i--) {
		if (ex.find(nums[i]) == ex.end()) {
			result.push_back(nums[i]);
			ex.insert(nums[i]);
		}
	}
 
	std::reverse(result.begin(), result.end());
	std::cout << result.size() << std::endl;
	for (auto c : result) std::cout << c << " ";
}
