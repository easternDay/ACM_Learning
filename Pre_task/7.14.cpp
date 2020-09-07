#include <bits/stdc++.h>

using namespace std;

int num;    //记录句子数目
string s;   //记录字符串
bool isQBZ; //记录是否转化
int m, n;   //记录逗号和句号位置
int pos;

string out = "";

int judge(int m, int n)
{
    int count = 0;
    if (s[m - 3] == 'o' && s[m - 2] == 'n' && s[m - 1] == 'g' && s[n - 3] == 'o' && s[n - 2] == 'n' && s[n - 1] == 'g')
    {
        while (count != 3)
        {
            if (s[n--] == ' ')
                count++;
        }
        return n;
    }
    return -1;
}

int main()
{
    //记录句子数目
    cin >> num;
    getchar();

    while (num--)
    {
        //读取句子
        getline(cin, s);
        //遍历句子
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ',')
            {
                m = i; //找到逗号
                break;
            }
        }
        n = s.size() - 1; //句号为最后一个

        pos = judge(m, n);

        if (pos != -1)
        {
            for (int i = 0; i <= pos; i++)
            {
                out += s[i];
            }
            out += " qiao ben zhong.";
        }
        else
        {
            out += "Skipped";
        }
        if (num != 0)
        {
            out += "\n";
        }
    }

    cout << out;

    return 0;
}