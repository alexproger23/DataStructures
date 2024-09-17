#include <iostream>
#include <string>
#include <set>
#include <cmath>
 
int main() {
    using namespace std;
    int y = 0;
    cin >> y;
    for (int i = y+1; ;i++) {
        int a1 = i%10;
        int a2 = (i%100 - a1)/10;
        int a3 = (i%1000 - i%100)/100;
        int a4 = i/1000;
        //cout<<a1<<" " << a2 << " " << a3 << " " << a4 << " ";
        if (a1 != a4 && a1 != a2 && a1 != a3 && a2 != a3 && a3 != a4 && a2 != a4) {
            cout << i;
            break;
        }
    }
}
