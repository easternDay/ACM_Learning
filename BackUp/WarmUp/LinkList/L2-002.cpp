#include <bits/stdc++.h>

using namespace std;

int startNode, n;
int nextNode[100000];
int nodeNum[100000];

typedef struct LinkNode
{
    struct LinkNode *nextAddress;
    int num;
    int address;
} LinkNode;

LinkNode Keep, Delete;
set<int> Have;

int main()
{    

    int addr, num, next;
    cin >> startNode >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> addr >> num >> next;
        nextNode[addr] = next;
        nodeNum[addr] = num;
    }

    addr = startNode;
    Have.clear();
    num = 0;
    LinkNode *reserve = &Keep;
    LinkNode *remove = &Delete;
    while (addr != -1)
    {
        Have.insert(abs(nodeNum[addr]));
        if (Have.size() == num)
        {
            remove->nextAddress = new LinkNode;
            remove = remove->nextAddress;
            remove->nextAddress = NULL;
            remove->num = nodeNum[addr];
            remove->address = addr;
        }
        else
        {
            reserve->nextAddress = new LinkNode;
            reserve = reserve->nextAddress;
            reserve->nextAddress = NULL;
            reserve->num = nodeNum[addr];
            reserve->address = addr;
        }
        num = Have.size();

        addr = nextNode[addr];
    }

    reserve = (&Keep)->nextAddress;
    remove = (&Delete)->nextAddress;
    while (reserve != NULL)
    {
        cout << setw(5) << setfill('0') << reserve->address << " " << reserve->num << " ";
        if (reserve->nextAddress != NULL)
        {
            cout << reserve->nextAddress->address << endl;
        }
        else
        {
            cout << -1;
        }
        reserve = reserve->nextAddress;
    }
    cout << endl;
    while (remove != NULL)
    {
        cout << setw(5) << setfill('0') << remove->address << " " << remove->num << " ";
        if (remove->nextAddress != NULL)
        {
            cout << remove->nextAddress->address << endl;
        }
        else
        {
            cout << -1;
        }
        remove = remove->nextAddress;
    }

    return 0;
}