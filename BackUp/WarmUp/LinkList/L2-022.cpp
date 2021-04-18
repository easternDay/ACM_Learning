#include <bits/stdc++.h>

using namespace std;

typedef struct
{
    int pla;
    int addr;
    int data;
    int next;
    int front;
} LinkNode;

LinkNode ilist[1000000];
int start, tail, n;

int main()
{
    int temp;
    cin >> start >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        ilist[temp].addr = temp;
        cin >> ilist[temp].data >> ilist[temp].next;
        ilist[ilist[temp].next].front = temp;
    }

    temp = start;
    int pla = 0;
    while (ilist[temp].next != -1)
    {
        ilist[temp].pla = pla++;
        temp = ilist[temp].next;
        if (ilist[temp].next == -1)
        {
            tail = temp;
        }
    }

    temp = start;
    LinkNode *final = new LinkNode[n + 2];
    pla = 0;
    while (ilist[temp].pla < n / 2)
    {
        final[pla++] = ilist[tail];
        tail = ilist[tail].front;
        final[pla++] = ilist[temp];
        temp = ilist[temp].next;
    }

    for (int i = 0; i < n; i++)
    {
        cout << setw(5) << setfill('0') << final[i].addr << " " << final[i].data << " ";
        if (i == n - 1)
        {
            cout << -1;
        }
        else
        {
            cout << setw(5) << setfill('0') << final[i + 1].addr << endl;
        }
    }

    return 0;
}