# Food Problem

> 题目链接：[https://nanti.jisuanke.com/t/29336](https://nanti.jisuanke.com/t/29336)
>
> 题解作者：[DeAllen](https://github.com/AllenTaken/)

## 题意

一些种类不同的甜点，有价值，有空间，有每种甜点个数；一些种类不同的卡车，有装载空间大小，有运输价值，有每种卡车个数。现在用卡车运甜点，每个甜点可以随意切开放到不同的卡车，问运输甜点价值>=P时，卡车运费的最小值。

## 题解

要求两遍多重背包，第一次求甜点的，当价值>=P时，背包的最小重量。

第二个是卡车背包，所谓卡车的承载重量其实是朴素背包的价值，卡车的运费其实是朴素背包的重量。

由于题目中指出该运费最多50000(有些强行的味道)，所以不如二分这个“重量”，求出每个对应“重量”下的最大"价值"，和第一次求出的背包最小重量相对比，得到结果

## 代码

运行时间：1472ms

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

const int N=205;
const int M=51000;
int total_e,total_w;
int des_e[N],des_s[N],des_n[N];
int tru_s[N],tru_v[N],tru_n[N];
int dp[M];
int n,m;

int solve();

int main()
{
    io_speedup
    int n;
    cin>>n;
	int i, j;
	f(i,1,n)
      {
          int x=solve();
          if(x==-1)cout<<"TAT";
          else cout<<x;
          cout<<"\n";
      }
	return 0;
}

int DessertSpace(int E){
    int i,j;
    f(i,0,M-1)dp[i]=INF;
    dp[0]=0;
    E+=100;
    f(i,0,n-1){
        int num=min(des_n[i],E/des_e[i]);
        for(int k=1;num>0;k*=2){
            if(k>num)k=num;
            num-=k;
            int e=des_e[i]*k;
            int w=des_s[i]*k;
            for(j=E;j>=e;--j){
                if(dp[j-e]!=INF)
                    dp[j]=min(dp[j],dp[j-e]+w);
            }
        }
    }
    int minw=INF;
    rf(i,E,E-100)
        minw=min(minw,dp[i]);
    return minw;
}

int TruckSpace(int cost){
    mem(dp,0);
    int i,j;
    f(i,0,m-1){
        int num=min(tru_n[i], cost/tru_v[i]);
        for(int k=1;num>0;k*=2){
            if(k>num)k=num;
            num-=k;
            int value=tru_v[i]*k;
            for(int j=cost;j>=value;--j)
                dp[j]=max(dp[j],dp[j-value]+tru_s[i]*k);
        }
    }
    int w=-1;
    f(i,0,cost)
        w=max(w,dp[i]);
    return w;
}

int solve(){
    int E;
    cin>>n>>m>>E;
    int i,j;
    total_e=0;
    total_w=0;
    f(i,0,n-1)
        cin>>des_e[i]>>des_s[i]>>des_n[i];
    f(i,0,m-1)
        cin>>tru_s[i]>>tru_v[i]>>tru_n[i];

    int space=DessertSpace(E);

    int l=1,r=50000,mid;
    if(TruckSpace(r)<space)return -1;
    while(l!=r){
        int mid=(l+r)>>1;
        if (TruckSpace(mid)>=space){
            r=mid;
        }
        else
            l=mid+1;
    }
    return l;
}
```



后来想了一下，其实根本不用二分，直接拿50000做背包重量，正常三重背包，最后就是求最小满足大于该甜点重量的卡车运费，如果二分，会重复算了很多

## 改进

运行时间：664ms

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

const int N=205;
const int M=51000;
int total_e,total_w;
int des_e[N],des_s[N],des_n[N];
int tru_s[N],tru_v[N],tru_n[N];
int dp[M];
int n,m;

int solve();

int main()
{
    io_speedup
    int n;
    cin>>n;
	int i, j;
	f(i,1,n)
      {
          int x=solve();
          if(x==-1)cout<<"TAT";
          else cout<<x;
          cout<<"\n";
      }
	return 0;
}

int DessertSpace(int E){
    int i,j;
    f(i,0,M-1)dp[i]=INF;
    dp[0]=0;
    E+=100;
    f(i,0,n-1){
        int num=min(des_n[i],E/des_e[i]);
        for(int k=1;num>0;k*=2){
            if(k>num)k=num;
            num-=k;
            int e=des_e[i]*k;
            int w=des_s[i]*k;
            for(j=E;j>=e;--j){
                if(dp[j-e]!=INF)
                    dp[j]=min(dp[j],dp[j-e]+w);
            }
        }
    }
    int minw=INF;
    rf(i,E,E-100)
        minw=min(minw,dp[i]);
    return minw;
}

int TruckSpace(int cost,int space){
    mem(dp,0);
    int i,j;
    f(i,0,m-1){
        int num=min(tru_n[i], cost/tru_v[i]);
        for(int k=1;num>0;k*=2){
            if(k>num)k=num;
            num-=k;
            int value=tru_v[i]*k;
            for(int j=cost;j>=value;--j)
                dp[j]=max(dp[j],dp[j-value]+tru_s[i]*k);
        }
    }
    int w=-1;
    f(i,0,cost)
        if(dp[i]>=space)return i;
    return -1;
}

int solve(){
    int E;
    cin>>n>>m>>E;
    int i,j;
    total_e=0;
    total_w=0;
    f(i,0,n-1)
        cin>>des_e[i]>>des_s[i]>>des_n[i];
    f(i,0,m-1)
        cin>>tru_s[i]>>tru_v[i]>>tru_n[i];

    int space=DessertSpace(E);

    int e=TruckSpace(50000,space);    //改
    return e;
}

```

