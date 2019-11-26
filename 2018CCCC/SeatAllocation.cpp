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
#include <queue>
#include <vector>

using namespace std;

#define CodeBlocks true

struct node
{
    vector<int> q;
    int num;
} ac[105];

int main()
{
    //输入样例
    //> 3
    //> 3 4 2

    int n, total = 0;
    cin >> n; //输入学校数目
    int x;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;           //输入队伍数目
        ac[i].num = x * 10; //队伍人数
        total += x * 10;    //总人数
    }

    //TODO
    int id = 1;
    //总人数循环
    while (total--)
    {
        //按照学校循环
        for (int i = 1; i <= n; i++)
        {
            //学校所有人进入队列
            if (ac[i].q.size() != ac[i].num)
            {
                //是否为最后一个学校
                if (ac[i].q.empty() == false && ac[i].q.back() + 1 == id)
                {
                    ac[i].q.push_back(id + 1);
                    id += 2;
                }
                else
                {
                    ac[i].q.push_back(id);
                    id++;
                }
            }
        }
    }

    //按学校输出
    for (int i = 1; i <= n; i++)
    {
        cout << "#" << i << endl;
        for (int j = 0; j < ac[i].q.size(); j++)
        {
            if (j % 10 == 0 && j != 0)
                cout << endl;
            if (j % 10 != 0)
                cout << " ";
            cout << ac[i].q[j];
        }
        cout << endl;
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