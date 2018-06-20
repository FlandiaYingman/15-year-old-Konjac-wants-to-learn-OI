// P1219 八皇后
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

void nqueen(int n, int rwn);
bool arr_lesser_than(const int *arra, const int *arrb);

int hrz[13], vtc[13], dga[25], dgb[25];
vector<int *> ans;
int ansc = 0;

int main() {
    for (int i = 0; i < 13; i++) {
        hrz[i] = vtc[i] = -1;
    }
    for (int i = 0; i < 25; i++) {
        dga[i] = dgb[i] = -1;
    }
    int n;
    cin >> n;
    nqueen(n, 0);

    for (int i = 0; i < (ans.size() > 3 ? 3 : ans.size()); i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j]+1 << " ";
        }
        cout << endl;
    }
    cout << ansc << endl;
    return 0;
}

void nqueen(int n, int rwn) {
    if (rwn >= n) {
        int *res = new int[13];
        memcpy(res, hrz, sizeof(int) * 13);
        ans.push_back(res);
        sort(ans.begin(), ans.end(), arr_lesser_than);
        if (ans.size() > 3) {
            ans.erase(ans.end() - 1);
        }
        ansc++;
        return;
    }
    for (int clmn = 0; clmn < n; clmn++) {
        if (hrz[rwn] == -1 && vtc[clmn] == -1 && dga[rwn + clmn] == -1 &&
            dgb[rwn - clmn + 12] == -1) {
            hrz[rwn] = clmn;
            vtc[clmn] = rwn;
            dga[rwn + clmn] = rwn - clmn + 12;
            dgb[rwn - clmn + 12] = rwn + clmn;
            nqueen(n, rwn + 1);
            hrz[rwn] = -1;
            vtc[clmn] = -1;
            dga[rwn + clmn] = -1;
            dgb[rwn - clmn + 12] = -1;
        }
    }
}

bool arr_lesser_than(const int *arra, const int *arrb) {
    for (int i = 0; i < 13; i++) {
        if (arra[0] < arrb[0]) {
            return true;
        }
    }
    return false;
}
