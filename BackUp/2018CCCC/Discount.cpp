#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double a, b;
    cin >> a >> b;
    cout.setf(ios::fixed);

    cout << fixed << setprecision(2) << a * b / 10 << endl;

    return 0;
}