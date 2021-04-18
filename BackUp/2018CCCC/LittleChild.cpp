#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 10;
vector<int> v[maxn];
vector<int> f[maxn];
int n, x;
int high;
int parent;
void bfs()
{
    queue<int> q;
    q.push(parent);
    high = 0;
    f[high].push_back(parent);

    while (!q.empty())
    {

        int sum = q.size();
        high++;
        for (int i = 0; i < sum; i++)
        {
            int head = q.front();
            q.pop();
            for (int j = 0; j < v[head].size(); j++)
            {
                f[high].push_back(v[head][j]);
                q.push(v[head][j]);
            }
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &x);
        if (x > 0)
            v[x].push_back(i);
        else
            parent = i;
    }
    bfs();
    cout << high << endl;
    for (int i = 0; i < f[high - 1].size(); i++)
    {
        if (i != 0)
            printf(" ");

        printf("%d", f[high - 1][i]);
    }
    cout << endl;
    return 0;
}