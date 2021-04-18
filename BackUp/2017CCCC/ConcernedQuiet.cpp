#include <iostream>
#include <set>
#include <map>
#include <string>
using namespace std;
set<string> s;
map<string, int> p, pp;
int main()
{
    int i, n, m, sum = 0, t;
    string name, a[10001];
    cin >> n;
    while (n--)
    {
        cin >> name;
        p[name] = 1;
    }
    cin >> m;
    for (i = 0; i < m; i++)
    {
        cin >> a[i] >> t;
        pp[a[i]] = t;
        sum = sum + t;
    }
    sum = sum / m;
    for (i = 0; i < m; i++)
    {
        if (p[a[i]] == 0 && pp[a[i]] > sum)
            s.insert(a[i]);
    }
    if (s.empty())
    {
        puts("Bing Mei You");
        return 0;
    }
    set<string>::iterator it;
    for (it = s.begin(); it != s.end(); it++)
        cout << *it << endl;
    return 0;
}