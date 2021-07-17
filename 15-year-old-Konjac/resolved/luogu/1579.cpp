//P1579 哥德巴赫猜想（升级版）
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

vector<int> gen_primes(int max);
bool is_prime(int num);

struct group {
    int first, second, third;
};

int main() { 
    vector<int> primes = gen_primes(30000);

    int goal_prime;
    cin >> goal_prime;

    vector<group> groups;
    for (int i = 0; primes[i] <= goal_prime; i++) {
        int iPrime = primes[i];
        for (int j = 0; primes[j] + primes[i] <= goal_prime; j++) {
            int jPrime = primes[j];
            if (is_prime(goal_prime - (iPrime + jPrime))) {
                int kPrime = goal_prime - (iPrime + jPrime);
                int sortation[3] = {iPrime, jPrime, kPrime};
                sort(sortation, sortation+3);
                groups.push_back({sortation[0], sortation[1], sortation[2]});
            }
        }
    }

    sort(groups.begin(), groups.end());

    cout << groups[0].first << " " << groups[0].second << " " << groups[0].third;
}

vector<int> gen_primes(int max) {
    vector<int> primes;
    for (int i = 2; i <= max; i++) {
        if (is_prime(i)) {
            primes.push_back(i);          
        }
    }
    return primes;
}

bool is_prime(int num) {
    if (num == 1 || num == 0) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

bool operator<(const group &x, const group &y) {
        if (x.first == y.first)
            return x.second < y.second;
        else 
            return x.first < y.first;
}