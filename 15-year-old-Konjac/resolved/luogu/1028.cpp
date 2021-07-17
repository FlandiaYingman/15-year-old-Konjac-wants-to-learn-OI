//P1028 数的计算
#include<iostream>
#include<cmath>

using namespace std;

int main() {
    int num;
    cin >> num;
    
    int arr[1001];
    for (int i = 1; i <= num; i++) {
        arr[i] = 1;
        for (int j = 1; j <= i/2; j++) {
            arr[i] += arr[j];
        }
    }

    cout << arr[num];
}