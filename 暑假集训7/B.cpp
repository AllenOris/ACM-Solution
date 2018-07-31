#include <bits/stdc++.h>

using namespace std;

long long N, K;

const long long mod = 1e9 + 7;
struct ANS
{
    pair<long long, long long> q;
    int num;
    long long ans;
} q[5005];
long long dp[2][5005];

bool cmp(ANS a, ANS b)
{
    if (a.q.first == b.q.first)
        return a.q.second < b.q.second;
    return a.q.first < b.q.first;
}
bool cmp2(ANS a, ANS b)
{
    return a.num < b.num;
}

int main()
{
    long long I = 0;
    while (~scanf("%lld%lld", &N, &K))
    {
        q[I].q = {N, K};
        q[I].num = I;
        I++;
    }
    sort(q, q + I, cmp);
    long long k = 0;
    dp[0][0] = 1;
    for (long long i = 1; i <= 5001; i++)
        for (long long j = 0; j <= 5001; j++)
        {
            if (k >= I)
                break;
            if (j == 0)
            {
                dp[i % 2][j] = 1;
            }
            else if (j > i * (i - 1) / 2)
            {
                dp[i % 2][j] = 0;
            }
            else
            {
                if (j >= i)
                    dp[i % 2][j] = (dp[(i + 1) % 2][j] + dp[i % 2][j - 1] - dp[(i + 1) % 2][j - i] + mod) % mod;
                else
                    dp[i % 2][j] = (dp[(i + 1) % 2][j] + dp[i % 2][j - 1]) % mod;
            }

            if (q[k].q.first == i && q[k].q.second == j)
            {
                
                q[k].ans = dp[i % 2][j];
                k++;
                //printf("%lld\n", dp[i % 2][j]);
            }
        }
    sort(q, q + I, cmp2);
    for (int i = 0; i < I; i++)
    {
        printf("%lld\n", q[i].ans);
    }
    return 0;
}