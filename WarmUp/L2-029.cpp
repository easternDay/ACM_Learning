//特立独行的幸
/*
对一个十进制数的各位数字做一次平方和，称作一次迭代。如果一个十进制数能通过若干次迭代得到 1，就称该数为幸福数。1 是一个幸福数。此外，例如 19 经过 1 次迭代得到 82，2 次迭代后得到 68，3 次迭代后得到 100，最后得到 1。则 19 就是幸福数。显然，在一个幸福数迭代到 1 的过程中经过的数字都是幸福数，它们的幸福是依附于初始数字的。例如 82、68、100 的幸福是依附于 19 的。而一个特立独行的幸福数，是在一个有限的区间内不依附于任何其它数字的；其独立性就是依附于它的的幸福数的个数。如果这个数还是个素数，则其独立性加倍。例如 19 在区间[1, 100] 内就是一个特立独行的幸福数，其独立性为 2×4=8。

另一方面，如果一个大于1的数字经过数次迭代后进入了死循环，那这个数就不幸福。例如 29 迭代得到 85、89、145、42、20、4、16、37、58、89、…… 可见 89 到 58 形成了死循环，所以 29 就不幸福。

本题就要求你编写程序，列出给定区间内的所有特立独行的幸福数和它的独立性。

输入格式：
输入在第一行给出闭区间的两个端点：1<A<B≤10
​4
​​ 。

输出格式：
按递增顺序列出给定闭区间 [A,B] 内的所有特立独行的幸福数和它的独立性。每对数字占一行，数字间以 1 个空格分隔。

如果区间内没有幸福数，则在一行中输出 SAD。

输入样例 1：
10 40
输出样例 1：
19 8
23 6
28 3
31 4
32 3
注意：样例中，10、13 也都是幸福数，但它们分别依附于其他数字（如 23、31 等等），所以不输出。其它数字虽然其实也依附于其它幸福数，但因为那些数字不在给定区间 [10, 40] 内，所以它们在给定区间内是特立独行的幸福数。

输入样例 2：
110 120
输出样例 2：
SAD
*/
#include <bits/stdc++.h>

using namespace std;

//判断素数
bool isSu(const int a)
{
    bool flag = true;
    for (int i = 2; i < a; i++)
    {
        if (i * i > a)
        {
            break;
        }
        if (a % i == 0)
        {
            flag = false;
            break;
        }
    }
    return flag;
}

//获取下一个幸福数
int getNext(const int a)
{
    int i = a, j = a % 10;
    int out = j * j;
    while (i != 0)
    {
        i = i / 10;
        j = i % 10;
        out += j * j;
    }
    return out;
}

//获取幸福数步数
int getStep(const int a)
{
    int m = a, count = 0;
    while (m != 1)
    {
        count++;
        m = getNext(m);
    }
    return isSu(a) ? 2 * count : count;
}

int a, b, length;
int p[10001];

int main()
{
    cin >> a >> b;

    for (int i = 0; i < 10001; i++)
    {
        p[i] = 0;
    }

    int m;

    for (int i = a; i <= b; i++)
    {
        m = i;
        while (m != 1)
        {
            p[m]++;
            if (m == i)
            {
                p[i] = 1;
            }
            if (p[m] >= b - a + 1)
            {
                p[m] = 2;
                p[i]++;
                break;
            }
            m = getNext(m);
        }
    }

    int count = 0;
    for (int i = a; i < b; i++)
    {
        if (p[i] == 1)
        {
            count++;
            cout << i << " " << getStep(i) << endl;
        }
    }
    if (count == 0)
    {
        cout << "SAD";
    }

    return 0;
}
/*
#include<stdio.h>
#include<math.h>                //独立性就是中转次数(素数*2)
#include<string.h>
int num[100005]={0},flag[100005]={0},TIMES[100005]={0},sad=0;
int aa,bb; 

int prime(int a)                //判断素数 
{
    for(int i=2;i<=sqrt(a);i++)
        if(a%i==0)
            return 1;           //返回1不是素数 
    return 0;                   //返回0是素数 
} 

void judge(int a)
{   
    memset(flag,0,10005);           //flag数组用于判断对a是否回头路 
    int times=0,A=a,tag=0;
    
    while(a!=1)
    {
        int sum=0;
        while(a)
        {
            sum=sum+pow((a%10),2);
            a/=10; 
        }   
        
        a=sum;
        times++;
        if(flag[a]==1||num[a]==-1)              //不走回头路，也不走前人摔下的路 
        {
            tag=1;
            num[A]=-1; 
            break;
        } 
        flag[a]=1;
    }
    
    if(tag==1)
        return;
        
    if(prime(A))            //不是素数
        TIMES[A]=times;     
    else                    //素数
        TIMES[A]=2*times;       

    for(int i=aa;i<=bb;i++)
    {
        if(i==A)
            continue;
        if(flag[i]==1)
            num[i]-=9999999;                //num[i]是负数表示是被用过的数字 
    }

    num[A]+=1;                          //负多正少是扭转不了什么的 
} 

int main()
{
    scanf("%d%d",&aa,&bb);
    
    for(int i=aa;i<=bb;i++)
        judge(i);                   
    
    for(int i=aa;i<=bb;i++)         
        if(num[i]>0)                    //不许依附于其它幸福数
        {
            printf("%d %d\n",i,TIMES[i]);
            sad=1;
        }
            
    if(sad==0)
        printf("SAD");
    return 0;
}
*/