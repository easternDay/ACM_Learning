//有瑕疵的L2-013
#include <bits/stdc++.h>

using namespace std;

int *city;
int n, m, k;

//合并
void Union(int p, int q)
{
    city[q] = p;
}

int main()
{
    cin >> n >> m;
    int count = 0;
    city = new int[n];
    int p, q;
    for (int i = 0; i < m; i++)
    {
        city[i] = i;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> p >> q;
        Union(p, q);
        count++;
    }
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int path = 0;
        cin >> m;
        for (int j = 0; j < n; j++)
        {
            if (j != m && city[j] == m)
            {
                path++;
                city[j] = j;
            }
        }
        if (city[m] != m)
        {
            city[m] = m;
            path++;
        }
        if (count > 1 && path > count - 1 && !flag)
        {
            cout << "Red Alert: City " << m << " is lost!" << endl;
        }
        else
        {
            cout << "City " << m << " is lost." << endl;
        }
        if (i == k - 1)
        {
            cout << "Game Over." << endl;
        }
        count -= path;
    }
    return 0;
}