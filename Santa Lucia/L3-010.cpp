/*
将一系列给定数字顺序插入一个初始为空的二叉搜索树（定义为左子树键值大，右子树键值小），你需要判断最后的树是否一棵完全二叉树，并且给出其层序遍历的结果。

输入格式：
输入第一行给出一个不超过20的正整数N；第二行给出N个互不相同的正整数，其间以空格分隔。

输出格式：
将输入的N个正整数顺序插入一个初始为空的二叉搜索树。在第一行中输出结果树的层序遍历结果，数字间以1个空格分隔，行的首尾不得有多余空格。第二行输出YES，如果该树是完全二叉树；否则输出NO。

输入样例1：
9
38 45 42 24 58 30 67 12 51
输出样例1：
38 45 24 58 42 30 12 67 51
YES
输入样例2：
8
38 24 12 45 58 67 42 51
输出样例2：
38 45 24 58 42 12 67 51
NO
*/
//https://www.liuchuo.net/archives/2164
#include <bits/stdc++.h>
using namespace std;

int tree[1 << 20] = {0};

//创建树
void BTS(int num, int pla = 1)
{
    //没有数，则创建
    if (tree[pla] == 0)
    {
        tree[pla] = num;
    }
    //比当前数大，则插入左子树
    else if (tree[pla] < num)
    {
        //BTS(num, pla << 1);
        BTS(num, 2 * pla);
    }
    //比当前树小，插入右子树
    else
    {
        //BTS(num, pla << 1 | 1);
        BTS(num, 2 * pla + 1);
    }
}

int main()
{
    int n, num;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        BTS(num);
    }

    bool flag = true;
    //若为完全搜索树，则一定是数组前n个都是满的！
    for (int i = 1, cnt = 1; cnt <= n; i++)
    {
        if (tree[i] == 0)
            flag = false;
        else
        {
            cout << tree[i];
            if (cnt++ != n)
                cout << " ";
        }
    }
    cout << endl
         << (flag ? "YES" : "NO");

    return 0;
}