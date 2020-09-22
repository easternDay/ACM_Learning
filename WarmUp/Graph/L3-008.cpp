#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n, m, k;
vector<int> vc[10001];
set<int> sc;

void DFS(int root, int lastSize, int &maxDep, int &ret, int deep = 0)
{
    sc.insert(root);
    if (sc.size() == lastSize)
    {
        return;
    }
    if (deep > maxDep)
    {
        maxDep = deep;
        ret = root;
    }
    else if (deep == maxDep && ret > root)
    {
        ret = root;
    }
    for (int i = 0; i < vc[root].size(); i++)
    {
        DFS(vc[root][i], sc.size(), maxDep, ret, deep + 1);
    }
    sc.erase(sc.find(root));
}

int main()
{
    cin >> n >> m >> k;

    int p, q;
    for (int i = 0; i < m; i++)
    {
        cin >> p >> q;
        vc[p].push_back(q);
        vc[q].push_back(p);
    }
    for (int i = 0; i < k; i++)
    {
        cin >> p;
        int maxDep = 0, ret = 99999;
        sc.clear();
        DFS(p, sc.size(), maxDep, ret);
        ret = ret == p ? 0 : ret;
        cout << ret << endl;
    }

    return 0;
}