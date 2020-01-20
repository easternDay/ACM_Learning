#include <iostream>
#include <string>
using namespace std;

int main()
{
    string tmp, first;
    int n = 0;
    while (true)
    {
        cin >> tmp;
        if (tmp != ".")
        {
            if (++n == 2)
            {
                first = tmp;
            }
            else if (n == 14)
            {
                cout << first << " and " << tmp << " are inviting you to dinner...";
                break;
            }
        }
        else
        {
            if (n >= 2)
            {
                cout << first << " is the only one for you...";
            }
            else
            {
                cout << "Momo... No one is for you ...";
            }
            break;
        }
    }

    return 0;
}