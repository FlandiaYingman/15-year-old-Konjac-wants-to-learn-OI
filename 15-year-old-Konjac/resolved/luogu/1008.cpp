//P1008 三连击
#include<iostream>
#include<algorithm>

int is_meet_condition(int, int, int);
int not_equals(int, const int *);

using namespace std;
int main() {
    for (int i = 100; i * 3 <= 999; i++) {
        int a = 1 * i;
        int b = 2 * i;
        int c = 3 * i;
        if (is_meet_condition(a, b, c)) {
            cout << a << " " << b << " " << c << endl;
        }
    }
}

int is_meet_condition(int first, int second, int third) {
    int li[9] = {first / 100, first % 100 / 10, first % 100 % 10,
                    second / 100, second % 100 / 10, second % 100 % 10,
                    third / 100, third % 100 / 10, third % 100 % 10};
    if (find(begin(li), end(li), 0) != end(li)) {
        return false;
    }
    return not_equals(9, li);
}

int not_equals(int length, const int * arr) {
    int not_equals;
    for (int i = 0; i < length-1; i++) {
        for (int j = i + 1; j < length; j++) {
            if (arr[i] == arr[j]) {
                return false;
            }
        }
    }
    return true;
}
