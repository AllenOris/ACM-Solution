#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>

using namespace std;

int n, k, ans = 0;
string s[100];
int snum[100];
int num[100];
string anss;
int now;
int l;
long long K = 0;
int flag = 1;
int tflag = 1;
int fflag = 0;
int tff = 0;

int stringtoint(string nows)
{
    int tmpans = 0;
    for (int i = k - 1; i >= 0; i--)
    {
        tmpans = tmpans * 2 + nows[i] - '0';
    }
    return tmpans;
}

string inttostring(int nows)
{
    string ansss = "";
    for (int i = 0; i < k; i++)
    {
        if (nows & 1)
        {
            ansss += "1";
        }
        else
            ansss += "0";
        nows >>= 1;
    }
    return ansss;
}

inline int count(int a, int b)
{
    int c = a ^ b;
    int tmpans = 0;
    while (c)
    {
        if (c & 1)
        {
            tmpans++;
        }
        c >>= 1;
    }
    return k - tmpans;
}

void dfs()
{
    flag = 1;
    tflag = 1;
    fflag = 0;
    tff = 0;
    for (int i = 0; i < n; i++)
    {
        int tmp = l - (k - count(now, snum[i] >> (k - l)));

        if (tmp > num[i] || tmp + k - l < num[i])
        {
            flag = 0;
            break;
        }
        if (tmp == num[i])
        {
            fflag = 1;
            tff = i;
        }
        if (tmp != num[i])
        {
            tflag = 0;
        }
    }
    if (flag == 0)
    {
        return;
    }
    if (l == k)
    {
        if (tflag == 1)
        {
            ans++;
            if(ans==1)
            {
                anss = inttostring(now);
            }
        }
        return;
    }
    if (fflag == 1)
    {
        int tnow = now << (k - l);
        int tmptmp = snum[tff] & ( (1 << (k - l )) -1);
        tmptmp = ~tmptmp;
        tmptmp =tmptmp & ((1 << (k - l ))-1);
        tnow = tnow | tmptmp;
        int cnow = now;
        now = tnow;
        int cl = l;
        l = k;
        dfs();
        l = cl;
        now = cnow;
        return;
    }
    if (l <= k - 1)
    {
        int cnow = now;
        int cl = l;
        now = cnow * 2;
        l++;
        dfs();
        now = cnow * 2 + 1;
        dfs();
        now = cnow;
        l=cl;
    }
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        ans = 0;
        scanf("%d%d", &n, &k);
        for (int i = 0; i < n; i++)
        {
            cin >> s[i] >> num[i];
            snum[i] = stringtoint(s[i]);
        }
        now = 0;
        l = 0;
        K = 0;
        dfs();
        if (ans == 1)
        {
            cout << anss << endl;
        }
        else
        {
            printf("%d solutions\n", ans);
        }
    }
    return 0;
}