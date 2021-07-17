//P1583 魔法照片
#include <iostream>
#include <algorithm>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::sort;
using std::vector;

struct person
{
    int weight;
    int number;
    int order_number;
    int class_number;

    static bool compare_weight(const person &a, const person &b)
    {
        if (a.weight != b.weight)
        {
            return a.weight > b.weight;
        }
        return a.number < b.number;
    }
};

int main()
{
    int e[11];
    person persons[20001];
    int person_count, photo_count;

    cin >> person_count >> photo_count;

    for (int i = 1; i <= 10; i++)
    {
        cin >> e[i];
    }

    for (int i = 1; i <= person_count; i++)
    {
        person *p = new person;
        p->number = i;
        cin >> p->weight;
        persons[i] = *p;
    }

    sort(persons + 1, persons + person_count + 1, person::compare_weight);

    for (int i = 1; i <= person_count; i++)
    {
        persons[i].order_number = i;
        persons[i].class_number = (i-1) % 10 +1;
        persons[i].weight += e[persons[i].class_number];
    }

    sort(persons + 1, persons + person_count + 1, person::compare_weight);

    for (int i = 1; i <= photo_count; i++)
    {
        cout << persons[i].number << " ";
    }
}
