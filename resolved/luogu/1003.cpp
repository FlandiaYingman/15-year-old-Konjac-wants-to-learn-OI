//P1003 铺地毯
#include<iostream>

using namespace std;

struct carpet {
    int a, b, g, k;

    bool is_on(int x, int y) {
        return x >= a && y >= b && x <= a+g && y <= b+k;
    }    
};

int main() {
    carpet carpets[10001];
    int carpet_count;

    cin >> carpet_count;
    for (int i = 1; i <= carpet_count; i++) {
        int a, b, g, k;
        cin >> a >> b >> g >> k;
        carpet c = {a, b, g, k};
        carpets[i] = c;
    }

    int x, y;
    cin >> x >> y;
    for (int i = carpet_count; i >= 1; i--) {
        carpet c = carpets[i];
        if (c.is_on(x, y)) {
            cout << i;
            return 0;
        }
    }
    cout << -1;
    return 0;
}