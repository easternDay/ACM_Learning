/*
给定一棵二叉树的中序遍历和前序遍历，请你先将树做个镜面反转，再输出反转后的层序遍历的序列。所谓镜面反转，是指将所有非叶结点的左右孩子对换。这里假设键值都是互不相等的正整数。

输入格式：
输入第一行给出一个正整数N（≤30），是二叉树中结点的个数。第二行给出其中序遍历序列。第三行给出其前序遍历序列。数字间以空格分隔。

输出格式：
在一行中输出该树反转后的层序遍历的序列。数字间以1个空格分隔，行首尾不得有多余空格。

输入样例：
7
1 2 3 4 5 6 7
4 1 3 2 6 5 7
输出样例：
4 6 1 7 5 3 2
*/
#include <bits/stdc++.h>
using namespace std;

int num;
vector<int> midSeq;
vector<int> preSeq;
vector<int> midInPreSeq;
vector<int> layerSeq;

//查找位置
int findMidInPre(int n)
{
    for (int i = 0; i < num; i++)
    {
        if (preSeq[i] == n)
            return i;
    }
}

//初始化
int Init()
{
    //临时变量
    int temp;

    //参数初始化
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cin >> temp;
        midSeq.push_back(temp);
    }
    for (int i = 0; i < num; i++)
    {
        cin >> temp;
        preSeq.push_back(temp);
    }

    //完全二叉树的节点数=2^层数-1
    for (int i = 0; i < pow(2, num); i++)
    {
        layerSeq.push_back(-1);
    }

    //顺序查找
    for (int i = 0; i < num; i++)
    {
        //midInPreSeq.push_back(findMidInPre(midSeq[i]));

        midInPreSeq.push_back(find(preSeq.begin(), preSeq.end(), midSeq[i]) - preSeq.begin());
    }
}

//查找最小位置
int findMin(int left, int right)
{
    int split = left;
    int pla = midInPreSeq[left];
    for (int i = left + 1; i <= right; i++)
    {
        if (midInPreSeq[i] < pla)
        {
            pla = midInPreSeq[i];
            split = i;
        }
    }
    return split;
}

//插入位置
void insertSeq(int midLeft, int midRight, int midSplitPla, int insertPla = 0)
{
    if (midRight < midLeft)
        return;
    layerSeq[insertPla] = midSeq[midSplitPla];
    insertSeq(midLeft, midSplitPla - 1, findMin(midLeft, midSplitPla - 1), 2 * insertPla + 2);
    insertSeq(midSplitPla + 1, midRight, findMin(midSplitPla + 1, midRight), 2 * insertPla + 1);
}

int main()
{
    Init(); //初始化
    insertSeq(0, num - 1, findMin(0, num - 1));

    int count = 0;
    for (int i = 0; i < pow(2, num) - 1 && count < num; i++)
    {
        if (layerSeq[i] != -1)
        {
            cout << layerSeq[i];
            count++;
            if (count != num)
                cout << " ";
        }
    }

    return 0;
}