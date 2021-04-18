#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// 保存学生信息的结构体：邮箱、分数
struct Peo
{
    string email;
    int grade;
};
const int MAXN = 1e4 + 10;
Peo peo[MAXN];

// 自定义数组的排序规则：先按成绩排序，若成绩相同，按邮箱升序
bool com(Peo p1, Peo p2)
{
    if (p1.grade == p2.grade)
    {
        return p1.email < p2.email;
    }
    return p1.grade > p2.grade;
}

int main()
{
    int n, g, k, money = 0;
    cin >> n >> g >> k;
    string email;
    int grade;
    for (int i = 0; i < n; i++)
    {
        cin >> email >> grade;
        peo[i].email = email;
        peo[i].grade = grade;
        // 统计出发出了多少代金券
        if (grade >= 60 && grade < g)
        {
            money += 20;
        }
        else if (grade >= g)
        {
            money += 50;
        }
    }
    sort(peo, peo + n, com);

    cout << money << endl;
    int lastGrade = -1;   // 储存上一个学生的成绩
    int currentLevel = 0; // 储存当前学生的排名
    for (int i = 0; i < k; i++)
    {
        // 如果当前学生的成绩不等于上一个学生的成绩，
        // 证明当前学生的排名在上一个学生的后一名
        if (lastGrade != peo[i].grade)
        {
            currentLevel = i + 1;
        }
        cout << currentLevel << " " << peo[i].email << " " << peo[i].grade << endl;
        lastGrade = peo[i].grade;
    }
    // 输出最后所有并列第 k 名的学生信息
    int i = k;
    while (peo[i].grade == lastGrade)
    {
        cout << currentLevel << " " << peo[i].email << " " << peo[i].grade << endl;
        i++;
    }

    return 0;
}