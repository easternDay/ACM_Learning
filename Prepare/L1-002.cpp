#include <bits/stdc++.h>

using namespace std;

int main()
{
    char c;
    int degree, left, n;

    cin >> n >> c;

    left = n - 1;
    degree = 3;

    while (left > degree * 2)
    {
        left -= degree * 2;
        degree += 2;
    }
    degree -= 2;

    int space = 0, startDegree = degree, isTr = false;
    while (true)
    {
        if (isTr && startDegree - 2 == degree)
        {
            break;
        }
        for (int i = 0; i < space; i++)
        {
            cout << " ";
        }
        space = isTr ? space - 1 : space + 1;
        for (int i = 0; i < startDegree; i++)
        {
            cout << c;
        }
        startDegree = isTr ? startDegree + 2 : startDegree - 2;
        if (startDegree == 1)
        {
            isTr = true;
        }
        cout << endl;
        if (degree == 1)
        {
            break;
        }
    }
    cout << left;

    return 0;
}