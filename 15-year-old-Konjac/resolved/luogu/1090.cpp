//P1090 合并果子
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int extract_min(vector<int> &v);

int main()
{
    int size;
    cin >> size;
    vector<int> v(size);
    for (int i = 0; i < size; i++)
    {
        cin >> v[i];
    }

    int ans = 0;
    while (true) {
        int a = extract_min(v);
        int b = extract_min(v);
        if (a== INT_MAX || b == INT_MAX) {
            break;
        }
        v.push_back(a + b);
        ans += a + b;
    }

    cout << ans;
    return 0;
}

int extract_min(vector<int> &v)
{
    if (v.size() == 0)
    {
        return INT_MAX;
    }
    int min_index = INT_MAX;
    int min_value = INT_MAX;
    for (int i = 0; i < v.size(); i++)
    {
        if (min_value > v[i])
        {
            min_value = v[i];
            min_index = i;
        }
    }
    v.erase(v.begin() + min_index);
    return min_value;
}