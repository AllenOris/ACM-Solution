#include <bits/stdc++.h>

using namespace std;

int N, M;
long long a[1000005];
long long times[1000005];
long long ptimes[1000005];
const long long mod = 1e9 + 7;

void init()
{
    times[0] = 1;
    for (int i = 1; i <= 1000005; i++)
    {
        times[i] = times[i - 1] * i % mod;
    }
}

long long qpow(long long b, long long c)
{
    long long tmpans = 1;
    while (c)
    {
        if (c & 1)
        {
            tmpans = tmpans * b % mod;
        }
        b = b * b % mod;
        c >>= 1;
    }
    return tmpans;
}

long long getp(long long s)
{
    return qpow(s, mod - 2);
}

int main()
{
    init();
    while (scanf("%d", &N) != -1)
    {
        long long ans = 1;
        long long sum = 0;
        for (int i = 0; i < N; i++)
        {
            long long c;
            scanf("%lld", &c);
            sum += c;
            ans = ans * getp(times[c]) % mod;
        }
        printf("%lld\n", times[sum] * ans % mod);
    }

    return 0;
}