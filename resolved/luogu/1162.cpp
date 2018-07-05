//P1162 填涂颜色

#include <iostream>
#include <queue>
#include <memory.h>

using namespace std;

int matrix[31][31];
bool visited[31][31];

void bfs(queue<int> &q, int n);

int main() {
    for (int i = 0; i < 31; i++) {
        for (int j = 0; j < 31; j++) {
            matrix[i][j] = 2;
        }
    }
    memset(visited, false, 31 * 31 * sizeof(int));

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int iv;
            cin >> iv;
            if (iv == 1) {
                matrix[i][j] = 1;
            }
        }
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        q.push(i);
        q.push(0);
        q.push(0);
        q.push(i);
    }
    for (int i = 0; i < n; i++) {
        q.push(i);
        q.push(n-1);
        q.push(n-1);
        q.push(i);
    }
    bfs(q, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j]) {
                cout << "0 ";
            } else {
                cout << matrix[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}

void bfs(queue<int> &q, int n) {
    while (!q.empty()) {
        int x, y;
        x = q.front();
        q.pop();
        y = q.front();
        q.pop();

        if (x >= n && y >= n && x < 0 && y < 0) {
            continue;
        }

        if (!visited[x][y] && matrix[x][y] == 2) {
            visited[x][y] = true;

            q.push(x + 1);
            q.push(y);

            q.push(x);
            q.push(y + 1);

            q.push(x - 1);
            q.push(y);

            q.push(x);
            q.push(y - 1);
        }
    }
}