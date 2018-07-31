#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[2][400];
int max0 = -1, max1 = -1;

bool judge(int w)
{
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[0][i]);
        max0 = max(max0, a[0][i]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[1][i]);
        max1 = max(max1, a[0][i]);
    }

    int l = 0, r = (max0 + max1) * m;
    while (l != r)
    {
        int mid = (l + r) / 2;
        if (judge(mid))
        {
            r = mid;
        }
        else
            l = mid + 1;
    }
    cout << l << endl;

    return 0;
}
