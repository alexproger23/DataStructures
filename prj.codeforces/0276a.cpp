#include <iostream>
 
int main() {
    int n,k = 0;
    int f,t = 0;
    int m = -1000000000;
    std::cin >> n >> k;
    for (int i = 0; i < n; i++) {
        std::cin >> f >> t;
        int ples = t > k ? f - t + k : f;
        if (m < ples) m = ples;
    }
    std::cout << m;
}
