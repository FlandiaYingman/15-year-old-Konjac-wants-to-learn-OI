//P1085 不高兴的津津
#include<iostream>

using namespace std;
int main() {
    int max_day;
    int max_study_hour = 0;
    for (int i = 1; i <= 7; i++) {
        int day, study_hour, a, b;

        cin >> a >> b;
        study_hour = a + b;
        if (max_study_hour < study_hour) {
            max_study_hour = study_hour;
            max_day = i;
        }
    }

    cout << max_day;
    return 0;
}