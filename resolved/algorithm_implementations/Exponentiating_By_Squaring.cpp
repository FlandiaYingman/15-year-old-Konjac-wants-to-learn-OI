#include <iostream>

using std::cout;
using std::endl;

long long simple_exponentiating(int x, int n, int &times_counter);

long long exponentiating_by_squaring(int x, int n, int &times_counter);

int main() {
    int x = 3;
    int n = 6666666;
    cout << "compute: " << x << "^" << n << endl;

    int times_counter = 0;
    cout << "using simple_exponentiating(): "
         << simple_exponentiating(x, n, times_counter)
         << endl;
    cout << "used " << times_counter << " times *" << endl;

    times_counter = 0;
    cout << "using exponentiating_by_squaring(int x, int n): "
         << exponentiating_by_squaring(x, n, times_counter)
         << endl;
    cout << "used " << times_counter << " times *" << endl;

    return 0;
}

long long simple_exponentiating(int x, int n, int &times_counter) {
    long long xn = 1;
    for (int i = 0; i < n; i++) {
        times_counter += 1;
        xn *= x;
    }
    return xn;
}

long long exponentiating_by_squaring(int x, int n, int &times_counter) {
    if (n == 1) {
        return x;
    } else if (n % 2 == 1) {
        //Is odd.
        long long xn = exponentiating_by_squaring(x, (n - 1) / 2, times_counter);
        times_counter += 2;
        return x * xn * xn;
    } else if (n % 2 == 0) {
        //Is even.
        long long xn = exponentiating_by_squaring(x, n / 2, times_counter);
        times_counter += 1;
        return xn * xn;
    } else {
        return -1;
    }
}