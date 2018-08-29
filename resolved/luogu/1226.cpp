//P1226 【模板】快速幂||取余运算

#include <cmath>
#include <iostream>

using namespace std;

long long exponentiating_by_squaring(long long x, long long n, long long k);

int main() {
    long long b, p, k;
    cin >> b >> p >> k;
    cout << b << "^" << p << " mod " << k << "=" << exponentiating_by_squaring(b, p, k) % k;
}

long long exponentiating_by_squaring(long long x, long long n, long long k) {
    if (n == 1) {
        return x;
    } else if (n == 0) {
        return 1;
    } else if (n % 2 == 1) {
        //Is odd.
        long long xn = exponentiating_by_squaring(x, (n - 1) / 2, k) % k;
        return x * xn * xn % k;
    } else {
        //Is even.
        long long xn = exponentiating_by_squaring(x, n / 2, k) % k;
        return xn * xn % k;
    }
}