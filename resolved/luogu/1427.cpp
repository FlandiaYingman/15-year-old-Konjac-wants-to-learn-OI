//P1427 小鱼的数字游戏
#include<iostream>

using namespace std;

int main() {
    int nums[100];
    int tmp;
    int count = 0;
    
    cin >> tmp;
    while (tmp != 0) {
        nums[count] = tmp;
        count++;
        cin >> tmp;
    }

    for (int i = count-1; i >= 0; i--) {
        if (nums[i] != 0) {
            cout << nums[i] << " ";
        }
    }
}