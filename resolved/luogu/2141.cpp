//P2141 珠心算测验
#include<iostream>
#include<algorithm>

using namespace std;

int main() {
    int c;
    cin >> c;
    int *arr = new int[c];
    for (int i = 0; i < c; i++) {
        cin >> arr[i];
    }

    int ans = 0;
    sort(arr, arr+c);

    for (int i = 2; i < c; i++) {
        bool flag = false;
        for (int s1 = 0; s1 < i; s1++) {
            for (int s2 = s1+1; s2 < i; s2++) {
                if (flag == true) {
                    break;
                }
                if (arr[s1] + arr[s2] == arr[i]) {
                    ans++;
                    flag = true;
                }
            }
        }
    }

    cout << ans;
}