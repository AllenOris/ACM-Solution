# B-Temmo's hard problem

> 题库链接：[https://nanti.jisuanke.com/t/29204](https://nanti.jisuanke.com/t/29204)

> 题解作者: [DeAllen](https://github.com/AllenTaken)

# 题意

一个序列只有1和2，给定一个操作，可以将[l,r]处序列完全翻转，让你选定l,r，使得翻转后的最长不下降子序列最长。

## 解析

是水题，但水题也能看出人与人的差距，比如我与昕神的差距。

n是2000，就想打一发暴力，穷举l,r，O(1)求最长不下降序列长度。为了达到O(1)，预处理每个点前面的1有多少，后面的2有多少，在跑一遍dp，求所有区间最长不上升子序列长度。所以每次翻转[l,r]后的最长不降长即为l前面的个数+r后面2的个数+[l,r]间最长不上升序列长。

让昕神给了数据测，没过，然后开始Debug。然后昕神想出了O(n)的做法，很神奇，她刚开始打，然后我a了。。

```c++
#include <bits/stdc++.h>
using namespace std;

#define io_speedup ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define f(i,a,b) for(i=a;i<=b;++i)
#define rf(i,a,b) for(i=a;i>=b;--i)
#define mem(a,n) memset(a,n,sizeof(a))
#define copy(a,b) memcpy(a,b,sizeof(b))
const int INF=~(1<<31);

const double E=exp(1.0);
const double Pi=4*atan(1.0);

const int N=2005;
int dp[N][N];
int a[N];
int one[N];
int two[N];
int front_two[N];
int main()
{
    io_speedup
    int T;
    cin>>T;
	int i, j;
	while(T--){
        int n;
        cin>>n;
        mem(one,0);mem(two,0);mem(a,0);mem(dp,0);mem(front_two,0);
        f(i,1,n)cin>>a[i];
        f(i,1,n){
            if(a[i]==1)one[i]=one[i-1]+1;
            else one[i]=one[i-1];
            if(a[i]==2)front_two[i]=front_two[i-1]+1;
            else front_two[i]=front_two[i-1];
        }
        rf(i,n,1)if(a[i]==2)two[i]=two[i+1]+1;
            else two[i]=two[i+1];
        f(i,1,n){
            dp[i][i]=1;
            f(j,i+1,n){
                if(a[j]==1)dp[i][j]=dp[i][j-1]+1;
                else dp[i][j]=max(dp[i][j-1],front_two[j]-front_two[i-1]);
            }
        }
        int ans=-1;
        f(i,1,n){
            ans=max(ans,one[i]+two[i]);
        }
        f(i,1,n-1)
            f(j,i+1,n){
                ans=max(ans,one[i-1]+dp[i][j]+two[j+1]);
            }
        cout<<ans<<endl;
	}
	return 0;
}
```

这是O(n^2)解法，想知道O(n)的做法就看昕神的题解，不知道她会不会写。





