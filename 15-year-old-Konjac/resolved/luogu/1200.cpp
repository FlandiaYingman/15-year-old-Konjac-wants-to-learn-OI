//P1200 [USACO1.1]你的飞碟在这儿Your Ride Is He…
#include<iostream>
#include<string>

using namespace std;

int name_to_id(string name);

int main() {
    string comet_name;
    string group_name;

    getline(cin, comet_name);
    getline(cin, group_name);

    int comet_id = name_to_id(comet_name);
    int group_id = name_to_id(group_name);

    if (comet_id == group_id) {
        cout << "GO";
    } else {
        cout << "STAY";
    }
}

int name_to_id(string name) {
    int product = 1;
    for (int i = 0; i < name.length(); i++) {
        char c = name.at(i);
        product *= int(c - 'A' + 1);
    }
    return product % 47;
}