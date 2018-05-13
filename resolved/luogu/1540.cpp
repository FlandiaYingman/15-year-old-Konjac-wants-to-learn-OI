//P1540 机器翻译
#include<iostream>
#include<deque>
#include<algorithm>

using namespace std;

int main() 
{
    int mem_size;
    int art_length;

    cin >> mem_size >> art_length;
    deque<int> d;
    int ans = 0;
    for (int i = 0; i < art_length; i++) {
        int word;
        cin >> word;

        if (find(d.begin(), d.end(), word) == d.end()) {
            //Not contains.
            ans++;
            if (d.size() == mem_size) {
                //Size max.
                d.pop_front();
            }
            d.push_back(word);
        }
    }

    cout << ans;
    return 0;
}