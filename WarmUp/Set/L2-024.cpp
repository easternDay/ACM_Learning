#include <bits/stdc++.h>

using namespace std;

set<int> sc;
int n, k, p, temp;
int q[10001];

int FindFather(int x)
{
    if (x != q[x])
    {
        return q[x] = FindFather(q[x]);
    }
    return x;
}

void TryUnion(int a, int b)
{
    int aF = FindFather(a);
    int bF = FindFather(b);
    if (aF != bF)
    {
        q[bF] = aF;
    }
}

int main()
{
    sc.clear();
    //输入总数目
    cin >> n;
    for (int i = 0; i < 10001; i++)
    {
        q[i] = i;
    }
    //遍历
    for (int i = 0; i < n; i++)
    {
        //输入每个圈子中的人数
        cin >> k;
        if (k > 0)
        {
            cin >> p;
            sc.insert(p);
        }
        for (int j = 1; j < k; j++)
        {
            cin >> temp;
            sc.insert(temp);
            TryUnion(p, temp);
        }
    }

    cout << sc.size() << " ";
    set<int> s;
    s.clear();
    for (set<int>::iterator it = sc.begin(); it != sc.end(); it++)
    {
        s.insert(FindFather(*it));
    }
    cout << s.size() << endl;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> k >> p;
        if (FindFather(k) == FindFather(p))
        {
            cout << "Y" << endl;
        }
        else
        {
            cout << "N" << endl;
        }
    }

    return 0;
}