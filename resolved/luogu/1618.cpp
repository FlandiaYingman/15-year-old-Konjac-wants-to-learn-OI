//P1618 三连击（升级版）
#include<iostream>
#include<algorithm>

int is_meet_condition(int, int, int);
int not_equals(int, const int *);

using namespace std;
int main() {
    int ac, bc, cc;
    cin >> ac >> bc >> cc;
    bool flag = false;
    for (int i = 0; i * cc <= 999; i++) {
        int a = ac * i;
        int b = bc * i;
        int c = cc * i;
        if (is_meet_condition(a, b, c)) {
            flag = true;
            cout << a << " " << b << " " << c << endl;
        }
    }
    if (flag == false) {
        cout << "No!!!";
    }
}

int is_meet_condition(int first, int second, int third) {
    if (first < 100 && second < 100 && third < 100) {
        return false;
    }

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
