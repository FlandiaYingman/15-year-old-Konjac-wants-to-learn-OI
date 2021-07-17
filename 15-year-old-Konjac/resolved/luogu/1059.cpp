//P1059 明明的随机数
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main()
{
    set<int> s;
    int length;
    cin >> length;
    for (int i = 0; i < length; i++)
    {
        int t;
        cin >> t;
        s.insert(t);
    }

    vector<int> v(s.size());
    copy(s.begin(), s.end(), v.begin());

    sort(v.begin(), v.end());

    cout << v.size() << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    
    return 0;
}