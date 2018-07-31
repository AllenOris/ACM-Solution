# L-Largest Point

> 题目链接：[https://nanti.jisuanke.com/t/29131](https://nanti.jisuanke.com/t/29131)
>
> 题解作者：[DeAllen](https://github.com/AllenTaken)

## 题意

给定数列ti，整数a,b，求a\*ti^2+b\*tj的最大值(i &ne; j)

## 解析

水题，贪心求ti^2与j的最大值和次大值，记录i,j，如果i,j不想等则最大值相加，如果相等，则一个最大值加另一个的次大值

## 代码

```c++
#include <bits/stdc++.h>
using namespace std;
#define f(i,a,b) for(i=a;i<=b;++i)
#define rf(i,a,b) for(i=a;i>=b;--i)
#define mem(a,n) memset(a,n,sizeof(a))
#define copy(a,b) memcopy(a,b,sizeof(b))
const long long INF=4e18;
const double E=exp(1.0);
const double Pi=4*atan(1.0);

void solve(long long );

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long i, t;
    cin>>t;
    f(i,1,t)
        solve(i);
    return 0;
}

const long long N=5e6+5;
long long a[N];

void solve(long long t){
    cout<<"Case #"<<t<<": ";
    long long n,x,y;
    cin>>n>>x>>y;
    long long i,j;
    long long max1,max2,max3,max4;
    max1=max2=max3=max3=-INF;
    long long point1,point2;
    f(i,1,n){
        cin>>a[i];
        long long p1=x*a[i]*a[i];
        long long p2=y*a[i];
        if(p1>=max1){
            max2=max1;
            max1=p1;
            point1=i;
        }
        else if(p1>=max2){
            max2=p1;
        }
        if(p2>=max3){
            max4=max3;
            max3=p2;
            point2=i;
        }
        else if(p2>=max4){
            max4=p2;
        }
    }
    if(point1!=point2)
        cout<<max1+max3;
    else
        cout<<max(max1+max4,max2+max3);
    cout<<endl;
}

```



