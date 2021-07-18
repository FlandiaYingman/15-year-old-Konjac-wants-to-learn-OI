// DP - Cut Rod

#include <algorithm>
#include <iostream>

using namespace std;

int price[] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};

// recursive top-down solution, not DP
int cut_rod_rec(int rod) {
    if (rod == 0) {
        return price[rod];
    }
    int ans = price[rod];
    for (int sub_rod = 1; sub_rod < rod; sub_rod++) {
        ans = max(ans, price[sub_rod] + cut_rod_rec(rod - sub_rod));
    }
    return ans;
}

int cut_rod_rec_mem_aux(int rod, int memo[]) {
    if (memo[rod] != -1) {
        return memo[rod];
    }
    if (rod == 0) {
        return price[rod];
    }
    int ans = price[rod];
    for (int sub_rod = 1; sub_rod < rod; sub_rod++) {
        ans = max(ans, price[sub_rod] + cut_rod_rec_mem_aux(rod - sub_rod, memo));
    }
    memo[rod] = ans;
    return ans;
}

// recursive top-down solution, memoized
int cut_rod_rec_mem(int rod) {
    int memo[rod];
    fill(memo, memo + rod - 1, -1);

    return cut_rod_rec_mem_aux(rod, memo);
}

// loop bottom-up solution, memoized
int cut_rod_loop(int rod_len) {
    int memo[rod_len];
    memo[0] = 0;

    for (int i = 1; i <= rod_len; i++) {
        int best_for_i = price[i];
        for (int j = 0; j < i; j++) {
            best_for_i = max(best_for_i, price[i - j] + memo[j]);
        }
        memo[i] = best_for_i;
    }

    return memo[rod_len];
}

int main() {
    int cut_rod = cut_rod_loop(9);
    cout << cut_rod;
}