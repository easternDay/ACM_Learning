#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, M, K;
    cin >> N >> M >> K;
    while (K--)
    {
        stack<int> S;
        int p = 1;
        bool flag = true;
        for (int i = 0; i < N; i++)
        {
            int j;
            cin >> j;

            S.push(j);

            while (!S.empty() && S.top() == p)
            {
                p++;
                S.pop();
            }

            if (S.size() > M)
            {
                flag = false;
            }
        }
        if (flag && S.empty())
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }
        if (K != 0)
        {
            cout << endl;
        }
    }
    return 0;
}