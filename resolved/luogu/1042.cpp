//P1042 乒乓球
#include<iostream>
#include<vector>

using namespace std;

int main() {
    vector<int> w_score_11;
    vector<int> l_score_11;
    vector<int> w_score_21;
    vector<int> l_score_21;

    char temp;
    cin.get(temp);
    int w_temp_11 = 0;
    int l_temp_11 = 0;
    int w_temp_21 = 0;
    int l_temp_21 = 0;
    while (true) {
        if (temp == 'W') {
            w_temp_11++;
            w_temp_21++;
            if (w_temp_11 >= 11 && w_temp_11 - l_temp_11 >= 2) {
                w_score_11.push_back(w_temp_11);
                l_score_11.push_back(l_temp_11);
                w_temp_11 = 0;
                l_temp_11 = 0;
            }
            if (w_temp_21 >= 21 && w_temp_21 - l_temp_21 >= 2) {
                w_score_21.push_back(w_temp_21);
                l_score_21.push_back(l_temp_21);
                w_temp_21 = 0;
                l_temp_21 = 0;
            }
        }
        if (temp == 'L') {
            l_temp_11++;
            l_temp_21++;
            if (l_temp_11 >= 11 && l_temp_11 - w_temp_11 >= 2) {
                w_score_11.push_back(w_temp_11);
                l_score_11.push_back(l_temp_11);
                w_temp_11 = 0;
                l_temp_11 = 0;
            }
            if (l_temp_21 >= 21 && l_temp_21 - w_temp_21 >= 2) {
                w_score_21.push_back(w_temp_21);
                l_score_21.push_back(l_temp_21);
                w_temp_21 = 0;
                l_temp_21 = 0;
            }
        }
        if (temp == 'E') {
            w_score_11.push_back(w_temp_11);
            l_score_11.push_back(l_temp_11);
            w_score_21.push_back(w_temp_21);
            l_score_21.push_back(l_temp_21);
            break;
        }
        cin.get(temp);
    }

    for (int i = 0; i < w_score_11.size(); i++) {
        cout << w_score_11[i] << ":" << l_score_11[i] << endl;
    }
    cout << endl;
    for (int i = 0; i < w_score_21.size(); i++) {
        cout << w_score_21[i] << ":" << l_score_21[i] << endl;
    }
}