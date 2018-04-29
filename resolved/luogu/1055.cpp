//P1055 ISBN号码
#include<iostream>
#include<string>
#include<cstring>

using namespace std;

int main() {
    string isbn;
    cin >> isbn;

    int ans = 0;
    int hyp = 0;
    for (int i = 0; i < 9+hyp; i++) {
        char at = isbn.at(i);
        if (at == '-') {
            hyp++;
            continue;
        } else {
            ans += (i+1-hyp) * (at - '0');
        }
    }
    ans %= 11;
    char in = isbn.at(isbn.length()-1);
    if (in == char(ans + '0')) {
        cout << "Right";
    } else if (ans == 10 && in == 'X') {
        cout << "Right";
    } else if (ans == 10) {
        isbn.erase(isbn.length()-1);
        isbn.insert(isbn.length(), 1, 'X');    
        cout << isbn;
    } else {
        isbn.erase(isbn.length()-1);
        isbn.insert(isbn.length(), 1, char(ans + '0'));    
        cout << isbn;
    }
}