#include <bits/stdc++.h>

using namespace std;

typedef struct ret
{
    int bigPos;
    int lessPos;
} ret;

ret func(int *input, int pos, int max, bool *isOut)
{

    ret returns;
    returns.bigPos = 0;
    returns.lessPos = 0;

    for (int i = pos + 1; i < max; i++)
    {
        if (returns.bigPos == 0 && !isOut[i] && input[i] > input[pos])
        {
            returns.bigPos = i;
        }
        if (returns.lessPos == 0 && !isOut[i] && input[i] < input[pos])
        {
            returns.lessPos = i;
        }
        if (returns.bigPos != 0 && returns.lessPos != 0)
        {
            return returns;
        }
    }
    return returns;
}

int main()
{
    int num;     //记录数目
    int *input;  //输入数组
    bool *isOut; //是否输出

    queue<int> que; //记录队列

    bool isComl = true; //是否完全

    cin >> num;            //记录num
    input = new int[num];  //输入数组
    isOut = new bool[num]; //输入数组

    for (int i = 0; i < num; i++)
    {
        cin >> input[i]; //填充输入流
        isOut[i] = false;
    }

    //输入第一个元素
    que.push(0);
    cout << input[0];
    if (0 != num - 1)
    {
        cout << " ";
    }
    isOut[0] = true;

    while (!que.empty())
    {
        int pos = que.front();

        int max = num;

        //判断pos后是否有比他大的已读取元素
        for (int i = pos + 1; i < num; i++)
        {
            if (isOut[i] && input[i] > input[pos])
            {
                max = i;
                break;
            }
        }

        ret returns = func(input, pos, max, isOut);

        //有左孩子没有右孩子说明不完全
        if (returns.bigPos == 0 & returns.lessPos != 0)
        {
            isComl = false;
        }

        //第一个比它大的
        if (returns.bigPos != 0)
        {
            cout << input[returns.bigPos];
            if (returns.bigPos != num - 1)
            {
                cout << " ";
            }
            isOut[returns.bigPos] = true;

            que.push(returns.bigPos);
        }

        //第一个比它小的
        if (returns.lessPos != 0)
        {
            cout << input[returns.lessPos];
            if (returns.lessPos != num - 1)
            {
                cout << " ";
            }
            isOut[returns.lessPos] = true;

            que.push(returns.lessPos);
        }

        que.pop();
    }

    cout << endl;
    cout << (isComl ? "YES" : "NO");

    return 0;
}