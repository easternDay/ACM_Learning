#include <bits/stdc++.h>

using namespace std;

int num;
string out = "";

int findHead(string s)
{
    //遍历字符串
    for (int i = 0; i < s.size(); i++)
    {
        //碰到空格
        if (s[i] == ' ')
        {
            //跳过
            continue;
        }
        return i;
    }
    return -1;
}
int findTail(string s)
{
    //遍历字符串
    for (int i = s.size() - 1; i >= 0; i--)
    {
        //碰到空格
        if (s[i] == ' ')
        {
            //跳过
            continue;
        }
        return i + 1;
    }
    return -1;
}

string func(string s)
{
    string c = "";

    //获取开头结尾起始位置
    int i = findHead(s);
    int j = findTail(s);

    //如果为空串
    if (i == -1 || j == -1)
    {
        return c;
    }

    //遍历字符串
    bool isSpa = false;
    //第一次处理
    while (i < j)
    {
        //碰到空格
        if (s[i] == ' ')
        {
            isSpa = true;
            i++;
            continue;
        }
        //如果不是空格
        if (isSpa)
        {
            c += " ";
            isSpa = false;
        }
        //大写英文字幕变小写，除了I
        if (s[i] > 'A' && s[i] < 'Z' && s[i] != 'I')
        {
            c += s[i] - 'A' + 'a';
        }
        //问好换感叹号
        else if (s[i] == '?')
        {
            c += "!";
        }
        //问好换感叹号
        else if (s[i] == 'I' && (s[i + 1] == ' ' || (!(s[i + 1] > 'A' && s[i + 1] < 'Z') && !(s[i + 1] > 'a' && s[i + 1] < 'z'))))
        {
            c += "you";
        }
        //原字符字符不变
        else
        {
            c += s[i];
        }

        i++;
    }
    //字符串替换
    string ret = "";
    for (int k = 0; k < c.size(); k++)
    {
        if (c[k] == 'c' && c[k + 1] == 'a' && c[k + 2] == 'n' && c[k + 3] == ' ' && c[k + 4] == 'y' && c[k + 5] == 'o' && c[k + 6] == 'u')
        {
            k += 6;
            ret += "I can";
        }
        else if (c[k] == 'c' && c[k + 1] == 'o' && c[k + 2] == 'u' && c[k + 3] == 'l' && c[k + 4] == 'd' && c[k + 5] == ' ' && c[k + 6] == 'y' && c[k + 7] == 'o' && c[k + 8] == 'u')
        {
            k += 8;
            ret += "I could";
        }
        else if (c[k] == 'm' && c[k + 1] == 'e' && c[k - 1] == ' ')
        {
            k += 1;
            ret += "you";
        }
        else if (c[k] == ' ' && !(c[k + 1] > 'A' && c[k + 1] < 'Z') && !(c[k + 1] > 'a' && c[k + 1] < 'z') && !(c[k + 1] > '0' && c[k + 1] < '9'))
        {
            continue;
        }
        else
        {
            ret += c[k];
        }
    }

    return ret;
}

int main()
{
    cin >> num; //输入数字
    getchar();  //吸收回车

    string s; //记录输入

    while (num--)
    {
        getline(cin, s); //读取行

        out += s;
        out += "\n";
        out += "AI: " + func(s);

        if (num != 0)
        {
            out += "\n";
        }
    }

    cout << out;

    return 0;
}