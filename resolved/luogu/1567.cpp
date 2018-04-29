//P1567 统计天数
#include<iostream>
#include<algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    int hist_max = -1;
    int curr_max = 1;
    int prev = 0;
    cin >> prev;
    
    for (int i = 1; i < n; i++) {
        int curr;
        cin >> curr;
        if (prev < curr) {
            prev = curr;
            curr_max++;
        } else {
            hist_max = max(hist_max, curr_max);
            prev = curr;
            curr_max = 1;
        }
    }

    cout << max(hist_max, curr_max);
    return 0;
}