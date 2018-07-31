#include <bits/stdc++.h>
using namespace std;

int n, r;
priority_queue<int> que;
int a[3000];
int sum, mymax = -1;
int tmp[3000];

bool judge(int w)
{
    memset(tmp, 0, sizeof(tmp));

    for (int i = n - 1; i >= 0; i--)
    {
        int flag = 1;
        //sort(tmp, tmp + r);
        for (int j = 0; j <r ; j++)
        {
            if (w - tmp[j] >= a[i])
            {
                tmp[j] += a[i];
                flag = 0;
                break;
            }
        }
        if (flag)
            return false;
    }
    return true;
}

int main()
{
    cin >> n >> r;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    sort(a, a + n);

    int l = a[n - 1];
    int r = sum;
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
