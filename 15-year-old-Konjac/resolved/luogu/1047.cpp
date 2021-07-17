//P1047 校门外的树
#include<iostream>
#include<bitset>

using namespace std;

int main() {
    bitset<10000> trees;
    trees.reset();
    int trees_count;
    cin >> trees_count;
    for (int i = 0; i <= trees_count; i++) {
        trees[i] = true;
    }

    int lines, start, end;
    cin >> lines;
    for (int i = 0; i < lines; i++) {
        cin >> start >> end;
        for (int i = start; i <= end; i++) {
            trees[i] = false;
        }
    }

    cout << trees.count();
}