//P1181 数列分段Section I
#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

tuple<int, int> min_max_extract(vector<int> &v);

int main()
{
    vector<int> v;
    int length, max_of_part;
    cin >> length >> max_of_part;

    for (int i = 0; i < length; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }

    int add_count = 0;
    int ans = 1;
    for (int i = 0; i < length; i++)
    {
        if (add_count + v[i] <= max_of_part) {
            add_count += v[i];
        } else {
            add_count = v[i];
            ans++;
        }
    }

    cout << ans;
    return 0;
}