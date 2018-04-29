//P1424 小鱼的航程(改进版)
#include<iostream>

using namespace std;

int main() {
    long x, n;
    cin >> x >> n;

    long long swim_dist = 0;
    
    for (int i = x; i < x+n; i++) {
        if (i % 7 == 6 || i % 7 == 0) {
            swim_dist += 0;
        } else {
            swim_dist += 250;
        }
    }

    cout << swim_dist;
}