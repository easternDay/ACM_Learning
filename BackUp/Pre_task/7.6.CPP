// 给定一棵二叉树的中序遍历和前序遍历，请你先将树做个镜面反转，再输出反转后的层序遍历的序列。所谓镜面反转，是指将所有非叶结点的左右孩子对换。这里假设键值都是互不相等的正整数。

// 输入格式：
// 输入第一行给出一个正整数N（≤30），是二叉树中结点的个数。第二行给出其中序遍历序列。第三行给出其前序遍历序列。数字间以空格分隔。

// 输出格式：
// 在一行中输出该树反转后的层序遍历的序列。数字间以1个空格分隔，行首尾不得有多余空格。

// 输入样例：
// 7
// 1 2 3 4 5 6 7
// 4 1 3 2 6 5 7
// 输出样例：
// 4 6 1 7 5 3 2

#include <bits/stdc++.h>
using namespace std;

int num;
int *preS, *midS;

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

void func(int preStart, int preEnd, int mid, int start, int end, int index)
{
    int preLength = mid - start; //前半段长度
    int lastLength = end - mid;  //后半段长度

    //规划一下
    S[index] = midS[mid];

    if (lastLength > 0)
    {
        int lastMid = findPos(preS[preStart + preLength + 1]);
        func(preStart + preLength + 1, preEnd, lastMid, mid + 1, end, 2 * index + 1);
    }

    if (preLength > 0)
    {
        int preMid = findPos(preS[preStart + 1]);
        func(preStart + 1, preStart + preLength, preMid, start, mid - 1, 2 * index + 2);
    }
}

int main()
{
    cin >> num;          //读取数目
    preS = new int[num]; //创建数组
    midS = new int[num]; //创建数组

    for (int i = 0; i < num; i++)
    {
        cin >> midS[i];
    }

    for (int i = 0; i < num; i++)
    {
        cin >> preS[i];
    }

    //找到分裂位置
    int mid = findPos(preS[0]);

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