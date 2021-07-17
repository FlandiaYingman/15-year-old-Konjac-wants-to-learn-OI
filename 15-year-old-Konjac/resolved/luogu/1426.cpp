//P1426 小鱼会有危险吗
#include<iostream>

using namespace std;

int main() {
    int detector_pos;
    int detector_dist;

    cin >> detector_pos >> detector_dist;

    int detector_low = detector_pos - detector_dist;
    int detector_high = detector_pos + detector_dist;

    double swimming_dist_step = 7.0;
    double swimming_dist = 0.0;
    double swimming_attenuation = 0.98;

    bool found = false;

    while (true) {
        if (swimming_dist > detector_high) {
            cout << "n";
            return 0;
        }
        if (found && swimming_dist >= detector_low && swimming_dist <= detector_high) {
            cout << "y";
            return 0;
        }
        if (swimming_dist >= detector_low && swimming_dist <= detector_high) {
            found = true;
        }

        swimming_dist += swimming_dist_step;
        swimming_dist_step *= swimming_attenuation;
    }
}