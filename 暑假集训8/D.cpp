#include <bits/stdc++.h>

using namespace std;

int n, k;
int a[100005];
int b[200005];

int main()
{
    int ans = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    int tmp;
    int j=0;
    for (int i = 0; i < n; )
    {
        tmp = 1;
        for (j = i + 1;j<n; j++)
        {
            if (a[j] - a[i] < 1000)
            {
                tmp++;
            }
            else
               {
                   ans = max(ans, tmp);
                   break;
               } 
        }
        i=j;
    }
    
	ans=max(ans,tmp);
    //cout<<ans<<endl;
    if (ans % k==0)
        cout << ans / k << endl;
    else
        cout << ans / k + 1 << endl;

    return 0;
}