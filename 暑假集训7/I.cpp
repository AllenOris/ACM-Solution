#include <bits/stdc++.h>

using namespace std;

int N, M;
long long f[200][200];
long long dp[2][200];
long long ff[200][200];

int main()
{
    while (scanf("%d %d", &N, &M) != -1)
    {
        memset(dp, 0, sizeof(dp));
        memset(f, 0, sizeof(f));
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < M; j++)
            {
                scanf("%lld", &f[i][j]);
            }
        }
        if (N <= M)
        {
            for (int i = 0; i < N - 1; i++)
                for (int j = 0; j < M; j++)
                    for (int k = 0; k < M; k++)
                        dp[i % 2][j] = max(dp[i % 2][j], dp[(i + 1) % 2][k] + f[k][j]);

            long long ans = -1;
            for (int j = 0; j < M; j++)
            {
                ans = max(ans, dp[(N - 2) % 2][j]);
            }
            printf("%lld\n", ans);
        }
        else
        {
            for (int i = 0; i < M; i++)
                for (int j = 0; j < M; j++)
                    for (int k = 0; k < M; k++)
                        dp[i % 2][j] = max(dp[i % 2][j], dp[(i + 1) % 2][k] + f[k][j]);
            
        }
    }

    return 0;
}