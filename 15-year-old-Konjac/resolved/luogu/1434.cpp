//P1434 [SHOI2002]滑雪

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

struct pos_node {
    int x, y;

    bool operator<(const pos_node &rhs) const {
        if (x < rhs.x) {
            return true;
        } else {
            return y < rhs.y;
        }
    }
};

int dfs(pos_node cur);

int map[100][100];
int val[100][100];
int row_count, column_count;

int main() {
    cin >> row_count >> column_count;
    for (int y = 0; y < row_count; y++) {
        for (int x = 0; x < column_count; x++) {
            cin >> map[x][y];
        }
    }
    memset(val, -1, 100 * 100 * sizeof(int));

    int max_val = -1;
    for (int y = 0; y < row_count; y++) {
        for (int x = 0; x < column_count; x++) {
            pos_node start = {x, y};
            dfs(start);
            if (val[x][y] > max_val) {
                max_val = val[x][y];
            }
        }
    }

    cout << max_val;
    return 0;
}

int dfs(pos_node cur) {
    //If the value is cached, return the cached value.
    if (val[cur.x][cur.y] != -1) {
        return val[cur.x][cur.y];
    } else {
        int left = 0, right = 0, up = 0, down = 0;
        if (cur.x >= 1 && map[cur.x][cur.y] > map[cur.x - 1][cur.y]) {
            left = dfs({cur.x - 1, cur.y});
        }
        if (cur.x < column_count - 1 && map[cur.x][cur.y] > map[cur.x + 1][cur.y]) {
            right = dfs({cur.x + 1, cur.y});
        }
        if (cur.y >= 1 && map[cur.x][cur.y] > map[cur.x][cur.y - 1]) {
            up = dfs({cur.x, cur.y - 1});
        }
        if (cur.y < row_count - 1 && map[cur.x][cur.y] > map[cur.x][cur.y + 1]) {
            down = dfs({cur.x, cur.y + 1});
        }
        val[cur.x][cur.y] = max((initializer_list<int>) {left, right, up, down}) + 1;
        return val[cur.x][cur.y];
    }
}
