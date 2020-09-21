#include <iostream>
#include <vector>
#include <set>

using namespace std;

int maxDep = 0;
vector<int> st[100001];
set<int> sc;

void DFS(int root, int deep = 0)
{
    if (st[root].size() == 0)
    {
        if (maxDep == deep)
        {
            sc.insert(root);
        }
        else if (maxDep < deep)
        {
            maxDep = deep;
            sc.clear();
            sc.insert(root);
        }
    }
    for (int i = 0; i < st[root].size(); i++)
    {
        DFS(st[root][i], deep + 1);
    }
}

int main()
{
    int n, p, root;
    cin >> n;
    sc.clear();
    for (int i = 1; i <= n; i++)
    {
        cin >> p;
        if (p == -1)
        {
            root = i;
        }
        else
        {
            st[p].push_back(i);
        }
    }
    DFS(root);
    cout << maxDep + 1 << endl;
    for (auto it = sc.begin(); it != sc.end(); it++)
    {
        cout << *it;
        it++;
        if (it != sc.end())
        {
            cout << " ";
        }
        it--;
    }

    return 0;
}