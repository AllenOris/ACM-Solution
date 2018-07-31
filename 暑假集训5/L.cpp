#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

int h, w;

int map[200][200];
char ans[200][200];
int map2[200][200];

int main()
{
    cin >> h >> w;
    h += 2;
    w += 2;

    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
        {
            scanf("%d", &map[i][j]);
        }
    for (int i = 0; i < 200; i++)
    {
        for (int j = 0; j < 200; j++)
        {
            map2[i][j] = map[i][j];
        }
    }
    for (int i = 0; i < h - 1; i++)
        for (int j = 0; j < w - 1; j++)
        {
            if (map[i][j] == 0)
            {
                ans[i + 1][j + 1] = '.';
                continue;
            }
            if (map[i][j] == 1)
            {
                ans[i + 1][j + 1] = 'X';
                map[i + 1][j + 1]--;
                map[i][j]--;
                map[i][j + 1]--;
                map[i + 1][j]--;
                if (i + 2 < h)
                {
                    map[i + 2][j]--;
                    map[i + 2][j + 1]--;
                }
                if (j + 2 < w)
                {
                    map[i][j + 2]--;
                    map[i + 1][j + 2]--;
                }
                if (i + 2 < h && j + 2 < w)
                {
                    map[i + 2][j + 2]--;
                }
                continue;
            }
            cout << "impossible" << endl;
            // system("pause");
            return 0;
        }
    memset(map, 0, sizeof(map));

    for (int i = 1; i < h-1; i++)
    {
        for (int j = 1; j < w-1; j++)
        {
            if(ans[i][j]=='X')
            {
                map[i][j]++;
                map[i+1][j]++;
                map[i+1][j+1]++;
                map[i][j+1]++;
                map[i-1][j]++;
                map[i][j-1]++;
                map[i-1][j+1]++;
                map[i+1][j-1]++;
                map[i-1][j-1]++;
            }
        }
    }
     for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if(map[i][j]!=map2[i][j])
            {
                cout << "impossible" << endl;
            // system("pause");
            return 0;
            }
        }
    }
    for (int i = 1; i < h - 1; i++)
    {
        for (int j = 1; j < w - 1; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    // system("pause");
    return 0;
}