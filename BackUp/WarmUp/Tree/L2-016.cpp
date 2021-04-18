#include <iostream>
#include <set>
using namespace std;

typedef struct parent
{
    int father;
    int mother;
    char sex;
} parent;

parent p[99999];
int n, id, ide;

set<int> s;

bool Test(set<int> &s, int parent1, int parent2, int deep = 0)
{
    if (deep > 3 || parent1 == -1 || parent2 == -1)
    {
        return true;
    }
    if ((p[parent1].father != -1 && p[parent1].father == p[parent2].father) || (p[parent1].mother != -1 && p[parent1].mother == p[parent2].mother))
    {
        return false;
    }

    return Test(s, p[parent1].father, p[parent2].father, deep + 1) && Test(s, p[parent1].father, p[parent2].mother, deep + 1) && Test(s, p[parent1].mother, p[parent2].father, deep + 1) && Test(s, p[parent1].mother, p[parent2].mother, deep + 1);
}

int main()
{
    for (int i = 0; i < 99999; i++)
    {
        p[i].father = -1;
        p[i].mother = -1;
        p[i].sex = -1;
    }

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> id;
        getchar();
        p[id].sex = getchar();
        cin >> p[id].father >> p[id].mother;
        if (p[id].father != -1)
            p[p[id].father].sex = 'M';
        if (p[id].mother != -1)
            p[p[id].mother].sex = 'F';
    }

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> id >> ide;
        if (p[id].sex == p[ide].sex)
        {
            cout << "Never Mind" << endl;
        }
        else
        {
            s.clear();
            if (Test(s, id, ide))
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
    }

    return 0;
}
