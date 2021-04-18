#include <iostream>
using namespace std;

int main()
{
    int Characters[1000] = {0};
    int n, c, tmp;
    cin >> n;
    while (n--)
    {
        cin >> c;
        while (c--)
        {
            cin >> tmp;
            Characters[tmp - 1]++;
        }
    }
    int max = 0;
    for (int i = 1; i < 1000; i++)
    {
        if (Characters[i] >= Characters[max])
        {
            max = i;
        }
    }
    cout << max + 1
     << " " << Characters[max];

    return 0;
}