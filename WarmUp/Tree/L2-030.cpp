#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

int n;

typedef struct people
{
    string fname;
    string lname;
    char sex;
} people;

// 定义一个map对象
map<string, people> p;
set<string> sc;

bool Test(string parent, int deep = 0)
{
    if (deep > 3 || p.count(parent) == 0)
    {
        return true;
    }
    int len = sc.size();
    sc.insert(parent);
    if (sc.size() == len)
    {
        return false;
    }
    return Test(p[parent].lname, deep + 1);
}

void setPeople(people &peo)
{
    if (peo.lname.back() == 'm')
    {
        peo.lname.pop_back();
        peo.sex = 'm';
    }
    else if (peo.lname.back() == 'f')
    {
        peo.lname.pop_back();
        peo.sex = 'f';
    }
    else if (peo.lname.back() == 'n')
    {
        peo.lname.pop_back();
        peo.lname.pop_back();
        peo.lname.pop_back();
        peo.lname.pop_back();
        peo.sex = 'm';
    }
    else if (peo.lname.back() == 'r')
    {
        peo.lname.pop_back();
        peo.lname.pop_back();
        peo.lname.pop_back();
        peo.lname.pop_back();
        peo.lname.pop_back();
        peo.lname.pop_back();
        peo.lname.pop_back();
        peo.sex = 'f';
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        people peo;
        cin >> peo.fname >> peo.lname;
        setPeople(peo);
        p[peo.fname] = peo;
    }
    cin >> n;
    string fname, lname, fname1, lname1;
    for (int i = 0; i < n; i++)
    {
        cin >> fname >> lname >> fname1 >> lname1;
        //TrimName(fname);
        //TrimName(lname);
        if (p.count(lname) == 0 || p.count(lname1) == 0)
        {
            cout << "NA" << endl;
        }
        else if (p[fname].sex == p[fname1].sex)
        {
            cout << "Whatever" << endl;
        }
        else
        {
            //cout << "\t" << Test(lname) << "\t" << Test(lname1) << endl;
            sc.clear();
            if (Test(fname) && Test(fname1))
            {
                cout << "Yes" << endl;
            }
            else
                cout << "No" << endl;
        }
        //cin >> lname;
    }
    return 0;
}