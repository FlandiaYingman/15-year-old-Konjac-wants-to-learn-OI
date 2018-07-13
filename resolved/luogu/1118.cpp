//P1118 [USACO06FEB]数字三角形`Backward Digit Su`…

#include <iostream>

using namespace std;

void init_pascal_triangle(int length);

int compute_sum(int length);

bool dfs(int length);

int goal_length, goal_sum;
int pascal_triangle[12] = {0};
bool num_used[13] = {false};
int sequence[12] = {0};

int main() {
    cin >> goal_length >> goal_sum;
    init_pascal_triangle(goal_length);
    dfs(0);
    return 0;
}

bool dfs(int length) {
    if (length == goal_length && compute_sum(length) == goal_sum) {
        for (int i = 0; i < length; i++) {
            cout << sequence[i] << " ";
        }
        return true;
    }

    if (length >= goal_length || compute_sum(length) >= goal_sum) {
        return false;
    }

    int unused_num = 0;
    for (int i = 1; i <= goal_length; i++) {
        if (!num_used[i]) {
            unused_num = i;
            num_used[unused_num] = true;
            sequence[length] = unused_num;
            if (dfs(length + 1)) {
                return true;
            }
            num_used[unused_num] = false;
            sequence[length] = 0;
        }
    }
    return false;
}

void init_pascal_triangle(int length) {
    for (int i = 0; i < length; i++) {
        pascal_triangle[0] = 1;
        for (int j = i; j > 0; j--) {
            pascal_triangle[j] = pascal_triangle[j] + pascal_triangle[j - 1];
        }
    }
}

int compute_sum(int length) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += pascal_triangle[i] * sequence[i];
    }
    return sum;
}