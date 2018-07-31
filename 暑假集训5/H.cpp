#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

long long n;

long long s[64];
struct node
{
    long long n, s;
};
vector<node> ans;

long long qpow(long long a, long long nn)
{
    long long ans = 1;
    while (nn > 0)
    {
        if (nn & 1)
            ans *= a;
        a *= a;
        nn /= 2;
    }
    return ans;
}

bool cmp(node a, node b)
{
    return a.n < b.n;
}

int main()
{
    int l = 56;
    cin >> n;
    for (int i = 1;; i++)
    {
        if (l <= 1)
        {
            if (ans.size() == 0)
            {
                cout << "impossible" << endl;
            }
            else
            {
                sort(ans.begin(), ans.end(), cmp);
                cout << ans[0].n << " " << ans[0].s << endl;
            }
            //system("pause");
            return 0;
        }
        for (int j = 2; j <= l; j++)
        {
            s[j] += qpow(i, j);
            //cout << j << " " << s[j] << endl;
            if (s[j] == n)
            {
                struct node tmp;
                tmp.n = j + 1;
                tmp.s = i;
                ans.push_back(tmp);
                l = j - 1;
                break;
            }
        }
        for (int j = 2; j <= l; j++)
        {
            if (qpow(i + 1, j) > n - s[j])
            {
                l = j - 1;
                break;
            }
        }
    }
    //system("pause");
    return 0;
}