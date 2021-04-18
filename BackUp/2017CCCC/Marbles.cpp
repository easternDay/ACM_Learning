#include <bits/stdc++.h>
using namespace std;
int main()
{
    double w, p, v2, smax = 0;
    scanf("%lf%lf", &w, &p);
    v2 = 2 * 1000 * 100 / w;
    while (v2 > 0.000001)
    {
        smax += v2 / 9.8;
        v2 *= 1 - p / 100;
    }
    printf("%.3f\n", smax);

    return 0;
}