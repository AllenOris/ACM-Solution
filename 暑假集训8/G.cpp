#include <bits/stdc++.h>

using namespace std;

int n, m;
struct node
{
    int x, y;
    bool used = 0;
} p[100005];
bool cmp(node a,node b)
{
    if(a.x==b.x)return a.y<b.y;
    return a.x < b.x;
}
struct node1
{
    int x, y, r;
} w[100005];

inline bool dis(int a, int b)
{
    return (p[a].x - w[b].x) * (p[a].x - w[b].x) + (p[a].y - w[b].y) * (p[a].y - w[b].y) <= w[b].r * w[b].r;
}

int main()
{
    int ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &p[i].x, &p[i].y);
        p[i].used = 0;
    }
    sort(p, p + n,cmp);
   
        cin >> m;
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &w[i].x, &w[i].y, &w[i].r);
    }
    for (int i = 0; i < m; i++)
    {
        int xl = w[i].x - w[i].r;
        int xr = w[i].x + w[i].r;
        int ll = 0, lr = n - 1;
        while (ll < lr)
        {
            int mid = (ll + lr) / 2;
            if (p[mid].x >= xl)
                lr = mid;
            else
                ll = mid + 1;
        }
        int rl = 0, rr = n - 1;
        while (rl < rr-1)
        {
            int mid = (rl + rr) / 2;
            //cout<<mid<<endl;
            if (p[mid].x > xr)
                rr = mid-1;
            else
                rl = mid ;
        }
        while(p[rl].x<=xr) rl++;
        for (int j = ll; j <= rl; j++)
        {
            if (p[j].used == 0 && dis(j, i))
            {
                p[j].used = 1;
            }
        }
    }
    ans = n;
    for (int i = 0; i < n; i++)
    {
        if (p[i].used)
            ans--;
    }
    cout << ans << endl;
    return 0;
}