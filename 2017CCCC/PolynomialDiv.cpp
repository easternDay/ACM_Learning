/* LittleFall : Hello! */
#include <bits/stdc++.h>
#define ll long long
using namespace std;
inline int read();
inline void write(int x);
const int M = 100016;
double A[M], B[M];

void print(vector<pair<int, double>> &ans)
{
    printf("%d", ans.size());
    if (ans.size() == 0)
        printf(" 0 0.0");
    for (auto x : ans)
        printf(" %d %.1f", x.first, x.second);
    printf("\n");
}
int main(void)
{
#ifdef _LITTLEFALL_
    freopen("in.txt", "r", stdin);
#endif
    //std::cin.sync_with_stdio(false);

    int la = read(), na = -1, lb, nb = -1;
    if (la == 0)
        scanf("%*d%*f");
    for (int i = 0; i < la; ++i)
    {
        int t = read();
        na = max(na, t);
        A[t] = read();
    }
    lb = read();
    if (lb == 0)
        scanf("%*d%*f");
    for (int i = 0; i < lb; ++i)
    {
        int t = read();
        nb = max(nb, t);
        B[t] = read();
    }
    vector<pair<int, double>> divide, reminder;
    while (na >= nb)
    {
        double x = (double)A[na] / B[nb];
        if (abs(x) > 0.05)
            divide.push_back({na - nb, x});
        for (int i = nb; i >= 0; --i)
            A[na - nb + i] -= x * B[i];
        --na;
    }
    for (int i = na; i >= 0; --i)
        if (abs(A[i]) > 0.05)
            reminder.push_back({i, A[i]});
    print(divide);
    print(reminder);
    return 0;
}

inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
inline void write(int x)
{
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
}