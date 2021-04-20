/*
一棵二叉搜索树可被递归地定义为具有下列性质的二叉树：对于任一结点，

其左子树中所有结点的键值小于该结点的键值；
其右子树中所有结点的键值大于等于该结点的键值；
其左右子树都是二叉搜索树。
所谓二叉搜索树的“镜像”，即将所有结点的左右子树对换位置后所得到的树。

给定一个整数键值序列，现请你编写程序，判断这是否是对一棵二叉搜索树或其镜像进行前序遍历的结果。

输入格式：
输入的第一行给出正整数 N（≤1000）。随后一行给出 N 个整数键值，其间以空格分隔。

输出格式：
如果输入序列是对一棵二叉搜索树或其镜像进行前序遍历的结果，则首先在一行中输出 YES ，然后在下一行输出该树后序遍历的结果。数字间有 1 个空格，一行的首尾不得有多余空格。若答案是否，则输出 NO。

输入样例 1：
7
8 6 5 7 10 8 11
输出样例 1：
YES
5 7 6 8 11 10 8
输入样例 2：
7
8 10 11 8 6 7 5
输出样例 2：
YES
11 8 10 7 5 6 8
输入样例 3：
7
8 6 8 5 10 9 11
输出样例 3：
NO
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> pre, post;

void getPost(int root, int tail, bool isMirror = false)
{
    if (root > tail)
        return;
    int i = root + 1, j = tail;
    if (!isMirror)
    {
        while (i <= tail && pre[root] > pre[i])
            i++;
        while (j > root && pre[root] <= pre[j])
            j--;
    }
    else
    {
        while (i <= tail && pre[root] <= pre[i])
            i++;
        while (j > root && pre[root] > pre[j])
            j--;
    }
    if (i - j != 1)
        return;
    getPost(root + 1, j, isMirror);
    getPost(i, tail, isMirror);
    post.push_back(pre[root]);
}

int main()
{
    int n;
    cin >> n;
    //输入前序序列
    pre.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> pre[i];
    }
    getPost(0, n - 1);
    if (post.size() != n)
    {
        post.clear();
        getPost(0, n - 1, true);
    }
    if (post.size() == n)
    {
        cout << "YES" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << post[i];
            if (i != n - 1)
                cout << " ";
        }
    }
    else
    {
        cout << "NO";
    }
    return 0;
}