#include <algorithm>
#include <bitset>
#include <climits>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stack>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

#define LS 2 * i
#define RS 2 * i + 1
#define UP(i, x, y) for (i = x; i <= y; i++)
#define DOWN(i, x, y) for (i = x; i >= y; i--)
#define MEM(a, x) memset(a, x, sizeof(a))
#define W(a) while (a)
#define gcd(a, b) __gcd(a, b)
#define LL long long
#define N 200000
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define EXP 1e-8
int wa[N], wb[N], wsf[N], wv[N], sa[N];
int myrank[N], height[N], s[N], a[N];
char str[N], str1[N], str2[N];
//sa:字典序中排第i位的起始位置在str中第sa[i]
//myrank:就是str第i个位置的后缀是在字典序排第几
//height：字典序排i和i-1的后缀的最长公共前缀
int cmp(int *r, int a, int b, int k)
{
    return r[a] == r[b] && r[a + k] == r[b + k];
}
void getsa(int *r, int *sa, int n, int m) //n要包含末尾添加的0
{
    int i, j, p, *x = wa, *y = wb, *t;
    for (i = 0; i < m; i++)
        wsf[i] = 0;
    for (i = 0; i < n; i++)
        wsf[x[i] = r[i]]++;
    for (i = 1; i < m; i++)
        wsf[i] += wsf[i - 1];
    for (i = n - 1; i >= 0; i--)
        sa[--wsf[x[i]]] = i;
    p = 1;
    j = 1;
    for (; p < n; j *= 2, m = p)
    {
        for (p = 0, i = n - j; i < n; i++)
            y[p++] = i;
        for (i = 0; i < n; i++)
            if (sa[i] >= j)
                y[p++] = sa[i] - j;
        for (i = 0; i < n; i++)
            wv[i] = x[y[i]];
        for (i = 0; i < m; i++)
            wsf[i] = 0;
        for (i = 0; i < n; i++)
            wsf[wv[i]]++;
        for (i = 1; i < m; i++)
            wsf[i] += wsf[i - 1];
        for (i = n - 1; i >= 0; i--)
            sa[--wsf[wv[i]]] = y[i];
        t = x;
        x = y;
        y = t;
        x[sa[0]] = 0;
        for (p = 1, i = 1; i < n; i++)
            x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
    }
}
void getheight(int *r, int n) //n不保存最后的0
{
    int i, j, k = 0;
    for (i = 1; i <= n; i++)
        myrank[sa[i]] = i;
    for (i = 0; i < n; i++)
    {
        if (k)
            k--;
        else
            k = 0;
        j = sa[myrank[i] - 1];
        while (r[i + k] == r[j + k])
            k++;
        height[myrank[i]] = k;
    }
}
int t, ans, n, m;

int main()
{
    int i, j, k, len;
    int n;
    cin >> n >> s[0];
    len = 1;
    while (len <= n)
    {
        getsa(s, sa, len + 1, 46668);
        getheight(s, len);
        ans = (1 + len) * len / 2;
        UP(i, 2, len)
        ans -= height[i];
        printf("%d\n", ans);
        s[len] = s[len - 1] * ans % 23333 + 1;
        len++;
    }
}
