//P1308 统计单词数
#include <iostream>
#include <string>
#include <algorithm>

using std::string;
using std::getline;
using std::cin;
using std::cout;
using std::endl;
using std::size_t;

void to_lowercase(string &);
size_t find_keyword(string& keyword, string text, size_t pos);

int main() {
    string keyword;
    string text;

    getline(cin, keyword);
    getline(cin, text);

    to_lowercase(keyword);
    to_lowercase(text);

    int first_occurrence = 0;
    if ((first_occurrence = find_keyword(keyword, text, 0)) == string::npos) {
        //Not found.
        cout << -1;
        return 0;
    } else {
        //Found.
        int occurrence_count = 1;
        int occurrence_pos = first_occurrence+1;
        while ((occurrence_pos = find_keyword(keyword, text, occurrence_pos)) != string::npos) {
            occurrence_count++;
            occurrence_pos = occurrence_pos+1;
        }
        cout << occurrence_count << " " << first_occurrence;
        return 0;
    }
}

void to_lowercase(string& str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
}

size_t find_keyword(string& keyword, string text, size_t pos) {
    size_t occurrence = text.find(keyword, pos);
    if (occurrence == string::npos) {
        return string::npos;
    } else {
        if (occurrence == 0 && occurrence + keyword.length() == text.length()) {
            return occurrence;
        } else if (occurrence == 0 && text.at(occurrence + keyword.length()) == ' ') {
            return occurrence;
        } else if (text.at(occurrence-1) == ' ' &&  occurrence + keyword.length() == text.length()) {
            return occurrence;
        } else if (text.at(occurrence-1) == ' ' && text.at(occurrence + keyword.length()) == ' ') {
            return occurrence;
        } else {
            return find_keyword(keyword, text, occurrence+1);
        }
    }
}