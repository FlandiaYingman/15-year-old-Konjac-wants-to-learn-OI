//P1089 津津的储蓄计划
#include<iostream>

using namespace std;
int main() {
    int available_money = 0;
    int saved_money = 0;
    int is_break = 0;
    for (int i = 1; i <= 12; i++) {
        int expect;
        cin >> expect;
        available_money += 300;
        if (available_money < expect) {
            is_break = -i;
        } else {
            available_money -= expect;
            if ((available_money / 100) > 0) {
                saved_money += (available_money / 100) * 100;
                available_money = available_money % 100;
            } 
        }
    }
    if (is_break < 0) {
        cout << is_break;
    } else {
        cout << saved_money * 1.2 + available_money;
    }
    return 0;
}