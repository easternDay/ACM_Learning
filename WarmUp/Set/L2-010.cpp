#include <bits/stdc++.h>

using namespace std;

int *friendShip;
int badShip[101][101];

//找爸爸
int FindFather(int *ship, int x)
{
    if (x == ship[x])
    {
        return x;
    }
    return ship[x] = FindFather(ship, ship[x]);
}

//合并
void Union(int *ship, int p, int q)
{
    int pF = FindFather(ship, p);
    int qF = FindFather(ship, q);
    if (pF != qF)
    {
        ship[qF] = pF;
    }
}

int main()
{
    //N为总人数，M为关系树
    int n, m, k;
    //读取人数
    cin >> n >> m >> k;
    //初始化数组
    friendShip = new int[n + 1];
    //badShip = new int[n + 1];
    //设置所有节点父节点为自己
    for (int i = 0; i <= n; i++)
    {
        friendShip[i] = i;
        for (int j = 0; j <= n; j++)
        {
            badShip[i][j] = 0;
        }
    }
    //读取关系
    int p, q, r;
    for (int i = 0; i < m; i++)
    {
        cin >> p >> q >> r;
        if (r == 1)
        {
            Union(friendShip, p, q);
        }
        else
        {
            //Union(badShip, p, q);
            badShip[p][q] = 1;
            badShip[q][p] = 1;
        }
    }
    //判断关系并输出
    for (int i = 0; i < k; i++)
    {
        cin >> p >> q;
        bool isFriend = FindFather(friendShip, p) == FindFather(friendShip, q) ? true : false;
        //bool isBad = FindFather(badShip, p) == FindFather(badShip, q) ? true : false;
        bool isBad = badShip[p][q] == 1 ? true : false;
        if (isFriend && !isBad)
        {
            cout << "No problem" << endl;
        }
        if (!isFriend && !isBad)
        {
            cout << "OK" << endl;
        }
        if (isFriend && isBad)
        {
            cout << "OK but..." << endl;
        }
        if (!isFriend && isBad)
        {
            cout << "No way" << endl;
        }
    }

    return 0;
}