#include <bits/stdc++.h>
using namespace std;

typedef struct
{
    string name;
    int num;
    set<int> like;
} Role;

int main()
{
    Role r[100];
    int n;
    cin >> n;
    if (n == 0)
    {
        cout << "- - -";
        return 0;
    }
    bool *b = new bool[n];
    for (int i = 0; i < n; i++)
    {
        cin >> r[i].name;
        cin >> r[i].num;
        int k;
        for (int j = 0; j < r[i].num; j++)
        {
            cin >> k;
            r[i].like.insert(k);
        }
        b[i] = false;
    }

    queue<Role> s;
    int pla;
    Role max = r[0];
    bool flag;

    while (s.size() != 3)
    {
        flag = true;
        for (int i = 0; i < n; i++)
        {
            if (!b[i])
            {
                max = r[i];
                pla = i;
                flag = false;
                break;
            }
        }
        if (flag)
        {
            break;
        }
        for (int i = 0; i < n; i++)
        {
            if (!b[i] &&
                ((max.like.size() == r[i].like.size() && r[i].num < max.num) ||
                 max.like.size() < r[i].like.size()))
            {
                flag = true;
                max = r[i];
                pla = i;
                flag = true;
            }
        }
        b[pla] = true;
        s.push(r[pla]);
    }

    string out = "";
    int count = 0;
    while (!s.empty())
    {
        count++;
        out += s.front().name;
        s.pop();
        if (count != 3)
        {
            out += " ";
        }
    }
    if (count == 2)
    {
        out += "-";
    }
    if (count == 1)
    {
        out += "- -";
    }

    cout << out;

    return 0;
}