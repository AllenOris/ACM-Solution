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
long long n;
long long F[51];
int len;

struct P
{
    long long x, y;
} p[200];

long long exGcd(long long a, long long b, long long &x, long long &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    long long r = exGcd(b, a % b, x, y);
    long long t = x;
    x = y;
    y = t - a / b * y;
    return r;
}

void init()
{
    int i = 2;
    F[0] = F[1] = 1;
    do
    {
        F[i] = F[i - 1] + F[i - 2];
    } while (F[i++] < 200000000LL);
    len = i;
    for (int j = 1; j < len; j++)
    {
        exGcd(F[j - 1], F[j], p[j].x, p[j].y);
    }
}

int main()
{
    long long T;
    init();
    cin >> T;
    while (T--)
    {
        long long a = 0, b = 999999999LL;
        cin >> n;
        for (int i = 1; i < len; i++)
        {
            long long c = (n * p[i].x - n *p[i].y) / (F[i - 1] + F[i]);
            long long x = n * p[i].x - c * F[i];
            long long y = n * p[i].y + c * F[i - 1];
            if(x>y)
            {
                x -= F[i];
                y += F[i - 1];
            }
            if(y<=0||x<=0)
                continue;
            //cout << x << " " << y << endl;
            if(y<b)
            {
                a = x;
                b = y;
            }
            else if(y==b&&a<=x)
            {
                a = x;
                b = y;
            }
        }
        cout << a << " " << b << endl;
    }
    //getchar();
    return 0;
}