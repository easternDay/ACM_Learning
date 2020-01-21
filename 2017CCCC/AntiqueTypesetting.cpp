#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, len = 0, i, j;
    char s[1100];

    cin >> n;
    getchar();

    while ((s[len] = getchar()) != '\n')
    {
        len++;
    }
    n = n;
    while (len % n != 0)
    {
        s[len++] = ' ';
    }
    for (i = 0; i < n; i++)
    {
        for (j = len / n - 1; j >= 0; j--)
        {
            cout << s[j * n + i];
        }
        cout << endl;
    }

    return 0;
}