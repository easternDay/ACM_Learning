#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5005;

int n;
struct point //存储点
{
    ll x, y;
} p[N], c[N];

bool cmp(point a, point b) //按顺时针排序
{
    return b.y * a.x > b.x * a.y;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%lld%lld", &p[i].x, &p[i].y);
    ll ans = 1e18;
    for (int i = 0; i < n; i++)
    {
        int k = 0;
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                c[k].x = p[j].x - p[i].x;
                c[k].y = p[j].y - p[i].y;
                k++;
            }
        }
        sort(c, c + k, cmp);
        for (int j = 1; j < k; j++)
            ans = min(ans, abs(c[j].y * c[j - 1].x - c[j].x * c[j - 1].y));
    }
    printf("%.3f\n", ans / 2.);
    return 0;
}