#include <bits/stdc++.h>

using namespace std;

int length = 0;
int icount = 0;

int print6()
{
    if (icount > 9)
    {
        cout << 27;
    }
    else if (icount > 3)
    {
        cout << 9;
    }
    else
    {
        while (icount--)
        {
            cout << 6;
        }
    }
}

int main()
{
    string s;
    getline(cin, s);
    char c;
    //读取输入
    while (length < s.size())
    {
        c = s[length];

        if (c == '6')
        {
            icount++;
        }
        else
        {
            print6();
            icount = 0;

            cout << c;
        }

        length++;
    }
    print6();
    return 0;
}