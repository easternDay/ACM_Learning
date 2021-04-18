#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

const int maxn = 100005;
int degree[maxn];
vector<int> v[maxn];
queue<int> q;
int n, k;

int main()
{
    int i;
    int x;
    while (cin >> n)
    {
        for (i = 0; i < maxn; i++)
            v[i].clear();

        while (q.size())
            q.pop();

        memset(degree, 0, sizeof(degree));

        for (i = 1; i <= n; i++)
        {
            scanf("%d", &k);
            while (k--)
            {
                scanf("%d", &x);
                degree[x]++;
                v[i].push_back(x);
            }
        }
        x = 1;
        for (i = 1; i <= n; i++)
        {
            if (degree[i] == 0)
            {
                x = i;
                break;
            }
        }
        
        q.push(x);
        while (q.size())
        {
            x = q.front();
            q.pop();
            for (i = 0; i < v[x].size(); i++)
                q.push(v[x][i]);
        }
        cout << x << endl;
    }
    return 0;
}