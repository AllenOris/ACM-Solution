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

long long dp[1600];
int n;
long long s[1600];
long long l[1600];
long long tl[1600];
long long stl[1600];

long long mymin(long long a, long long b)
{
	return a < b ? a : b;
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		memset(dp, 0x7f, sizeof(dp));
		memset(l, 0, sizeof(l));
		memset(tl, 0, sizeof(tl));
		memset(s, 0, sizeof(s));
		memset(stl, 0, sizeof(stl));	
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &l[i]);
			tl[i] = i * l[i];
			s[i] = l[i] + s[i - 1];
			stl[i] = stl[i - 1] + tl[i];
		}
		dp[0] = 0;
		for (int i = 0; i <= n; i++)
		{
			for (int j = 0; j < i; j++)
			{
				dp[i] = mymin( dp[i], dp[j] + i * s[i]- stl[i] + s[n] - s[i] );
				
			}
		}
		cout << dp[n] << endl;
	}
	return 0;
}