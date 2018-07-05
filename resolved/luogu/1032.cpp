//P1032 字串变换

#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>
#include <fstream>

using namespace std;

struct transform_rule {
    string from, to;
};

struct transform_string {
    string val;
    int transform_times;
};

vector<transform_string> transform(const transform_string &s, const transform_rule &rule);
void bfs(queue<transform_string> &q);

string finish;
vector<transform_rule> rules;
set<string> appeared;

//ifstream fin("testdata.in");
//#define cin fin

int main() {
    string start;
    cin >> start >> finish;

    while (!cin.eof()) {
        string from, to;
        cin >> from >> to;
        if (!(from.empty() && to.empty())) {
            rules.push_back({from, to});
        }
    }

    queue<transform_string> q;
    q.push({start, 0});

    bfs(q);

    return 0;
}

void bfs(queue<transform_string> &q) {
    while (!q.empty()) {
        transform_string s = q.front();
        q.pop();

        if (s.transform_times > 10) {
            cout << "NO ANSWER!";
            return;
        }

        if (s.val == finish) {
            cout << s.transform_times;
            return;
        }

        for (int i = 0; i < rules.size(); i++) {
            vector<transform_string> v = transform(s, rules[i]);
            for (int j = 0; j < v.size(); j++) {
                if (appeared.find(v[j].val) == appeared.end()) {
                    appeared.insert(v[j].val);
                    q.push(v[j]);
                }
            }
        }
    }
    cout << "NO ANSWER!";
    return;
}

vector<transform_string> transform(const transform_string &s, const transform_rule &rule) {
    vector<transform_string> v;
    int times = s.transform_times + 1;
    string val = s.val;

    size_t pos = val.find(rule.from, 0);
    while (pos != string::npos) {
        string str(val);
        str.replace(pos, rule.from.length(), rule.to);
        v.push_back({str, times});
        pos = val.find(rule.from, pos + rule.from.length());
    }

    return v;
}
