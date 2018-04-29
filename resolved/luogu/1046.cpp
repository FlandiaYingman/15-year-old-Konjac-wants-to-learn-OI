//P1046 陶陶摘苹果
#include<iostream>

using namespace std;

int main() {
    int apples[10];
    int height;

    for (int i = 0; i < 10; i++) {
        cin >> apples[i];
    }
    cin >> height;
    height += 30;

    int available = 0;
    for (int i = 0; i < 10; i++) {
        if (apples[i] <= height) {
            available++;
        }
    }

    cout << available;
    return 0;
}