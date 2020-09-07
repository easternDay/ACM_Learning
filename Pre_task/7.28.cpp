#include <bits/stdc++.h>

using namespace std;

set<int> s[50];

int main()
{
    int m, n, k;
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> k;
        for (int j = 1; j <= k; j++)
        {
            cin >> n;
            s[i].insert(n);
        }
    }
    cin >> n;
    int i, j;
    while (n--)
    {
        cin >> i >> j;
        //cout << s[i].size() << endl << s[j].size() << endl;
        int u = s[i].size() + s[j].size();
        set<int> tmp;
        tmp.insert(s[i].begin(), s[i].end());
        tmp.insert(s[j].begin(), s[j].end());
        int c = u - tmp.size();
        double ans = (double)c / (double)(tmp.size());
        cout << setiosflags(ios::fixed) << setprecision(2) << ans * 100 << "%";
        if (n)
        {
            cout << endl;
        }
    }

    return 0;
}