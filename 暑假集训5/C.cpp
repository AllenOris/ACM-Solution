#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

int map[2000][2000];
int n, m;
int in[2000];
int out[2000];
int dp[2000];
int s = 1500, t = 1501;
bool used[2000];

struct E
{
    int v, next, to;
} e[10050];

int head[2000],cnt;
void add(int a,int b,int c)
{
    e[cnt].to = b;
    e[cnt].next = head[a];
    e[cnt].v = c;
    head[a] = cnt++;
}

queue<int> que;

int main()
{
    memset(head, -1, sizeof(head));
    memset(dp, -1, sizeof(dp));
    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        add(a, b, c);
        in[b]++;
        out[a]++;
    }
    for (int i = 0; i < n; i++)
    {
        if (in[i + 1] == 0)
        {
            add(s, i + 1, 0);
        }
        if (out[i + 1] == 0)
        {
            add(i+1, t, 0);
        }
    }
    dp[s] = 0;
    que.push(s);
    while (!que.empty())
    {
        int tmp = que.front();
        que.pop();
        used[tmp] = 0;
        for (int i = head[tmp]; i != -1; i=e[i].next)
        {
            int to = e[i].to;
            int v = e[i].v;
            if ( dp[tmp] + v >= dp[to])
            {
                dp[to] = dp[tmp] + v;
                if (used[to] == 0)
                {
                    que.push(to);
                    used[to] = 1;
                }
            }
        }
    }

        cout << dp[t] << endl;

    //system("pause");
    return 0;
}