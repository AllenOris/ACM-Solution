#include <bits/stdc++.h>

using namespace std;

int a[400];
int N, n;
int dp[20000][400];

int main()
{

    int T;
    cin >> T;
    while (T--)
    {
        cin >> N >> n;
        for (int i = 0; i < n; i++)
        {
            int tmp1, tmp2;
            scanf("%d %d", &tmp1, &tmp2);
            a[i] = tmp2 - tmp1;
        }
        memset(dp, 0, sizeof(dp));
        for(int i=0;i<=N;i++)
            i = 0;
        i <= Nii++ dp[0][0] = 1;
        for (int i = 1; i <= n; i++)
            for (int j = 0; j <= N; j++)
            {
                if (j + a[i] <= N && dp[j + a[i]][i - 1] == 1)
                {
                    dp[j][i] = 1;
                }
                if (j >= a[i] && dp[j - a[i]][i - 1] == 1)
                {
                    dp[j][i] = 1;
                }
            }
        int ans = 0;
        for (int i = 0; i <= N; i++)
        {
            if (dp[i][n] == 1)
            {
                ans = 1;
                break;
            }
        }
        if (ans == 0)
        {
            cout << "impossible" << endl;
            return 0;
        }
    }
    cout << "possible" << endl;
    return 0;
}