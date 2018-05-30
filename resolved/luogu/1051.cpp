//P1051 谁拿了最多奖学金
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::istringstream;
using std::sort;
using std::string;
using std::vector;

struct student
{
    int number;
    string name;
    int scholarship;

    int paper_count;
    int final_average_grade;
    int class_assessment_grade;

    char western_province;
    char leader;

    student(string str, int number)
    {
        istringstream ss(str);
        this->number = number;
        ss >> this->name;
        ss >> this->final_average_grade;
        ss >> this->class_assessment_grade;
        ss >> this->leader;
        ss >> this->western_province;
        ss >> this->paper_count;
        setup_scholarship();
    }

    void setup_scholarship()
    {
        this->scholarship = 0;
        if (final_average_grade > 80 && paper_count >= 1)
        {
            this->scholarship += 8000;
        }
        if (final_average_grade > 85 && class_assessment_grade > 80)
        {
            this->scholarship += 4000;
        }
        if (final_average_grade > 90)
        {
            this->scholarship += 2000;
        }
        if (final_average_grade > 85 && western_province == 'Y')
        {
            this->scholarship += 1000;
        }
        if (class_assessment_grade > 80 && leader == 'Y')
        {
            this->scholarship += 850;
        }
    }

    static bool comp(const student *a, const student *b)
    {
        if (a->scholarship != b->scholarship)
        {
            return a->scholarship > b->scholarship;
        }
        return a->number < b->number;
    }
};

int main()
{
    int student_count;
    cin >> student_count;
    cin.get();
    cin.get(); //Magic cin.get();

    vector<student*> students;
    for (int i = 0; i < student_count; i++)
    {
        string str;
        getline(cin, str);
        //cout << str ;
        //cout << i << endl;

        student *stu = new student(str, i);
        students.push_back(stu);
    }

    sort(students.begin(), students.end(), student::comp);

    int sum = 0;
    for (int i = 0; i < students.size(); i++)
    {
        //cout << "add " << students[i]->scholarship << ", name " << students[i]->name << endl;
        sum += students[i]->scholarship;
    }

    cout << students[0]->name << endl
         << students[0]->scholarship << endl
         << sum;
}
