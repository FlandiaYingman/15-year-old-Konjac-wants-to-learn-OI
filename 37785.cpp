//T37785 Oier们的烦恼(worries)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool came_A = false;
bool came_B = false;
bool came_C = false;

bool playing_A = false;
bool playing_B = false;
bool playing_C = false;
bool playing_D = false;
bool playing_E = false;

bool died_A = false;
bool died_B = false;
bool died_C = false;
bool died_D = false;
bool died_E = false;

inline bool has_teacher_came() {
    return came_A || came_B || came_C;
}

inline void teacher_kill_students() {
    if (playing_A) {
        died_A = true;
    }
    if (playing_B) {
        died_B = true;
    }
    if (playing_C) {
        died_C = true;
    }
    if (playing_D) {
        died_D = true;
    }
    if (playing_E) {
        died_E = true;
    }
}

int main() {
    int message_count;
    cin >> message_count;

    string teacher_A;
    string teacher_B;
    string teacher_C;
    cin >> teacher_A >> teacher_B >> teacher_C;

    string student_A;
    string student_B;
    string student_C;
    string student_D;
    string student_E;
    cin >> student_A >> student_B >> student_C >> student_D >> student_E;

    string thisLine;
    for (int i = 0; i < message_count; i++) {
        getline(cin, thisLine);
        if (thisLine == student_A + " started playing games!") {
            playing_A = true;
            if (has_teacher_came()) {
                died_A = true;
            }
        } else if (thisLine == student_B + " started playing games!") {
            playing_B = true;
            if (has_teacher_came()) {
                died_B = true;
            }
        } else if (thisLine == student_C + " started playing games!") {
            playing_C = true;
            if (has_teacher_came()) {
                died_C = true;
            }
        } else if (thisLine == student_D + " started playing games!") {
            playing_D = true;
            if (has_teacher_came()) {
                died_D = true;
            }
        } else if (thisLine == student_E + " started playing games!") {
            playing_E = true;
            if (has_teacher_came()) {
                died_E = true;
            }
        } else if (thisLine == student_A + " stopped playing games!") {
            playing_A = false;
        } else if (thisLine == student_B + " stopped playing games!") {
            playing_B = false;
        } else if (thisLine == student_C + " stopped playing games!") {
            playing_C = false;
        } else if (thisLine == student_D + " stopped playing games!") {
            playing_D = false;
        } else if (thisLine == student_E + " stopped playing games!") {
            playing_E = false;
        } else if (thisLine == teacher_A + " came!") {
            came_A = true;
            teacher_kill_students();
        } else if (thisLine == teacher_B + " came!") {
            came_B = true;
            teacher_kill_students();
        } else if (thisLine == teacher_C + " came!") {
            came_C = true;
            teacher_kill_students();
        } else if (thisLine == teacher_A + " left!") {
            came_A = false;
        } else if (thisLine == teacher_B + " left!") {
            came_B = false;
        } else if (thisLine == teacher_C + " left!") {
            came_C = false;
        }
    }

    vector<string> died_names;
    if (died_A) {
        died_names.push_back(student_A);
    }
    if (died_B) {
        died_names.push_back(student_B);
    }
    if (died_C) {
        died_names.push_back(student_C);
    }
    if (died_D) {
        died_names.push_back(student_D);
    }
    if (died_E) {
        died_names.push_back(student_E);
    }

    sort(died_names.begin(), died_names.end());

    if (died_names.empty()) {
        cout << "How Good Oiers Are!";
    } else {
        for (int i = 0; i < died_names.size(); i++) {
            cout << died_names[i] << " ";
        }
        cout << endl;
        if (died_names.size() == 5) {
            cout << "How Bad Oiers Are!";
        }
    }

    return 0;
}