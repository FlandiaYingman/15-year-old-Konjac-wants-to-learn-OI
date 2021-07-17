//P1093 奖学金
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct student
{
    int student_id;
    int chinese;
    int mathematics;
    int english;

    int total()
    {
        return chinese + mathematics + english;
    }

    static bool comp(student &a, student &b)
    {
        if (a.total() == b.total() && a.chinese == b.chinese)
        {
            return a.student_id < b.student_id;
        }
        else if (a.total() == b.total())
        {
            return a.chinese > b.chinese;
        }
        else
        {
            return a.total() > b.total();
        }
    }
};

int main()
{
    int student_count;
    cin >> student_count;
    vector<student> students;
    for (int i = 1; i <= student_count; i++)
    {
        int c, m, e;
        cin >> c >> m >> e;
        student s = *new student();
        s.student_id = i;
        s.chinese = c;
        s.mathematics = m;
        s.english = e;
        students.push_back(s);
    }

    sort(students.begin(), students.end(), student::comp);

    for (int i =0; i < 5; i++) {
        cout << students[i].student_id << " " << students[i].total() << endl;
    }
}