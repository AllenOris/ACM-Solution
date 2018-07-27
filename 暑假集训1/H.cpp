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
const int N = 300005;
int a[N], b[N], tiezhi[N]; //小到大
int n, s, f, k;
int tb[N];


int dotest(int mid)
{
	if (mid == n - f)
		return 1;

	int lb = n - f;
	int sbb = k - f;
	for (int i = 0; i < N-1; i++)
	{
		tb[i] = b[i];
	}
	int i = sbb - 1, j = lb - 1;
	for (i = sbb - 1; i >= max(0, sbb - mid - 1); i--, j--)
		tb[j] += tiezhi[i];
	const int ttt = i;
	for (int t = ttt; t >= 0; t--)
		tb[ttt - t] += tiezhi[t];
	sort(tb, tb + lb);
	int vb = tb[lb - mid - 1];
	int vis = sbb;
	int ans = 0;
	for (int jj = f - 1; jj >= 0; jj--)
	{
		while (vis < k)
		{
			if (tiezhi[vis] + a[jj] >= vb)
			{
				ans++;
				vis++;
				break;
			}
			else
				vis++;
		}
	}
	if (ans >= s - mid)
		return 1;
	else
		return 0;
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(tiezhi, 0, sizeof(tiezhi));
		scanf("%d%d%d", &n, &s, &f);
		for (int i = 0; i < f; i++)
			scanf("%d", &a[i]);
		for (int i = 0; i < n - f; i++)
			scanf("%d", &b[i]);
		scanf("%d", &k);
		for (int i = 0; i < k; i++)
			scanf("%d", &tiezhi[i]);
		sort(a, a + f);
		sort(b, b + n - f);
		sort(tiezhi, tiezhi + k);
		int mid, l = 0, r = min(s, n - f);
		while (l != r)
		{
			mid = (l + r) / 2;
			if (dotest(mid) == 1)
			{
				r = mid;
			}
			else
				l = mid + 1;
		}
		printf("%d\n", s - l);
	}
	return 0;
}
