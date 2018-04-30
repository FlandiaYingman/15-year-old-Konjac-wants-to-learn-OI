#include<iostream>
#include<vector>

using namespace std;

void insertion_sort(int* arr, int arr_len);

int main() {
    int arr_len = 6;
    int arr[] = {6, 4, 5, 3, 2, 1};
    for (int i : arr) {
        cout << i << ", ";
    }
    insertion_sort(arr, arr_len);
    for (int i : arr) {
        cout << i << ", ";
    }
    return 0;
}

void insertion_sort(int* arr, int arr_len) {
    for (int i = 1; i < arr_len; i++) {
        int key = arr[i];
        int j;
        for (j = i-1; j >= 0 && arr[j] >= key; j--) {
            arr[j+1] = arr[j];
        }
        arr[j+1] = key;
    }
}