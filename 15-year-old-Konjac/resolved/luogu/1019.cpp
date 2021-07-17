// P1019 单词接龙
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

map<string, string &> cache;
map<string, int> used_times;
vector<string> words;
int max_length = 0;

void dfs(const string &str);

string concat_str(const string &a, const string &b);

int main() {
    int word_count;
    cin >> word_count;

    for (int i = 0; i < word_count; i++) {
        string s = *new string;
        cin >> s;

        words.push_back(s);
        used_times.insert(pair<string, int>(s, 0));
    }

    string start_with;
    cin >> start_with;

    dfs(start_with);

    cout << max_length;
}

void dfs(const string &str) {
    bool hasNext = false;
    for (string w : words) {
        if ((*used_times.find(w)).second >= 2) {
            continue;
        }
        if (str.size() == 1 && w[0] == str[0]) {
            hasNext = true;
            (*used_times.find(w)).second += 1;
            dfs(w);
            (*used_times.find(w)).second -= 1;
        }
        string concatenated = concat_str(str, w);
        if (!concatenated.empty()) {
            hasNext = true;
            (*used_times.find(w)).second += 1;
            dfs(concatenated);
            (*used_times.find(w)).second -= 1;
        }
    }
    if (!hasNext) {
        max_length = max(max_length, (int) str.size());
    }
}

string concat_str(const string &a, const string &b) {
    //Check cache.
    auto find = cache.find(a + " " + b);
    if (find != cache.end()) {
        return (*find).second;
    }

    int min_length = min(a.size(), b.size());
    for (int i = 1; i < min_length; i++) {
        string a_i = a.substr(a.size() - i, i);
        string b_i = b.substr(0, i);
        if (a_i == b_i) {
            string &result = *new string;
            result.assign(a.substr(0, a.size() - i) + b);
            cache.insert(pair<string, string &>(a + " " + b, result));
            return result;
        }
    }
    return *new string();
}

