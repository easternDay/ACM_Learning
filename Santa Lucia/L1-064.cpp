/*
以上图片来自新浪微博。

本题要求你实现一个稍微更值钱一点的 AI 英文问答程序，规则是：

无论用户说什么，首先把对方说的话在一行中原样打印出来；
消除原文中多余空格：把相邻单词间的多个空格换成 1 个空格，把行首尾的空格全部删掉，把标点符号前面的空格删掉；
把原文中所有大写英文字母变成小写，除了 I；
把原文中所有独立的 can you、could you 对应地换成 I can、I could—— 这里“独立”是指被空格或标点符号分隔开的单词；
把原文中所有独立的 I 和 me 换成 you；
把原文中所有的问号 ? 换成惊叹号 !；
在一行中输出替换后的句子作为 AI 的回答。
输入格式：
输入首先在第一行给出不超过 10 的正整数 N，随后 N 行，每行给出一句不超过 1000 个字符的、以回车结尾的用户的对话，对话为非空字符串，仅包括字母、数字、空格、可见的半角标点符号。

输出格式：
按题面要求输出，每个 AI 的回答前要加上 AI: 和一个空格。

输入样例：
6
Hello ?
 Good to chat   with you
can   you speak Chinese?
Really?
Could you show me 5
What Is this prime? I,don 't know
输出样例：
Hello ?
AI: hello!
 Good to chat   with you
AI: good to chat with you
can   you speak Chinese?
AI: I can speak chinese!
Really?
AI: really!
Could you show me 5
AI: I could show you 5
What Is this prime? I,don 't know
AI: what Is this prime! you,don't know
*/
#include <bits/stdc++.h>
using namespace std;

bool isABC(char c)
{
    return (c > 'A' && c < 'Z') || (c > 'a' && c < 'z');
}

int main()
{
    int n, otherPla;
    cin >> n;
    getchar();
    string s;
    while (n--)
    {
        getline(cin, s);
        cout << s << endl;
        //消除行首空格
        while (s[0] == ' ')
            s.replace(0, 1, "");
        //消除结尾空格
        while (s[s.size() - 1] == ' ')
            s.replace(s.size() - 1, 1, "");
        //消除标点符号前的空格
        for (int i = 1; i < s.size(); i++)
        {
            if (!isABC(s[i]) && s[i - 1] == ' ')
                s.replace(i - 1, 1, "");
        }
        //消除多余空格
        while ((otherPla = s.find("  ")) != -1)
        {
            s.replace(otherPla, 2, " ");
        }
        //小写转化
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'I')
            {
                if (i == 0 && !isABC(s[i + 1]))
                {
                    s.replace(otherPla, 1, "you");
                    continue;
                }
                if (i == s.size() - 1 && !isABC(s[i - 1]))
                {
                    s.replace(otherPla, 1, "you");
                    continue;
                }
                if (i > 0 && i < s.size() - 1 && !isABC(s[i + 1]) && !isABC(s[i - 1]))
                {
                    s.replace(otherPla, 1, "you");
                    continue;
                }
            }
            s[i] = tolower(s[i]);
        }
        //把原文中所有独立的 I 和 me 换成 you
        if (s.substr(0, 2) == "me ")
            s.replace(0, 2, "you");
        if (s.substr(s.size() - 3, s.size() - 1) == " me")
            s.replace(s.size() - 2, 2, "you");
        while ((otherPla = s.find(" me ")) != -1)
            s.replace(otherPla, 3, " you");
        //把原文中所有独立的 can you、could you 对应地换成 I can、I could—— 这里“独立”是指被空格或标点符号分隔开的单词；
        while ((otherPla = s.find("can you")) != -1)
        {
            if (otherPla == 0 && s[7] == ' ')
                s.replace(0, 7, "I can");
            else if (otherPla == s.size() - 7 && s[otherPla - 1] == ' ')
                s.replace(otherPla, 7, "I can");
            else if (s[otherPla - 1] == ' ' && s[otherPla + 7] == ' ')
                s.replace(otherPla, 7, "I can");
        }
        while ((otherPla = s.find("could you")) != -1)
        {
            if (otherPla == 0 && s[9] == ' ')
                s.replace(0, 9, "I could");
            else if (otherPla == s.size() - 9 && s[otherPla - 1] == ' ')
                s.replace(otherPla, 9, "I could");
            else if (s[otherPla - 1] == ' ' && s[otherPla + 9] == ' ')
                s.replace(otherPla, 9, "I could");
        }
        //把原文中所有的问号 ? 换成惊叹号 !；
        while ((otherPla = s.find("?")) != -1)
            s.replace(otherPla, 1, "!");
        cout << "AI: " << s << endl;
    }

    return 0;
}