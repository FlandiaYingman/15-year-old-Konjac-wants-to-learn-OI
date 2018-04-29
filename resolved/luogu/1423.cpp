//P1423 小玉在游泳
#include<iostream>

using namespace std;

int main() {
    double goal_dist;
    cin >> goal_dist;

    double prev_step_dist = 2;
    int swim_step = 0;
    double swim_dist = 0;

    for (; swim_dist <= goal_dist; swim_step++) {
        swim_dist += prev_step_dist;
        prev_step_dist *= 0.98;
        cout << swim_dist << endl;
    }

    cout << swim_step;
    return 0;
}