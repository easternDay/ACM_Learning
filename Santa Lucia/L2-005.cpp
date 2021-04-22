/*
给定两个整数集合，它们的相似度定义为：N
​c
​​ /N
​t
​​ ×100%。其中N
​c
​​ 是两个集合都有的不相等整数的个数，N
​t
​​ 是两个集合一共有的不相等整数的个数。你的任务就是计算任意一对给定集合的相似度。

输入格式：
输入第一行给出一个正整数N（≤50），是集合的个数。随后N行，每行对应一个集合。每个集合首先给出一个正整数M（≤10
​4
​​ ），是集合中元素的个数；然后跟M个[0,10
​9
​​ ]区间内的整数。

之后一行给出一个正整数K（≤2000），随后K行，每行对应一对需要计算相似度的集合的编号（集合从1到N编号）。数字间以空格分隔。

输出格式：
对每一对需要计算的集合，在一行中输出它们的相似度，为保留小数点后2位的百分比数字。

输入样例：
3
3 99 87 101
4 87 101 5 87
7 99 101 18 5 135 18 99
2
1 2
1 3
输出样例：
50.00%
33.33%
*/
#include <bits/stdc++.h>
using namespace std;

vector<set<int>> vec;

int main()
{
    int n, cnt, input, key;
    cin >> n;
    vec.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> cnt;
        while (cnt--)
        {
            cin >> key;
            vec[i].insert(key);
        }
    }

    cin >> n;
    int p, q, nc, nt;
    while (n--)
    {
        cin >> p >> q;
        p--;
        q--;
        nc = vec[p].size() + vec[q].size();
        set<int> s;
        for (auto iter = vec[p].begin(); iter != vec[p].end(); iter++)
        {
            s.insert(*iter);
        }
        for (auto iter = vec[q].begin(); iter != vec[q].end(); iter++)
        {
            s.insert(*iter);
        }
        nt = s.size();
        nc = nc-nt;
        cout << setiosflags(ios::fixed) << setprecision(2) << (float)nc / nt * 100 << "%" << endl;
    }

    return 0;
}