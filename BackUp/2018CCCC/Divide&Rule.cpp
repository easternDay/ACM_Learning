#include <bits/stdc++.h>

using namespace std;
bool text[10000 + 2];
int tx, px;

void solve()
{
    pair<int, int> P[10000 + 2];
    
    scanf("%d%d", &tx, &px);
    for (int i = 0; i < px; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        P[i] = {x, y};
    }

    int tcx;
    scanf("%d", &tcx);
    for (int i = tcx; i--;)
    {
        int apx;
        scanf("%d", &apx);
        memset(text, 1, sizeof(text));
        for (int j = apx; j--;)
        {
            int xc;
            scanf("%d", &xc);
            text[xc] = 0;
        }
        bool tecc;
        for (int n = 0; n < px; n++)
        {

            if (text[P[n].first] && text[P[n].second])
                tecc = false, n = px;
            else
                tecc = true;
        }
        if (tecc)
            printf("YES\n");
        else
            printf("NO\n");
    }
}

int main()
{
    solve();
    return 0;
}