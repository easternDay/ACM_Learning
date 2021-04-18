#include <bits/stdc++.h>

using namespace std;

typedef struct RedPaper
{
    float total;
    int num;
    int pla;

    bool operator<(const RedPaper &rp) const
    {
        if (total == rp.total)
        {
            return num < rp.num;
        }
        return total < rp.total;
    }
    bool operator>(const RedPaper &rp) const
    {
        if (total == rp.total)
        {
            return num > rp.num;
        }
        return total > rp.total;
    }
} RedPaper;

int n;
vector<RedPaper> rp;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        RedPaper r;
        r.num = 0;
        r.total = 0;
        rp.push_back(r);
    }
    int num, pla, money;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        rp[i].pla = i + 1;
        for (int j = 0; j < num; j++)
        {
            cin >> pla >> money;
            rp[i].total -= money;
            rp[pla - 1].total += money;
            rp[pla - 1].num++;
        }
    }

    sort(rp.begin(), rp.end(), greater<RedPaper>());

    for (int i = 0; i < rp.size(); i++)
    {
        cout << rp[i].pla << " " << setiosflags(ios::fixed) << setprecision(2) << rp[i].total / 100 << endl;
    }

    return 0;
}