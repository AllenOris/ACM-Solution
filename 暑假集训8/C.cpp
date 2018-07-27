#include<bits/stdc++.h>

using namespace std;
string s;
char t[4] = {'P', 'E', 'R'};


int main()
{
    int ans = 0;
    cin>>s;
    for (int i = 0; i < s.length();i++)
    {
        if(s[i]!=t[i%3])
        {
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}