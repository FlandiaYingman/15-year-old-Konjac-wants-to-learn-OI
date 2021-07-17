//P1909 买铅笔
#include<iostream>
#include<algorithm>
#include<cmath>

int money(int, int, int);

using namespace std;
int main() {
    int need_pencil;
    int a_count, a_price;
    int b_count, b_price;
    int c_count, c_price;

    cin >> need_pencil
        >> a_count >> a_price
        >> b_count >> b_price
        >> c_count >> c_price;
    
    int a_money = money(need_pencil, a_count, a_price);
    int b_money = money(need_pencil, b_count, b_price);
    int c_money = money(need_pencil, c_count, c_price);

    cout << min({a_money, b_money, c_money});
}

int money(int need, int count, int price) {
    return ceil((double) need / (double) count) * price;
}