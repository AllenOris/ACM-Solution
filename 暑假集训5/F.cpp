#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>

using namespace std;

int F[50];
int n;
int h[2000000];

struct node
{
    long long num;
    long long index;
} a[200000];
struct ans
{
    int l, r;
} Tmin;
int len = 0;
int len1 = 0;

bool cmp(node c, node d)
{
    return c.num < d.num;
}

bool cmp1(ans c, ans d)
{
    if (c.l == d.l)
    {
        return c.r < d.r;
    }
    return c.l < d.l;
}

int main()
{
    F[0] = 0;
    F[1] = 1;
    h[1] = 1;
    for (int i = 2;; i++)
    {
        F[i] = F[i - 1] + F[i - 2];
        if (F[i] > 2000000)
            break;
        h[F[i]] = i;
    }
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int b;
        scanf("%d", &b);
        if (h[b] != 0)
        {
            a[len1].num = b;
            a[len1].index = i + 1;
            len1++;
        }
    }
    n = len1;
    int j = 1;
    sort(a, a + n, cmp);
    for (int i = 0; i < n - 1; i++)
    {
        for ( ; j < n; j++)
        {
            if (a[j].num > F[h[a[i].num] + 1])
            {
                break;
            }
            if (a[j].num == a[i].num && a[i].num != 1)
            {
                continue;
            }
            cout << a[i].index << " " << a[j].index << endl;
            return 0;
        }
    }
    cout << "impossible" << endl;
    return 0;
}