#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> ans[10];
char s[10][2] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
int main()
{
    int m;
    cin >> m;
    ans[2].push_back("12");
    ans[2].push_back("21");
    if (m == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    if (m == 2)
    {
        cout << "1 2" << endl;
        cout << "2 1" << endl;
        return 0;
    }
    // cout << ans[2].size() << endl;
    for (int i = 3; i <= m; i++)
    {
        int l = 0;
        for (auto j : ans[i - 1])
        {
            auto tmp = j;
            l++;
            if (l % 2 == 1)
            {
                for (int k = j.length(); k >= 0; k--)
                {
                    ans[i].push_back(tmp.insert(k, s[i]));
                    //cout << tmp << endl;
                    tmp = j;
                }
            }
            //cout << j.insert(j.length(),s[0]) << endl;
            else
                for (int k = 0; k <= j.length(); k++)
                {
                    ans[i].push_back(tmp.insert(k, s[i]));
                    //cout << tmp << endl;
                    tmp = j;
                }
        }
    }
    // cout << ans[2].size() << endl;
    for (auto i : ans[m])
    {
        for (auto j : i)
            if (j != i[i.length() - 1])
                cout << j << " ";
            else
                cout << j;
        cout << endl;
    }
    //system("pause");
    return 0;
}