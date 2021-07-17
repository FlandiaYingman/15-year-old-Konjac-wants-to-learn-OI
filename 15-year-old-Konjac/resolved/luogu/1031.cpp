//P1031 均分纸牌
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> cards;
    int card_count;
    cin >> card_count;
    for (int i = 0; i < card_count; i++) {
        int temp_card;
        cin >> temp_card;
        cards.push_back(temp_card);
    }

    int sum = 0;
    for (int i = 0; i < card_count; i++) {
        sum += cards[i];
    }
    int coverage = sum / card_count;

    for (int i = 0; i < card_count; i++) {
        cards[i] -= coverage;
    }

    int ans = 0;
    for (int i = 1; i < card_count; i++) {
        if (cards[i-1] == 0) {
            continue;
        }
        cards[i] += cards[i-1];
        cards[i-1] = 0;
        ans++;
    }

    cout << ans;

    return 0;
}