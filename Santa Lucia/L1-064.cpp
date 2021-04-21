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
//https://www.cnblogs.com/pkgunboat/p/10651822.html
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool check(const string &a, string::size_type pos, int cstrlen)
{
    bool ok1{false}, ok2{false};
    if ((pos == 0) || a[pos - 1] == ' ' || ispunct(a[pos - 1]))
        ok1 = true;
    if ((pos + cstrlen - 1 == a.size() - 1) || a[pos + cstrlen] == ' ' || ispunct(a[pos + cstrlen]))
        ok2 = true;
    return ok1 & ok2;
}
void stringreplace(string &a)
{
    int cstrlen[] = {7, 9, 1, 2};
    int rstrlen[] = {5, 7, 3, 3};
    char aimstr[][10] = {"can you", "could you", "I", "me"};
    char restr[][10] = {"I can", "I could", "you", "you"};
    string::size_type pos = 0;
    while (pos != a.size())
    {
        int i;
        for (i = 0; i != 4; ++i)
        {
            if (a.compare(pos, cstrlen[i], aimstr[i]) == 0)
                if (check(a, pos, cstrlen[i]))
                {
                    a.replace(pos, cstrlen[i], restr[i]);
                    pos += rstrlen[i];
                    break;
                }
        }
        if (i == 4)
            ++pos;
    }
}
int main(int argc, char **argv)
{
    int cnt;
    cin >> cnt;
    cin.get();
    while (cnt--)
    {
        string str;
        getline(cin, str);
        cout << str << endl;
        cout << "AI: ";
        vector<string::size_type> spaceindex;
        string::size_type pos = 0;
        string::size_type l = 0, r = str.size();
        while (pos != str.size() && str[pos] == ' ')
            ++pos;
        l = pos;
        pos = str.size() - 1;
        while (pos >= l && str[pos] == ' ')
            --pos;
        r = pos + 1;
        str = str.substr(l, r - l);
        pos = 0;
        while ((pos = str.find(' ', pos)) != string::npos)
        {
            if ((str[pos + 1] == ' ') || (ispunct(str[pos + 1])))
                spaceindex.push_back(pos);
            ++pos;
        }
        vector<int>::size_type ind = 0;
        string::size_type j = 0;
        for (string::size_type i = 0; i != str.size(); ++i)
        {
            if (ind != spaceindex.size() && i == spaceindex[ind])
                ++ind;
            else
                str[j++] = str[i];
        }
        str.erase(j);
        for (auto &i : str)
        {
            if (isupper(i) && i != 'I')
                i = tolower(i);
            if (i == '?')
                i = '!';
        }
        stringreplace(str);
        cout << str << endl;
    }
    return EXIT_SUCCESS;
}