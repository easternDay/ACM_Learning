#include <bits/stdc++.h>

using namespace std;

int n;            //记录数目
int isJX = false; //不是镜像

bool judge(int *set, int i);

int main()
{
    cin >> n;              //记录总数目
    int *set = new int[n]; //动态数组
    bool bl = true;        //判断终止

    for (int i = 0; i < n; i++)
    {
        cin >> set[i]; //读取数组
    }

    //判断数目
    if (n <= 2)
    {
        cout << "YES" << endl;
        if (n == 2)
        {
            cout << set[0] << ' ' << set[1];
            if (set[1] > set[0])
            {
                isJX = true;
            }
        }
        else
        {
            cout << set[0];
        }
    }

    //先判断为NO的情况
    for (int i = 0; i < n; i++)
    {
        bl = bl && judge(set, i);
        if (!bl)
        {
            cout << "NO";
            return 1;
        }
    }

    //通过测试

    return 0;
}

//i为读取位置
bool judge(int *set, int i)
{
    int left, right;
    left = right = 2 * i + 1;

    //判断是否镜像
    isJX ? left += 1 : right += 1; //三元式

    if ((set[i] > set[left] && left < n) || (set[i] <= set[right] && right < n))
    {
        return false;
    }

    return true;
}