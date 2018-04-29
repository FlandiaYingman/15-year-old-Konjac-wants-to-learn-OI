//P1035 级数求和
#include<iostream>

using namespace std;
int main() {
    int k;
    cin >> k;
    
    double h = 0.0;
    for (int i = 1; true; i++) {
        h += 1.0 / i;
        if (k < h) {
            cout << i;
            return 0;
        }
    }
    return 0;
}