//P1208 [USACO1.3]混合牛奶 Mixing Milk
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct dairy_farmer
{
    int price, count;
    static bool comp_price(dairy_farmer &a, dairy_farmer &b)
    {
        return a.price < b.price;
    }
};


int main()
{
    int needed_milk, dairy_farmer_count;
    cin >> needed_milk >> dairy_farmer_count;
    vector<dairy_farmer> v;
    for (int i = 0; i < dairy_farmer_count; i++)
    {
        dairy_farmer d = *new dairy_farmer;
        cin >> d.price >> d.count;
        v.push_back(d);
    }
    sort(v.begin(), v.end(), dairy_farmer::comp_price);
    int used_money = 0;
    while (needed_milk > 0)
    {
        if (needed_milk < v[0].count) {
            used_money += v[0].price * needed_milk;
            needed_milk = 0;
            v[0].count -= needed_milk;
        } else {
            used_money += v[0].count * v[0].price;
            needed_milk -= v[0].count;
            v[0].count = 0;
            v.erase(v.begin());
        }
    }
    cout << used_money;
    return 0;
}