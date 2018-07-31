#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n;
vector<int> E[1050];
queue<int> que;
int v[1050];
int r[1050];
int c[1050];
int used[1050];
int map[1050][1050];
int l;

void de(int u)
{
    int now = u;
    if (E[now].size() == 0)
    {
        used[now] = 1;
        l--;
        return;
    }
    int tmp = now;
    used[now] = 1;
    l--;
    int tt = -1;
    for (int i = E[now].size() - 1; i >= 0;i--)
    {
        if(used[E[now][i]]==0)
        {
            tt = E[now][i];
            break;
        }
    }
    if(tt==-1)
    {
        E[now].clear();
        return;
    }
    r[tt]--;
    for (int i = 0; i < E[tmp].size(); i++)
    {
        if(used[E[tmp][i]]==0)
        r[E[tmp][i]]--;
    }
    E[tmp].clear();
    de(tt);
}

int main()
{
    int ans = 0;
    cin >> n;
    l = n;
    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        for (int j = 0; j < a; j++)
        {
            int tmp;
            scanf("%d", &tmp);
            E[i].push_back(tmp);
            r[tmp]++;
            c[i]++;
        }
    }
    while (l)
    {
        for (int i = 0; i < n; i++)
        {
            if (used[i] == 0 && r[i] == 0)
            {
                ans++;
                que.push(i);
            }
        }
        while (!que.empty())
        {
            int i = que.front();
            que.pop();
            de(i);
        }
    }
    cout << ans << endl;
    return 0;
}