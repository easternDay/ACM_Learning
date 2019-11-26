/**
 * 天梯赛每年有大量参赛队员，要保证同一所学校的所有队员都不能相邻，分配座位就成为一件比较麻烦的事情。
 * 为此我们制定如下策略：假设某赛场有 N 所学校参赛，第 i 所学校有 M[i] 支队伍，每队 10 位参赛选手。
 * 令每校选手排成一列纵队，第 i+1 队的选手排在第 i 队选手之后。
 * 从第 1 所学校开始，各校的第 1 位队员顺次入座，然后是各校的第 2 位队员…… 以此类推。
 * 如果最后只剩下 1 所学校的队伍还没有分配座位，则需要安排他们的队员隔位就坐。
 * 本题就要求你编写程序，自动为各校生成队员的座位号，从 1 开始编号。
 * 
 * 输入格式：
 * 输入在一行中给出参赛的高校数 N （不超过100的正整数）；第二行给出 N 个不超过10的正整数，其中第 i 个数对应第 i 所高校的参赛队伍数，数字间以空格分隔。
 * 
 * 输出格式：
 * 从第 1 所高校的第 1 支队伍开始，顺次输出队员的座位号。每队占一行，座位号间以 1 个空格分隔，行首尾不得有多余空格。另外，每所高校的第一行按“#X”输出该校的编号X，从 1 开始。
*/

#include <iostream>

using namespace std;

#define CodeBlocks true

int main()
{
    //输入样例
    //> 3
    //> 3 4 2

    int i;
    //Get the school num & Team num.
    int N, count = 0;
    cin >> N;
    int *M = new int[N];
    for (i = 0; i < N; i++)
    {
        cin >> M[i];
        M[i] *= 10;
        count += M[i];
    }

    //TODO
    int now = 0, pos = 0, pre = -1;
    int *Table = new int[count + 10];
    while (count != 0)
    {
        if (now >= 3)
        {
            now -= 3;
        }
        if (pre == now)
        {
            Table[pos++] = -1;
        }
        else
        {
            if (M[now] == 0)
            {
                now++;
                continue;
            }
            pre = now;
            Table[pos++] = now;
            if (pos % 10 == 0)
            {
                cout << endl;
            }
            M[now++]--;
        }
        count--;
    }

    for (i = 0; i < pos; i++)
    {
        if (i % 10 == 0)
        {
            cout << endl;
        }
        if (Table[i] != -1)
        {
            cout << Table[i] << "\t";
        }
    }

    cout << endl;
    cout << "#1" << endl;
    for (i = 0, count = 0; i < pos; i++)
    {
        if (count != 0 && count % 10 == 0)
        {
            cout << endl;
        }
        if (Table[i] != -1 && Table[i] == 0)
        {
            count++;
            cout << i + 1 << " ";
        }
    }
    cout << "#2" << endl;
    for (i = 0, count = 0; i < pos; i++)
    {
        if (count != 0 && count % 10 == 0)
        {
            cout << endl;
        }
        if (Table[i] != -1 && Table[i] == 1)
        {
            count++;
            cout << i + 1 << " ";
        }
    }
    cout << "#3" << endl;
    for (i = 0, count = 0; i < pos; i++)
    {
        if (count != 0 && count % 10 == 0)
        {
            cout << endl;
        }
        if (Table[i] != -1 && Table[i] == 2)
        {
            count++;
            cout << i + 1 << " ";
        }
    }

    //输出样例
    //> #1
    //> 1 4 7 10 13 16 19 22 25 28
    //> 31 34 37 40 43 46 49 52 55 58
    //> 61 63 65 67 69 71 73 75 77 79
    //> #2
    //> 2 5 8 11 14 17 20 23 26 29
    //> 32 35 38 41 44 47 50 53 56 59
    //> 62 64 66 68 70 72 74 76 78 80
    //> 82 84 86 88 90 92 94 96 98 100
    //> #3
    //> 3 6 9 12 15 18 21 24 27 30
    //> 33 36 39 42 45 48 51 54 57 60
    return 0;
}