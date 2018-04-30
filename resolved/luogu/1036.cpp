//P1036 选数
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool is_prime(int num);
vector<vector<int>> enumerate_all_permutations(int* arr, int arr_len, int count);

int main() {
    int n;
    int k;
    cin >> n;
    cin >> k;
    int* x = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    vector<vector<int>> enumerate = enumerate_all_permutations(x, n, k);
    int prime_count = 0;
    for (vector<int> v : enumerate) {
        int sum = 0;
        for (int i : v) {
            sum += i;
        }
        if (is_prime(sum)) {
            prime_count++;
        }
    }

    cout << prime_count;
}

vector<vector<int>> enumerate_all_permutations(int* arr, int arr_len, int count) {
    vector<vector<int>> result;
    if (count == 1) {
        for (int i = 0; i < arr_len; i++) {
            vector<int> v;
            v.push_back(arr[i]);
            result.push_back(v);
        }
        return result;
    }
    for (int i = 0; i < arr_len - (count-1); i++) {
        int key = arr[i];
        vector<vector<int>> v = enumerate_all_permutations(arr+i+1, arr_len-i-1, count-1);
        for (int j = 0; j < v.size(); j++) {
            v[j].push_back(key);
            result.push_back(v[j]);
        }
    }
    return result;
}

bool is_prime(int num) {
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

