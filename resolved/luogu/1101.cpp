//P1101 单词方阵

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

struct pos {
    int x, y;
};


bool dfs(pos p, int d, int l, int n);
bool dfs_rev(pos p, int d, int l, int n);

const string yizhong = "yizhong";
const string yizhong_rev = "gnohziy";

vector<string> alphabet_matrix;
char result_matrix[100][100];

int main() {
    int n;
    cin >> n;

    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < n; ++y) {
            result_matrix[x][y] = '*';
        }
    }

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        alphabet_matrix.push_back(str);
    }

    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < n; ++y) {
            char c = alphabet_matrix[x][y];
            if (c == yizhong[0]) {
                for (int i = 0; i < 4; i++) {
                    dfs({x, y}, i, 0, n);
                }
            }
            if (c == yizhong_rev[0]) {
                for (int i = 0; i < 4; i++) {
                    dfs_rev({x, y}, i, 0, n);
                }
            }
        }
    }

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            cout << result_matrix[x][y];
        }
        cout << endl;
    }

    return 0;
}

bool dfs(pos p, int d, int l, int n) {
    if (l >= yizhong.length()) {
        return true;
    }
    if (p.x >= n || p.x < 0 || p.y >= n || p.y < 0) {
        return false;
    }
    switch (d) {
        //horizontal
        case 0:
            if (alphabet_matrix[p.x][p.y] == yizhong[l]) {
                if (dfs({p.x + 1, p.y}, d, l + 1, n)) {
                    result_matrix[p.x][p.y] = yizhong[l];
                    return true;
                }
            }
            break;
            //vertical
        case 1:
            if (alphabet_matrix[p.x][p.y] == yizhong[l]) {
                if (dfs({p.x, p.y + 1}, d, l + 1, n)) {
                    result_matrix[p.x][p.y] = yizhong[l];
                    return true;
                }
            }
            break;
            //diagonal a
        case 2:
            if (alphabet_matrix[p.x][p.y] == yizhong[l]) {
                if (dfs({p.x + 1, p.y + 1}, d, l + 1, n)) {
                    result_matrix[p.x][p.y] = yizhong[l];
                    return true;
                }
            }
            break;
            //diagonal b
        case 3:
            if (alphabet_matrix[p.x][p.y] == yizhong[l]) {
                if (dfs({p.x + 1, p.y - 1}, d, l + 1, n)) {
                    result_matrix[p.x][p.y] = yizhong[l];
                    return true;
                }
            }
            break;
        default:
            break;
    }
    return false;
}

bool dfs_rev(pos p, int d, int l, int n) {
    if (l >= yizhong_rev.length()) {
        return true;
    }
    if (p.x >= n || p.x < 0 || p.y >= n || p.y < 0) {
        return false;
    }
    switch (d) {
        //horizontal
        case 0:
            if (alphabet_matrix[p.x][p.y] == yizhong_rev[l]) {
                if (dfs_rev({p.x + 1, p.y}, d, l + 1, n)) {
                    result_matrix[p.x][p.y] = yizhong_rev[l];
                    return true;
                }
            }
            break;
            //vertical
        case 1:
            if (alphabet_matrix[p.x][p.y] == yizhong_rev[l]) {
                if (dfs_rev({p.x, p.y + 1}, d, l + 1, n)) {
                    result_matrix[p.x][p.y] = yizhong_rev[l];
                    return true;
                }
            }
            break;
            //diagonal a
        case 2:
            if (alphabet_matrix[p.x][p.y] == yizhong_rev[l]) {
                if (dfs_rev({p.x + 1, p.y + 1}, d, l + 1, n)) {
                    result_matrix[p.x][p.y] = yizhong_rev[l];
                    return true;
                }
            }
            break;
            //diagonal b
        case 3:
            if (alphabet_matrix[p.x][p.y] == yizhong_rev[l]) {
                if (dfs_rev({p.x + 1, p.y - 1}, d, l + 1, n)) {
                    result_matrix[p.x][p.y] = yizhong_rev[l];
                    return true;
                }
            }
            break;
        default:
            break;
    }
    return false;
}

