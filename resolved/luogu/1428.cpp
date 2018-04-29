//P1428 小鱼比可爱
#include<iostream>

using namespace std;

int main() {
    int cute[100] = {0};
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int ans = 0;
        int cur_cute;

        cin >> cur_cute;
        for (int j = 0; j < cur_cute; j++) {
            ans += cute[j];
        }

        cute[cur_cute]++;
        cout << ans << " ";
    }
}