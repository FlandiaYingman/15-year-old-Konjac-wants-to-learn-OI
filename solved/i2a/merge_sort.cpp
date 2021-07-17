// SORT - Merge Sort

#include <climits>
#include <iostream>

using namespace std;

void merge_sort(int low, int high, int *arr) {
  if (low + 1 == high) {
    return;
  }

  int mid = (low + high) / 2;
  merge_sort(low, mid, arr);
  merge_sort(mid, high, arr);
  int temp_len = high - low;
  int *temp_arr = new int[temp_len];
  int low_i = low;
  int high_i = mid;
  for (int temp_i = 0; temp_i < temp_len; temp_i++) {
    if (high_i >= high) {
      temp_arr[temp_i] = arr[low_i++];
      continue;
    }
    if (low_i >= mid) {
      temp_arr[temp_i] = arr[high_i++];
      continue;
    }
    if (arr[low_i] <= arr[high_i]) {
      temp_arr[temp_i] = arr[low_i++];
      continue;
    }
    if (arr[low_i] >= arr[high_i]) {
      temp_arr[temp_i] = arr[high_i++];
      continue;
    }
  }
  for (int temp_i = 0; temp_i < temp_len; temp_i++) {
    arr[low + temp_i] = temp_arr[temp_i];
  }
  delete temp_arr;
}

void merge_sort(int len, int *arr) { merge_sort(0, len, arr); }

void merge_i2a(int low, int high, int mid, int *arr) {
  int *low_arr = new int[mid - low + 1];
  int *high_arr = new int[high - mid + 1];
  for (int i = 0; i < mid - low; i++) {
    low_arr[i] = arr[low + i];
  }
  for (int i = 0; i < high - mid; i++) {
    high_arr[i] = arr[mid + i];
  }
  low_arr[mid - low] = INT_MAX;
  high_arr[high - mid] = INT_MAX;
  for (int li = 0, hi = 0, i = low; i < high; i++) {
    if (low_arr[li] < high_arr[hi]) {
      arr[i] = low_arr[li++];
    } else {
      arr[i] = high_arr[hi++];
    }
  }
  delete low_arr;
  delete high_arr;
}

void merge_sort_i2a(int low, int high, int *arr) {
  if (high - low > 1) {
    int mid = (low + high) / 2;
    merge_sort_i2a(low, mid, arr);
    merge_sort_i2a(mid, high, arr);
    merge_i2a(low, high, mid, arr);
  }
}

void merge_sort_i2a(int len, int *arr) { merge_sort_i2a(0, len, arr); }

int main() {
  int len;
  int arr[100000];

  cin >> len;
  for (size_t i = 0; i < len; i++) {
    cin >> arr[i];
  }

  merge_sort_i2a(len, arr);

  for (size_t i = 0; i < len; i++) {
    cout << arr[i] << " ";
  }

  return 0;
}