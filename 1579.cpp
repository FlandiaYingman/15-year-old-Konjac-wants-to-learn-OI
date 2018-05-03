//P1579 哥德巴赫猜想（升级版）
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

vector<int> gen_primes(int max);
bool is_prime(int num);

int main() { 
    vector<int> primes;
    int prime;
    cin >> prime;
    primes = gen_primes(prime);

    vector<vector<int>> prime_goldbach;
    int min_prime_goldbach = 20001;
    for (int i = 1; i < primes.size(); i++) {
        for (int j = i; j < primes.size(); j++) {
            int ip = primes[i];
            int jp = primes[j];
            int k = prime - (ip+jp);
            cout << ip << " " << jp << " " << k << endl;
            if (is_prime(k)) {  
                vector<int> v;
                v.push_back(ip);
                v.push_back(jp);
                v.push_back(k);
                sort(v.begin(), v.end());
                min_prime_goldbach = min(v[0], min_prime_goldbach);
                cout << v[0] << " " << v[1] << " " << v[2] << endl;
                prime_goldbach.push_back(v);
            }
        }
    }

    vector<vector<int>> sames;
    for (int i = 0; i < prime_goldbach.size(); i++) {
        vector<int> is = prime_goldbach[i];
        bool flag = false;
        for (vector<int> v : sames) {
            if (v[0] == is[0] && v[1] == is[1] && v[2] == is[2]) {
                flag = true;
            }
        }
        if (is[0] == min_prime_goldbach && !flag) {
            sames.push_back(is);
            cout << is[0] << " " << is[1] << " " << is[2] << endl;
        }
    }
}

vector<int> gen_primes(int max) {
    vector<int> primes;
    for (int i = 1; i <= max; i++) {
        if (is_prime(i)) {
            primes.push_back(i);          
        }
    }
    return primes;
}

bool is_prime(int num) {
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}