//P1478 陶陶摘苹果（升级版）
#include<iostream>

using namespace std;

void insertion_sort(int* arr, int arr_len, int* arrb);

int main() {
    int height;
    int chair_height;
    int power;
    int apple_count;

    int apple_height[5000];
    int apple_power[5000];

    cin >> apple_count >> power;
    cin >> chair_height >> height;

    int able_apple_count = 0;
    for (int i = 0; i < apple_count; i++) {
        cin >> apple_height[i] >> apple_power[i];
    
    }

    insertion_sort(apple_power, apple_count, apple_height);

    for (int i = 0; i < apple_count; i++) {
        if (apple_height[i] <= height + chair_height && power-apple_power[i] >= 0) {
            power -= apple_power[i];
            able_apple_count++;
        }
    }

    cout << able_apple_count;
}

void insertion_sort(int* arr, int arr_len, int* arrb) {
    for (int i = 1; i < arr_len; i++) {
        int key = arr[i];
        int keyb = arrb[i];
        int j;
        for (j = i-1; j >= 0 && arr[j] >= key; j--) {
            arrb[j+1] = arrb[j];
            arr[j+1] = arr[j];
        }
        arrb[j+1] = keyb;
        arr[j+1] = key;
    }
}