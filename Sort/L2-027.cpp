#include <bits/stdc++.h>

using namespace std;

short int n, g, k;

typedef struct Student
{
    short int n;
    string name;
    short int score;

    bool operator<(const Student &rhs) const // 升序排序时必须写的函数
    {
        if (score == rhs.score)
        {
            return name > rhs.name;
        }
        return score < rhs.score;
    }
    bool operator>(const Student &rhs) const // 降序排序时必须写的函数
    {
        if (score == rhs.score)
        {
            return name < rhs.name;
        }
        return score > rhs.score;
    }
} Student;

vector<Student> s;

short int main()
{
    cin >> n >> g >> k;

    for (short int i = 1; i <= n; i++)
    {
        Student stu;
        cin >> stu.name >> stu.score;
        s.push_back(stu);
    }

    sort(s.begin(), s.end(), greater<Student>());

    short int num = 0, prescore = -1, money = 0;
    for (short int i = 0; i < s.size(); i++)
    {
        if (prescore != s[i].score)
        {
            num = i + 1;
        }
        s[i].n = num;
        prescore = s[i].score;
        if (s[i].score >= g)
        {
            money += 50;
        }
        else if (s[i].score >= 60)
        {
            money += 20;
        }
    }
    cout << money << endl;
    for (short int j = 0; s[j].n <= k; j++)
    {
        cout << s[j].n << " " << s[j].name << " " << s[j].score;
        if (!(j == s.size() || s[j + 1].n > k))
        {
            cout << endl;
        }
    }

    return 0;
}