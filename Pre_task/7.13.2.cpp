#include <bits/stdc++.h>

using namespace std;

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
    char c;
    //读取输入
    while ((c = getchar()) != '\n')
    {
        if (c == '6')
        {
            icount++;
        }
        else
        {
            print6();
            cout << c;
            icount = 0;
        }
    }
    print6();
    
    return 0;
}
