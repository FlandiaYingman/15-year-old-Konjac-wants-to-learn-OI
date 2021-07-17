//P1217 [USACO1.5]回文质数 Prime Palindromes
#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<stack>

using namespace std;

bool is_prime(long num);
vector<string> gen_palindromes(int digit);
vector<long> gen_prime_palidromes(int digit);
vector<long> gen_prime_palidromes(long low, long high);
int get_digit(long num);

int main() {
    long low, high;
    cin >> low >> high;
    vector<long> p = gen_prime_palidromes(low, high);
    for (long l : p) {
        cout << l << endl;
    }
}

bool is_prime(long num) {
    if (num % 2 == 0) return false;
    for (long i = 3; i * i <= num; i+=2) {
        if (num % i == 0) return false;
    }
    return true;
}

vector<string> gen_palindromes(int digit) {
    vector<string> v;
    if (digit == 2) {
        for (int i = 0; i < 10; i++) {
            v.push_back(to_string(i) + to_string(i));
        }
        return v;
    } else if (digit == 1) {
        for (int i = 0; i < 10; i++) {
            v.push_back(to_string(i));
        }
        return v;
    } else {
        for (int i = 0; i < 10; i++) {
            for (string s : gen_palindromes(digit-2)) {
                v.push_back(to_string(i) + s + to_string(i));
            }
        }
        return v;
    }
}

vector<long> gen_prime_palidromes(int digit) {
    vector<string> palidromes = gen_palindromes(digit);
    vector<long> prime_palidromes;
    for (string s : palidromes) {
        if (s.length() > 1 && s.at(0) == '0') {
            continue;
        } else {
            long l = stol(s);
            if (is_prime(l)) {
                prime_palidromes.push_back(l);
            }
        }
    }
    return prime_palidromes;
}

vector<long> gen_prime_palidromes(long low, long high) {
    vector<long> v;
    for (long i = get_digit(low); i <= get_digit(high); i++) {
        vector<long> nv = gen_prime_palidromes(i);
        for (long l : nv) {
            if (l >= low && l <= high) {
                v.push_back(l);
            }
        }
    }
    return v;
}

int get_digit(long num) {
    return 1 + (int) log10(num);
}