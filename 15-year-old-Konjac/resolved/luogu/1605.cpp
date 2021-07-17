//P1605 迷宫

#include <iostream>

using namespace std;

struct pos {
    int x, y;
};

void dfs(pos p);

bool maze[8][8];
int ans = 0;
pos goal;

int main() {
    for (int x = 0; x < 8; ++x) {
        for (int y = 0; y < 8; ++y) {
            maze[x][y] = false;
        }
    }
    int rows, columns, walls;
    cin >> rows >> columns >> walls;
    for (int x = 1; x <= columns; ++x) {
        for (int y = 1; y <= rows; ++y) {
            maze[x][y] = true;
        }
    }
    int start_x, start_y, goal_x, goal_y;
    cin >> start_x >> start_y >> goal_x >> goal_y;
    goal = {goal_x, goal_y};
    maze[start_x][start_y] = false;
    for (int i = 0; i < walls; ++i) {
        int x, y;
        cin >> x >> y;
        maze[x][y] = false;
    }
    dfs({start_x, start_y});
    cout << ans;
    cout.flush();
    return 0;
}

void dfs(pos p) {
    if (p.x == goal.x && p.y == goal.y) {
        ans++;
        return;
    }
    //up
    if (maze[p.x][p.y + 1]) {
        maze[p.x][p.y + 1] = false;
        dfs({p.x, p.y + 1});
        maze[p.x][p.y + 1] = true;
    }
    //right
    if (maze[p.x + 1][p.y]) {
        maze[p.x + 1][p.y] = false;
        dfs({p.x + 1, p.y});
        maze[p.x + 1][p.y] = true;
    }
    //down
    if (p.y >= 1 && maze[p.x][p.y - 1]) {
        maze[p.x][p.y - 1] = false;
        dfs({p.x, p.y - 1});
        maze[p.x][p.y - 1] = true;
    }
    //right
    if (p.x >= 1 && maze[p.x - 1][p.y]) {
        maze[p.x - 1][p.y] = false;
        dfs({p.x - 1, p.y});
        maze[p.x - 1][p.y] = true;
    }
}