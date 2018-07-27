#include <bits/stdc++.h>
using namespace std;

int n, m, k;

int mymap[505][505];
int map1[505][505];
long long ans;
int sum;

void test()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            map1[i][j] = mymap[i][j];
        }
    for (int i = 0; i < k; i++)
    {
        int x1 = rand() % n;
        int x2 = rand() % n;
        int y1 = rand() % m;
        int y2 = rand() % m;
        if (x1 > x2)
        {
            int t = x2;
            x2 = x1;
            x1 = t;
        }
        if (y1 > y2)
        {
            int t = y2;
            y2 = y1;
            y1 = t;
        }
        for (int j = x1; j <= x2; j++)
            for (int l = y1; l <= y2; l++)
            {
                map1[j][l] = 0;
            }
    }
    long long tmpans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            tmpans += map1[i][j];
        }
    ans += sum - tmpans;
}

int main()
{
    int T;
    int S;
    srand((unsigned int)time(0));

    cin >> T;
    int TT = T;
    while (T--)
    {
        cin >> n >> m >> k;
        ans = 0;
        S = 10000;
        sum = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                scanf("%d", &mymap[i][j]);
                sum += mymap[i][j];
            }

        for (int i = 0; i < S; i++)
        {
            test();
        }
        cout << "Case #" << TT - T << ": " << ans / S << endl;
    }
    return 0;
}
