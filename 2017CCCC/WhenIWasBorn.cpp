#include <bits/stdc++.h>

using namespace std;

int main()
{
    int born, different;
    cin >> born >> different;

    int Re[10] = {0}, i, x = 0, r;
    while (true)
    {
        for (i = 0; i < 10; i++)
        {
            Re[i] = 0;
        }
        Re[born % 10]++;
        Re[(born / 10) % 10]++;
        Re[(born / 100) % 10]++;
        Re[(born / 1000) % 10]++;
        for (i = 0, r = 0; i < 10; i++)
        {
            if (Re[i])
            {
                r++;
            }
        }
        if (r == different)
        {
            break;
        }
        x++;
        born++;
    }
    cout << x << " " << setw(4) << setfill('0') << born;
    return 0;
}