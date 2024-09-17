#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
 
int len(int v) {
    int l = 0;    
    while (v > 0) {
        v /= 10;
        l++;
    }
    return l;
}
 
int main() {
    int n = 0;
    int x;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> x;
        std::vector<int> nums;
        int a = 0;
        int l = len(x);
        for (int j = 0; j < l; j++) {
            a = x%10;
            if (a != 0) nums.push_back(a*pow(10,j));
            x /= 10;
        }
        std::cout << nums.size() << std::endl;
        std::reverse(nums.begin(),nums.end());
        for (auto c : nums) std::cout << c << " ";
    }
}
