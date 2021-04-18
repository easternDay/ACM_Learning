#include <bits/stdc++.h>
using namespace std;
int p[1001], per[1001];
int people[1000][1001] = {0};
int FindFather(int x)
{
    if (x == p[x])
    {
        return x;
    }
    return x = FindFather(p[x]);
}
void Union(int x, int y)
{
    int xF = FindFather(x);
    int yF = FindFather(y);
    if (xF != yF)
    {
        p[yF] = xF;
    }
}
int main()
{
    for (int i = 0; i < 1001; i++)
    {
        p[i] = i;
        per[i] = 0;
    }
    int n, q, r;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> people[i][0];
        getchar();
        cin >> people[i][1];
        for (int j = 1; j < people[i][0]; j++)
        {
            cin >> people[i][j + 1];
            Union(people[i][1], people[i][j + 1]);
        }
    }
    set<int> sc;
    sc.clear();
    for (int i = 0; i < n; i++)
    {
        people[i][0] = FindFather(people[i][1]);
        sc.insert(people[i][0]);
        per[people[i][0]]++;
    }
    cout << sc.size() << endl;
    sort(per, per + 1001);
    for (int i = 1000; per[i] != 0; i--)
    {
        if (i != 1000)
        {
            cout << " ";
        }
        cout << per[i];
    }

    return 0;
}