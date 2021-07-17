//P1433 吃奶酪

#include <iostream>
#include <vector>
#include <cmath>
#include <cfloat>

using namespace std;

struct node {
    double x, y;
    int num;

    double distance_to(const node &rhs) const {
        return sqrt((x - rhs.x) * (x - rhs.x) + (y - rhs.y) * (y - rhs.y));
    }
};

vector<node> cheeses;
double distance_of[15][15];
int n;

double shortest_traversal_distance();

void dfs(double &min_length, node n, double length, int visited_count, bool visited[]);

int main() {
    cin >> n;
    cheeses.push_back({0, 0, 0});
    for (int i = 1; i <= n; i++) {
        double x, y;
        cin >> x >> y;
        cheeses.push_back({x, y, i});
    }
    for (int i = 0; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            distance_of[i][j] = distance_of[j][i] = cheeses[i].distance_to(cheeses[j]);
        }
    }

    printf("%.2f", shortest_traversal_distance());
}

double shortest_traversal_distance() {
    double min_length = DBL_MAX;
    bool b[15];
    b[0] = true;
    dfs(min_length, cheeses[0], 0, 0, b);
    return min_length;
}

void dfs(double &min_length, node v, double length, int visited_count, bool visited[]) {
    if (visited_count >= n) {
        min_length = min(min_length, length);
    } else if (length < min_length) {
        for (int i = 0; i <= n; i++) {
            node w = cheeses[i];
            if (!visited[w.num]) {
                visited[w.num] = true;
                dfs(min_length, w, length + distance_of[v.num][w.num], visited_count+1, visited);
                visited[w.num] = false;
            }
        }
    }
}