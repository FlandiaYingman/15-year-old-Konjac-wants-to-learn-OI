//P1126 机器人搬重物

#include <iostream>
#include <queue>
#include <set>

using namespace std;

struct pos {
    int x, y;
    int used_time;
    char facing;

    bool operator<(const pos &rhs) const {
        if (x != rhs.x) {
            return x < rhs.x;
        } else if (y != rhs.y) {
            return y < rhs.y;
        } else {
            return facing < rhs.facing;
        }
    }

    bool operator==(const pos &rhs) const {
        return x == rhs.x && y == rhs.y && facing == rhs.facing;
    }
};

int bfs(queue<pos> &q);

inline bool is_validated(const pos &p1);

inline pos move_front(const pos &p);

inline pos turn_left(const pos &p);

inline pos turn_right(const pos &p);

int row_count;
int column_count;

//The first index is the y-axis or 'row number', the second index is the x-axis or 'column number'.
bool wall[51][51];

int start_x, start_y, end_x, end_y;
char start_facing;

int main() {
    cin >> row_count >> column_count;

    for (int row = 1; row <= row_count; row++) {
        for (int column = 1; column <= column_count; column++) {
            cin >> wall[row][column];
        }
    }

    cin >> start_y >> start_x >> end_y >> end_x >> start_facing;

    queue<pos> q;
    q.push({start_x, start_y, 0, start_facing});

    int min_time = bfs(q);

    cout << min_time;

    return 0;
}

int bfs(queue<pos> &q) {
    set<pos> appeared;
    while (!q.empty()) {
        pos p = q.front();
        q.pop();

        if (p.x == end_x && p.y == end_y) {
            return p.used_time;
        }

        pos creep = move_front(p);
        if (is_validated(creep) && appeared.find(creep) == appeared.end()) {
            creep.used_time += 1;
            q.push(creep);
            appeared.insert(creep);
        }

        pos walk = move_front(move_front(p));
        if (is_validated(walk) && is_validated(creep) && appeared.find(walk) == appeared.end()) {
            walk.used_time += 1;
            q.push(walk);
            appeared.insert(walk);
        }

        pos run = move_front(move_front(move_front(p)));
        if (is_validated(run) && is_validated(walk) && is_validated(creep) && appeared.find(run) == appeared.end()) {
            run.used_time += 1;
            q.push(run);
            appeared.insert(run);
        }

        pos left = turn_left(p);
        if (appeared.find(left) == appeared.end()) {
            left.used_time += 1;
            q.push(left);
            appeared.insert(left);
        }

        pos right = turn_right(p);
        if (appeared.find(right) == appeared.end()) {
            right.used_time += 1;
            q.push(right);
            appeared.insert(right);
        }
    }
    return -1;
}

inline bool is_validated(const pos &p1) {
    pos p2 = {p1.x + 1, p1.y, p1.used_time, p1.facing};
    pos p3 = {p1.x, p1.y + 1, p1.used_time, p1.facing};
    pos p4 = {p1.x + 1, p1.y + 1, p1.used_time, p1.facing};
    return p1.x >= 1 && p1.y >= 1 && p1.x <= column_count && p1.y <= row_count && !wall[p1.y][p1.x] &&
           p2.x >= 1 && p2.y >= 1 && p2.x <= column_count && p2.y <= row_count && !wall[p2.y][p2.x] &&
           p3.x >= 1 && p3.y >= 1 && p3.x <= column_count && p3.y <= row_count && !wall[p3.y][p3.x] &&
           p4.x >= 1 && p4.y >= 1 && p4.x <= column_count && p4.y <= row_count && !wall[p4.y][p4.x];

}

inline pos move_front(const pos &p) {
    switch (p.facing) {
        case 'N':
            return {p.x, p.y - 1, p.used_time, p.facing};
        case 'S':
            return {p.x, p.y + 1, p.used_time, p.facing};
        case 'W':
            return {p.x - 1, p.y, p.used_time, p.facing};
        case 'E':
            return {p.x + 1, p.y, p.used_time, p.facing};
        default:
            return {-1, -1, -1, -1};
    }
}

inline pos turn_left(const pos &p) {
    switch (p.facing) {
        case 'N':
            return {p.x, p.y, p.used_time, 'W'};
        case 'S':
            return {p.x, p.y, p.used_time, 'E'};
        case 'W':
            return {p.x, p.y, p.used_time, 'S'};
        case 'E':
            return {p.x, p.y, p.used_time, 'N'};
        default:
            return {-1, -1, -1, -1};
    }
}

inline pos turn_right(const pos &p) {
    switch (p.facing) {
        case 'N':
            return {p.x, p.y, p.used_time, 'E'};
        case 'S':
            return {p.x, p.y, p.used_time, 'W'};
        case 'W':
            return {p.x, p.y, p.used_time, 'N'};
        case 'E':
            return {p.x, p.y, p.used_time, 'S'};
        default:
            return {-1, -1, -1, -1};
    }
}