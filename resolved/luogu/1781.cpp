//P1781 宇宙总统

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int length;
    cin >> length;
    string max;
    int max_num;
    for (int i = 1; i <= length; i++)
    {
        string cur;
        cin >> cur;
        if (cur.length() > max.length())
        {
            max = cur;
            max_num = i;
        }
        else if (cur.length() == max.length())
        {
            if (cur > max)
            {
                max = cur;
                max_num = i;
            }
        }
    }

    cout << max_num << endl << max;

    return 0;
}