#include <bits/stdc++.h>

using namespace std;

char c;
int total[10];

int main()
{
    for (int i = 0; i < 10; i++)
    {
        total[i] = 0;
    }
    while ((c = getchar()) != '\0')
    {
        if (c < '0' || c > '9')
        {
            break;
        }
        total[c - '0']++;
    }
    for (int i = 0; i < 10; i++)
    {
        if (total[i] != 0)
        {
            cout << i << ":" << total[i] << endl;
        }
    }
    return 0;
}