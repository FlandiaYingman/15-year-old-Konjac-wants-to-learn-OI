//P1914 小书童——密码
#include<iostream>
#include<string>

using namespace std;

char next(char c);
string next(string s);

int main() {
    int times;
    string str;
    cin >> times;
    cin >> str;

    for (int i = 0; i < times; i++) {
        str = next(str);
    }

    cout << str;
}

char next(char c) {
    if (c == 'z')
        return 'a';
    return c+1;
}

string next(string s) {
    string result;
    for (char c : s) {
        result += next(c);
    }
    return result;
}