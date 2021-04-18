#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int a[100010];
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n);
    int sum1 = 0, sum2 = 0, j = 0, x = n / 2, y = n / 2;
    if (n % 2)
    {
        j = 1;
        sum2 += a[n / 2];
        x++;
    }

    for (int i = 0; i < n / 2; i++, j++)
    {
        sum1 += a[i];
        sum2 += a[j + n / 2];
    }
    printf("Outgoing #: %d\nIntroverted #: %d\nDiff = %d\n", x, y, sum2 - sum1);
    return 0;
}
