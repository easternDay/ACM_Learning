#include <bits/stdc++.h>

using namespace std;

int n;
vector<double> vec;

int main()
{
    cin >> n;
    double j;
    for (int i = 0; i < n; i++)
    {
        cin >> j;
        vec.push_back(j);
    }
    sort(vec.begin(), vec.end());

    double min, max;
    j = 0;
    double d = 0, val = min;
    if (n % 2 == 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (i < n / 2)
            {
                j += vec[i];
            }
            else
            {
                j -= vec[i];
            }
        }
        j = abs(j);
        cout << "Outgoing #: " << n / 2 << endl;
        cout << "Introverted #: " << n / 2 << endl;
        cout << "Diff = " << j;
    }
    else
    {
        min = vec[n / 2] - 1;
        max = vec[n / 2] + 1;
        int minnum, temp;
        while (min <= max)
        {
            temp = 0;
            for (int i = 0; i <= n; i++)
            {
                if (vec[i] < min)
                {
                    temp++;
                    j += vec[i];
                }
                else
                {
                    j -= vec[i];
                }
            }
            j = abs(j);
            if (j > d)
            {
                d = j;
                val = min;
                minnum = temp;
            }
            min++;
        }
        cout << "Outgoing #: " << minnum << endl;
        cout << "Introverted #: " << n - minnum << endl;
        cout << "Diff = " << d;
    }

    return 0;
}