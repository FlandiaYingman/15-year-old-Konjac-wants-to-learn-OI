//P1421 小玉买文具
#include<iostream>

using namespace std;
int main() {
    //a yuan, b jiao.
    //A pen priced 1 yuan 9 jiao.
    const int pen_price_jiao = 19;

    int a, b;
    cin >> a >> b;

    int money_jiao = (a * 10) + b;
    int pen_count = money_jiao / pen_price_jiao;

    cout << pen_count;
    return 0;
}