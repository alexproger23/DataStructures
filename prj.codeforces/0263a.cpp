#include <iostream>
 
int main() {
    using namespace std;
    int x = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> x;
            if (x == 1) {
                cout << abs(i-2) + abs(j-2);    
            }
        }
    }
}
