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
}