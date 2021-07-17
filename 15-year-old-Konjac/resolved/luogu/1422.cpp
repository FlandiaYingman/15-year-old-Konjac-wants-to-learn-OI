//P1422 小玉家的电费
#include<iostream>
#include<stdio.h>

using namespace std;
int main() {
    const double price_less_equal_150 = 0.4463;
    const double price_151_to_400 = 0.4663;
    const double price_more_equal_401 = 0.5663;

    int used;
    double price = 0.0;
    cin >> used;
    
    if (used <= 150) {
        price += used * price_less_equal_150;
    } else if (used > 150 && used <= 400) {
        price += 150 * price_less_equal_150;
        price += (used - 150) * price_151_to_400;
    } else if (used > 400) {
        price += 150 * price_less_equal_150;
        price += (-150 + 400) * price_151_to_400;
        price += (used - 400) * price_more_equal_401;
    }
    

    printf("%.1f", price);
    return 0;
}