//P1425 小鱼的游泳时间
#include<iostream>

using namespace std;
int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int start = (a * 60) + b;
    int end = (c * 60) + d;

    int swimming_time = end - start;
    int swimming_time_hour = swimming_time / 60;
    int swimming_time_min = swimming_time % 60;

    cout << swimming_time_hour << " " << swimming_time_min;
    return 0;
}