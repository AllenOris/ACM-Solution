# K-Temmo's reunited

>题库链接： [https://nanti.jisuanke.com/t/29326](https://nanti.jisuanke.com/t/29326)

>题解作者：[DeAllen](https://github.com/AllenTaken)

# 题意

二维平面上n(n<1e5)个点，找到一个点，使得其他点到该点的曼哈顿距离之和最短。

## 解析

dp

想一下这个事情，将点按x排序，一个点和它所有左边点x方向的差为dp[i-1]，那么一定满足dp[i]=dp[i-1]+(x[i]-x[i-1]*i)

x右侧相同，y方向也相同，所以扫四次即可，最好加起来求个最小值。

## ac代码

```c++
#include <bits/stdc++.h>
using namespace std;

#define io_speedup ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define f(i,a,b) for(i=a;i<=b;++i)
#define rf(i,a,b) for(i=a;i>=b;--i)
#define mem(a,n) memset(a,n,sizeof(a))
#define copy(a,b) memcpy(a,b,sizeof(b))
const long long INF=~(1<<31);

const double E=exp(1.0);
const double Pi=4*atan(1.0);

const long long N=1e5+5;
struct Point{
    long long x,y;
    long long num;
    bool operator<(const Point&T)const{
        if(x!=T.x)return x<T.x;
        return y<T.y;
    }
}a[N];
bool cmp(const Point&A,const Point&B){
    if(A.y!=B.y)return A.y<B.y;
    return A.x<B.x;
}
long long sumx[N];
long long sumy[N];

int main()
{
    io_speedup
    long long n;
    cin>>n;
	long long i, j;
    f(i,0,n-1){
        cin>>a[i].x>>a[i].y;
        a[i].num=i;
    }
    sort(a,a+n);
    //x左
    long long temp=0;
    f(i,1,n-1){
        long long p=a[i].num;
        temp=temp+(a[i].x-a[i-1].x)*i;
        sumx[p]+=temp;
    }
    //x右
    temp=0;
    rf(i,n-2,0){
        long long p=a[i].num;
        temp=temp+(a[i+1].x-a[i].x)*(n-1-i);
        sumx[p]+=temp;
    }
    sort(a,a+n,cmp);
    //y下
    temp=0;
    f(i,1,n-1){
        long long p=a[i].num;
        temp=temp+(a[i].y-a[i-1].y)*i;
        sumy[p]+=temp;
    }
    //y上
    temp=0;
    rf(i,n-2,0){
        long long p=a[i].num;
        temp=temp+(a[i+1].y-a[i].y)*(n-1-i);
        sumy[p]+=temp;
    }

    long long ans=sumx[0]+sumy[0];
    f(i,1,n-1){
        ans=min(ans,sumx[i]+sumy[i]);
    }
    cout<<ans<<endl;
	return 0;
}

```



