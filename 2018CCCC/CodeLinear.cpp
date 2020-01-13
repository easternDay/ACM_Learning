#include <iostream>
#include <cstdio>
using namespace std;
int ignore_space(const string &s, int d, int t)
{
    while (d < s.size() && d > 0 && s[d] == ' ')
    {
        d += t;
    }
    return d;
}
int trim_space(string &s, int d, int t)
{
    if (s[d] != ' ')
        s.insert(d, " ");
    d += t;
    int i = 0;
    while (i + d < s.size() && s[i + d] == ' ')
        i++;
    if (i)
        s.erase(d, i);
    return d;
}
bool judge(string s, int d, int &flag)
{
    if (d && isalpha(s[d - 1]))
        return false;
    if (s.substr(d, 2) == "if" && (s[d + 2] == ' ' || s[d + 2] == '('))
        return true;
    if (s.substr(d, 3) == "for" && (s[d + 3] == ' ' || s[d + 3] == '('))
        return true;
    if (s.substr(d, 5) == "while" && (s[d + 5] == ' ' || s[d + 5] == '('))
        return true;
    flag = 0;
    if (s.substr(d, 4) == "else" && (s[d + 4] == ' ' || s[d + 4] == '{'))
        return true;
    return false;
}
void perfect(string &s)
{
    for (int i = s.size() - 1; i >= 0; i--)
    {
        int ise = 1;
        if (s[i] == ')')
        {
            int d = 1, j = i - 1;
            while (d && j >= 0)
            {
                if (s[j] == ')')
                    d++;
                else if (s[j] == '(')
                    d--;
                j--;
            }
            i = j + 1;
        }
        else if (judge(s, i, ise))
        {
            int j = i;
            while (j < s.size() && isalpha(s[j]))
                j++;
            if (ise)
            {
                j = trim_space(s, j, 1);
                int d = 1;
                while (d != 0 && ++j < s.size())
                {
                    if (s[j] == '(')
                        d++;
                    else if (s[j] == ')')
                        d--;
                }
                j++;
            }
            j = trim_space(s, j, 1);
            if (s[j] != '{')
            {
                s.insert(j, "{");
                j++;
                int flag = 0;
                while (j < s.size())
                {
                    if (s[j] == ';' && flag == 0)
                    {
                        s.insert(j + 1, "}");
                        break;
                    }
                    else if (s[j] == '(')
                        flag++;
                    else if (s[j] == ')')
                        flag--;
                    else if (s.substr(j, 2) == "if")
                        flag++;
                    else if (s.substr(j, 4) == "else")
                        flag--;
                    else if (s[j] == '{')
                        flag++;
                    else if (s[j] == '}')
                    {
                        flag--;
                        if (flag == 1 && s[ignore_space(s, j + 1, 1)] != 'e')
                            flag--;
                        if (flag == 0)
                        {
                            s.insert(j + 1, "}");
                            break;
                        }
                    }
                    j++;
                }
            }
        }
    }
}
void put_space(int k)
{
    while (k--)
    {
        printf("  ");
    }
}
bool check(char s)
{
    return s == ')' || s == 'e' || s == '{' || s == '}' || s == ';';
}
int main()
{
    int flag = 0, space_num = 0, start = 1;
    string s;
    getline(cin, s);
    perfect(s);
    for (int i = ignore_space(s, 0, 1); i < s.size(); i++)
    {
        if (start)
        {
            start = 0;
            if (s[i] == '}')
                put_space(space_num - 1);
            else
                put_space(space_num);
        }
        if (s[i] == '{')
        {
            int d = ignore_space(s, i - 1, -1);
            if (!flag || !check(s[d]))
            {
                putchar('\n');
                put_space(space_num);
            }
            flag = 1;
            putchar(s[i]);
            putchar('\n');
            space_num++;
            start = 1;
            i = ignore_space(s, i + 1, 1) - 1;
        }
        else if (s[i] == '}')
        {
            space_num--;
            putchar(s[i]);
            i = ignore_space(s, i + 1, 1) - 1;
            if (s[i + 1] == '}')
            {
                putchar('\n');
                start = 1;
            }
            else if (i < s.size() - 1)
            {
                putchar('\n');
                start = 1;
            }
        }
        else if (s[i] == '(')
        {
            int d = 1, j = i;
            putchar(s[i]);
            while (d)
            {
                putchar(s[++j]);
                if (s[j] == '(')
                    d++;
                else if (s[j] == ')')
                    d--;
            }
            i = j;
            if (!flag)
                i = ignore_space(s, i + 1, 1) - 1;
        }
        else if (s[i] == ';')
        {
            putchar(s[i]);
            i = ignore_space(s, i + 1, 1) - 1;
            putchar('\n');
            start = 1;
        }
        else
        {
            putchar(s[i]);
        }
    }
    return 0;
}