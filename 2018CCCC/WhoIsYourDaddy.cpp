#include <iostream>

using namespace std;

int main()
{
    int a, b, a1 = 0, b1 = 0, x;
    cin >> a >> b;
    for (int i = 0; i < 3; i++)
    {
        cin >> x;
        if (x == 1)
            b1++;
        else
            a1++;
    }
    if (a > b && a1 > 0)
        cout << "The winner is a: " << a << " + " << a1;
    else
        cout << "The winner is b: " << b << " + " << b1;
    return 0;
}