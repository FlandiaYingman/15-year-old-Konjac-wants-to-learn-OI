#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> enumerate_all_permutations(int* arr, int arr_len, int count);

int main() {
    int arr_len = 4;
    int arr[] = {3, 7, 12, 19};
    vector<vector<int>> result = enumerate_all_permutations(arr, arr_len, 3);
    cout << "-------------------------------------------\n";
    for (vector<int> vi : result) {
        for (int i : vi) {
            cout << i << ", ";
        }
        cout << endl;
    }
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