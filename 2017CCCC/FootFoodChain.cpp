#include <iostream>
#include <cstring>
using namespace std;
int win[25][25];        //邻接矩阵，保存胜败关系
bool vis[25], flag = 0; //vis标记点， flag判断是否得到符合题意的"食物链"
int N, list[25];        //N个球队，list保存"食物链"
void Dfs(int x, int k)
{
    if (flag) //若flag为真，表示已经得到符合题意的 "食物链",直接退出
        return;
    if (k == N - 1) //"食物链"规模达到N
    {
        if (win[x][1]) //判断最后一点是否与1连通
        {
            flag = 1; //标记已经得到符合题意的"食物链"
            printf("1");
            for (int i = 0; i < k; i++)
                printf(" %d", list[i]);
            printf("\n");
        }
        return;
    }
    int i;
    for (i = 2; i <= N; i++)
        if (!vis[i] && win[i][1]) //判断未标记的点中是否与1连通
            break;
    if (i == N + 1) //未标记的点都不与1连通，直接退出
        return;
    for (i = 2; i <= N; i++)
    {
        if (!vis[i] && win[x][i]) //查找x战胜过的球队
        {
            list[k] = i; //记录点
            vis[i] = true;
            Dfs(i, k + 1);
            vis[i] = false;
        }
    }
}
int main()
{
    scanf("%d", &N);
    char c;
    for (int i = 1; i <= N; i++)
    {
        getchar();
        for (int j = 1; j <= N; j++)
        {
            c = getchar();
            if (c == 'W')
                win[i][j] = 1; //记录i战胜j
            if (c == 'L')
                win[j][i] = 1; //记录j战胜i
        }
    }
    vis[1] = 1; //标记第一个点
    Dfs(1, 0);  //从1开始dfs
    if (!flag)  //未找到符合题意的"食物链"
        cout << "No Solution" << endl;
    return 0;
}