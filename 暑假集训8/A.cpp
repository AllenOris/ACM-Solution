#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
int tot, n, m, nxt[N], dis[N], to[N], first[N], w[N], v, maxd, po;
int myans[N];
bool used[N];

void create(int x, int y, int z)
{
    nxt[tot] = first[x];
    to[tot] = y;
    w[tot] = z;
    first[x] = tot++;
}

void dfs(int u, int fa)
{
    used[u] = 1;
    for (int e = first[u]; e != -1; e = nxt[e])
    {
        v = to[e];
        if (v != fa)
        {
            dis[v] = dis[u] + w[e];
            if (dis[v] >= maxd)
            {
                maxd = dis[v];
                po = v;
            }
            dfs(v, u);
        }
    }
}
bool cmp(int tt, int ttt)
{
    return tt > ttt;
}
int main()
{
    //freopen("lx.in","r",stdin);
    int len = 0;
    memset(first, -1, sizeof(first));
    int x, y;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &x, &y);
        create(x, y, 1);
        create(y, x, 1);
    }
    for (int i = 0; i < n; i++)
    {
        if (used[i] == 0)
        {
            maxd = -1;
            po = i;
            used[i] = 1;
            dis[i] = 0;
            dfs(i, -1);
            maxd = -1;
            dis[po] = 0;
            dfs(po, -1);
            myans[len++] = maxd;
        }
    }
    sort(myans, myans + len, cmp);

    if (len == 1)
        cout << myans[0] << endl;
    else if (len == 2)
        cout << max(myans[0], (myans[0] + 1) / 2 + 1 + (myans[1] + 1) / 2) << endl;
    else
        cout << max(myans[0], max((myans[0] + 1) / 2 + 1 + (myans[1] + 1) / 2, (myans[1] + 1) / 2 + 2 + (myans[2] + 1) / 2)) << endl;
    //system("pause");
    return 0;
}