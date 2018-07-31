#include <algorithm>
#include <iostream>
#include <map>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const int maxn = 2005;
ll C[maxn][maxn];
void init()
{
    C[0][0] = 1;
    C[1][0] = C[1][1] = 1;
	for (int i = 2; i < maxn; i++){
		C[i][0] = 1;
		for (int j = 1; j < maxn; j++)
			C[i][j] = (C[i-1][j] + C[i - 1][j - 1])%mod;
	}
}
int main()
{
    init();
    int n, m;
    while (~scanf("%d%d", &n, &m))
    {
        //printf("%lld\n",dp[2][2]);
        if (n == 2 || m == 2)
            printf("1\n");
        else
            printf("%lld\n", ((C[ m + n - 4][n-2] * C[ m + n - 4][n-2]) % mod - C[n+m-1 - 3][n -3] * C[n - 1+m-3][n -1]%mod + mod) % mod);
    }
}