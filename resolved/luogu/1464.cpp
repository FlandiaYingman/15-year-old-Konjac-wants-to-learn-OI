//P1464 Function
#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

long long w(long long a, long long b, long long c);

map<string, long long> wmap;

int main() {
    vector<string> outputs;
    while (true) {
        long long a, b, c;
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1) {
            break;
        }
        outputs.push_back("w(" + to_string(a) + ", " + to_string(b) + ", " + to_string(c) + ") = " + to_string(w(a, b, c)));
    }
    for (string s : outputs) {
        cout << s << endl;
    }
}

long long w(long long a, long long b, long long c) {
    long long result;
    if (wmap.count(to_string(a) + ", " + to_string(b) + ", " + to_string(c)) == 1) { 
        result = wmap.find(to_string(a) + ", " + to_string(b) + ", " + to_string(c))->second;
    } else if (a <= 0 || b <= 0 || c <= 0) {
        result = 1;
    } else if (a > 20 || b > 20 || c > 20) {
        result = w(20, 20, 20);
    } else if (a < b && b < c) {
        result = w(a, b, c-1) + w(a, b-1, c-1) - w(a ,b-1 ,c);
    } else {
        result = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
    }
    wmap.insert(pair<string, long long>(to_string(a) + ", " + to_string(b) + ", " + to_string(c), result));
    return result;
}