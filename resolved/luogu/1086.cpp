//P1086 花生采摘
#include <iostream>
#include <cmath>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

struct coor
{
    int x;
    int y;

    bool operator==(const coor &b)
    {
        return x == b.x && y == b.y;
    }
};

const coor road = {-1, -1};

coor max_of(int peanuts[21][21], int width, int height);
int time_of(coor start, coor end);

int main()
{
    int peanuts[21][21];
    int width, height;
    int time_limit;
    cin >> height >> width >> time_limit;
    for (int y = 1; y <= height; y++)
    {
        for (int x = 1; x <= width; x++)
        {
            cin >> peanuts[x][y];
        }
    }

    int time_used = 0;
    int peanut_get = 0;
    coor current_pos = {-1, -1};
    while (true) {
        coor max = max_of(peanuts, width, height);
        int time_to_max = time_of(current_pos, max);
        int time_max_to_road = time_of(max, road);
        if (max == road) {
            cout << peanut_get;
            return 0;
        }
        if ((time_used + time_to_max + time_max_to_road) < time_limit) {
            int peanut = peanuts[max.x][max.y];
            peanuts[max.x][max.y] = 0;
            peanut_get += peanut;
            time_used += time_to_max+1;
            current_pos = max;
        } else {
            cout << peanut_get;
            return 0;
        }
    }
}

coor max_of(int peanuts[21][21], int width, int height)
{
    int max_val = 0;
    coor max_coor = {-1, -1};
    for (int y = 1; y <= height; y++)
    {
        for (int x = 1; x <= width; x++)
        {
            if (peanuts[x][y] > max_val)
            {
                max_val = peanuts[x][y];
                max_coor = {x, y};
            }
        }
    }
    return max_coor;
}

int time_of(coor start, coor end)
{
    if (start == road && end == road) {
        return 0;
    }
    if (start == road)
    {
        return end.y;
    }
    if (end == road) {
        return start.y;
    }
    int manhattan_dist = abs(start.x - end.x) + abs(start.y - end.y);
    return manhattan_dist;
}