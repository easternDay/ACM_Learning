#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num;
    cin >> num;

    string tmp;

    map<string, bool> name;
    for (int i = 0; i < num; i++)
    {
        cin >> tmp;
        name[tmp] = true;
    }

    int n;
    cin >> n;

    map<string, int> role;
    int totalLike = 0;
    for (int i = 0; i < n; i++)
    {
        int like;
        cin >> tmp >> like;
        if (name[tmp]==0)
        {
            role[tmp] = like;
        }
        totalLike += like;
    }
    totalLike /= n;
    map<string, int>::iterator it;
    bool flag = false;
    for (it = role.begin(); it != role.end(); it++)
    {
        if (it->second > totalLike)
        {
            flag = true;
            cout << it->first << endl;
        }
    }
    if (!flag)
    {
        cout << "Bing Mei You" << endl;
    }
    return 0;
}