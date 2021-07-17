//P1563 玩具谜题

#include<iostream>
#include<string>
#include<vector>
#include<cmath>

using namespace std;
int count_n(int dir, int origin, int step, int n);

struct toy {
    string name;
    int direction;
    int compute_direction(int dir) {
        if (this->direction == 1) {
            return dir;
        } else {
            return dir == 0 ? 1 : 0;
        }
    }
};

int main() {
    vector<toy> toys;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int dir;
        string name;
        cin >> dir >> name;
        toy t;
        t.name = name;
        t.direction = dir;
        toys.push_back(t);
    }

    int location = 0;
    for (int i = 0; i < m; i++) {
        int dir;
        int step;
        cin >> dir >> step;
        location = count_n(toys[location].compute_direction(dir), location, step, n);
        //cout << "now it's " << toys[location].name << endl;
    }
    cout << toys[location].name;
}

int count_n(int dir, int origin, int step, int n) {
    if (dir == 0) {
        //cout << "anticlockwise count " << step << endl;
        return (origin + step) % n;
    } else {
        //cout << "clockwise count " << step << endl;
        return (n + origin - step) % n;
    }
}

