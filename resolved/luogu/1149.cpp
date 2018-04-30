//P1149 火柴棒等式
#include<iostream>
#include<cmath>

using namespace std;

int used_matchstick_count(int num);

const int matchstick_num[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main() {
    int matchsick_count;
    cin >> matchsick_count;

    int equation_count = 0;

    if (matchsick_count <= 4) {
        cout << 0;
        return 0;
    }

    for (int i = 0; i <= 1000; i++) {
        for (int j = 0; j <= 1000; j++) {
            int k = i + j;
            if (used_matchstick_count(i) + used_matchstick_count(j) + used_matchstick_count(k) + 2 + 2 == matchsick_count) {
                equation_count++;
            }
        }
    }

    cout << equation_count;
}

int used_matchstick_count(int num) {
    if (num == 0) {
        return matchstick_num[0];
    }
    int result = 0;
    int digit = floor(log10(num)) + 1;
    for (int i = digit; i > 0; i--) {
        int digit_num = (num / (int) pow(10, i-1)) % 10;
        result += matchstick_num[digit_num];
    }
    return result;
}