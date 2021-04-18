// 给定一棵二叉树的后序遍历和中序遍历，请你输出其层序遍历的序列。这里假设键值都是互不相等的正整数。

// 输入格式：
// 输入第一行给出一个正整数N（≤30），是二叉树中结点的个数。第二行给出其后序遍历序列。第三行给出其中序遍历序列。数字间以空格分隔。

// 输出格式：
// 在一行中输出该树的层序遍历的序列。数字间以1个空格分隔，行首尾不得有多余空格。

// 输入样例：
// 7
// 2 3 1 5 7 6 4
// 1 2 3 4 5 6 7
// 输出样例：
// 4 1 6 3 5 7 2
#include <bits/stdc++.h>
using namespace std;

int num;
int *lastS, *midS;

int S[1000] = {0};

//找到分裂点
int findPos(int n)
{
    for (int i = 0; i < num; i++)
    {
        if (midS[i] == n)
        {
            return i;
        }
    }
    return -1;
}

void func(int lastStart, int lastEnd, int mid, int start, int end, int index)
{
    int preLength = mid - start; //前半段长度
    int lastLength = end - mid;  //后半段长度

    //规划一下
    S[index] = midS[mid];

    if (preLength > 0)
    {
        int preMid = findPos(lastS[lastStart - 1 + preLength]);
        func(lastStart, lastStart - 1 + preLength, preMid, start, mid - 1, 2 * index + 1);
    }

    if (lastLength > 0)
    {
        int lastMid = findPos(lastS[lastEnd - 1]);
        func(lastStart + preLength, lastEnd - 1, lastMid, mid + 1, end, 2 * index + 2);
    }
}

int main()
{
    cin >> num;           //读取数目
    lastS = new int[num]; //创建数组
    midS = new int[num];  //创建数组

    for (int i = 0; i < num; i++)
    {
        cin >> lastS[i];
    }
    for (int i = 0; i < num; i++)
    {
        cin >> midS[i];
    }

    //找到分裂位置
    int mid = findPos(lastS[num - 1]);

    //开搞
    func(0, num - 1, mid, 0, num - 1, 0);

    for (int i = 0; i < 465; i++)
    {
        if (S[i] != 0)
        {
            if (i != 0)
            {
                cout << " ";
            }
            cout << S[i];
        }
    }

    return 0;
}