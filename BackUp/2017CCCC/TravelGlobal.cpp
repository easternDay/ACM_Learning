#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <queue>

#define MAX 10000 + 10
#define INF 0x3fffffff

using namespace std;

vector<int> MGraph[MAX];
vector<int> path[MAX];
vector<int> tempPath;
vector<int> bestPath;
int cnt = INF;

int rote[MAX][MAX];

int visit[MAX];
int dist[MAX];

typedef struct
{
    int u;
    int value;
} Node;

bool operator>(const Node &a, const Node &b)
{
    return a.value > b.value;
}

void Dijkstra(int start, int end)
{
    cnt = INF;
    for (int i = 0; i < MAX; i++)
        path[i].clear();
    tempPath.clear();
    bestPath.clear();
    fill(visit, visit + MAX, 0);
    fill(dist, dist + MAX, INF);

    dist[start] = 0;

    /*
    for( int i = 0; i < MAX; i++ ) {
        int u = -1, MIN = INF;
        for( int j = 0; j < MAX; j++ ) {
            if( !visit[j] && dist[j] < MIN ) {
                u = j;
                MIN = dist[j];
            }
        }
        if( u == -1 ) return;
        visit[u] = 1;
        for( int j = 0; j < MGraph[u].size(); j++ ) {
            int v = MGraph[u][j];
            if( !visit[v] && dist[u] + 1 < dist[v] ) {
                dist[v] = dist[u] + 1;
                path[v].clear();
                path[v].push_back( u );
            }
            else if( !visit[v] && dist[u] + 1 == dist[v] ) {
                path[v].push_back( u );
            }
        }
    }
    */

    priority_queue<Node, vector<Node>, greater<Node>> q;
    Node node;
    node.u = start;
    node.value = dist[start];
    q.push(node);
    while (!q.empty())
    {
        Node cur = q.top();
        q.pop();
        int u = cur.u;
        if (visit[u])
            continue;
        visit[u] = 1;
        for (int j = 0; j < MGraph[u].size(); j++)
        {
            int v = MGraph[u][j];
            if (!visit[v] && dist[u] + 1 < dist[v])
            {
                dist[v] = dist[u] + 1;
                path[v].clear();
                path[v].push_back(u);
                Node node;
                node.u = v;
                node.value = dist[v];
                q.push(node);
            }
            else if (!visit[v] && dist[u] + 1 == dist[v])
            {
                path[v].push_back(u);
            }
        }
    }
}

void dfs(int v, int s)
{
    if (v == s)
    {
        tempPath.push_back(s);
        int pre = -1;
        int sum = 0;
        vector<int> curPath;
        for (int i = 0; i < tempPath.size() - 1; i++)
        {
            int a = tempPath[i];
            int b = tempPath[i + 1];
            int cur = rote[a][b];
            if (cur != pre)
            {
                sum++;
                //printf( "%d\n", cur );
                //curPath.push_back( id );
            }
            pre = cur;
        }
        if (sum < cnt)
        {
            cnt = sum;
            bestPath = tempPath;
        }
        tempPath.pop_back();
        return;
    }

    tempPath.push_back(v);
    for (int i = 0; i < path[v].size(); i++)
    {
        dfs(path[v][i], s);
    }
    tempPath.pop_back();
}
int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        int m, id, pre, cur;
        scanf("%d", &m);
        pre = cur = -1;
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &cur);
            if (pre != -1)
            {
                MGraph[pre].push_back(cur);
                MGraph[cur].push_back(pre);
                rote[cur][pre] = rote[pre][cur] = i;
            }
            pre = cur;
        }
    }

    int q, start, end;
    scanf("%d", &q);

    for (int i = 0; i < q; i++)
    {
        scanf("%d%d", &start, &end);
        Dijkstra(start, end);
        dfs(end, start);
        if (dist[end] == INF)
        {
            printf("Sorry, no line is available.\n");
        }
        else
        {
            int len = bestPath.size();
            int pre = -1;
            printf("%d\n", dist[end]);
            for (int i = len - 1; i > 0; i--)
            {
                int a = bestPath[i];
                int b = bestPath[i - 1];
                int cur = rote[a][b];

                if (cur != pre)
                {
                    if (pre == -1)
                    {
                        printf("Go by the line of company #%d from %04d ", cur, a);
                    }
                    else
                    {
                        printf("to %04d.\n", a);
                        printf("Go by the line of company #%d from %04d ", cur, a);
                    }
                }
                //printf( "%d %d  %d\n", a, b, cur );
                pre = cur;
            }
            printf("to %04d.\n", bestPath[0]);
        }
    }
    return 0;
}