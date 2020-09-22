#include <iostream>
#include <set>
using namespace std;

typedef struct parent
{
    short int father;
    short int mother;
    char sex;
} parent;

parent p[99999];
int n, id, ide;

set<short int> s;

bool Test(set<short int> &s, int parent1, int parent2, int deep = 0)
{
    int count = s.size();
    if (deep > 4 || (parent1 == -1 && parent2 == -1))
    {
        return true;
    }
    int i = -1, j = -1, k = -1, l = -1;
    if (parent1 != -1)
    {
        s.insert(parent1);
        if (count == s.size())
        {
            return false;
        }
        else
        {
            i = p[parent1].father;
            j = p[parent1].mother;
        }
    }
    count = s.size();
    if (parent2 != -1)
    {
        s.insert(parent2);
        if (count == s.size())
        {
            return false;
        }
        else
        {
            k = p[parent2].father;
            l = p[parent2].mother;
        }
    }

    int flag = Test(s, i, k, deep + 1);
    int flag2 = Test(s, j, l, deep + 1);
    return flag && flag2;
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
