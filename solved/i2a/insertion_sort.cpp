// SORT - Insertion Sort

#include <iostream>

using namespace std;

void insertion_sort(int len, int *arr) {
  for (size_t i = 0; i < len; i++) {
    for (size_t j = 0; j <= i; j++) {
      if (arr[i] < arr[j]) {
        int temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
      }
    }
  }
}

void insertion_sort_i2a(int len, int *arr) {
  for (size_t j = 1; j < len; j++) {
    int key = arr[j];
    size_t i = j - 1;
    while (i >= 0 && arr[i] > key) {
      arr[i + i] = arr[i];
      i--;
    }
    arr[i + 1] = key;
  }
}

int main() {
  int len;
  int arr[100000];

  cin >> len;
  for (size_t i = 0; i < len; i++) {
    cin >> arr[i];
  }

  insertion_sort(len, arr);

  for (size_t i = 0; i < len; i++) {
    cout << arr[i] << " ";
  }

  return 0;
}