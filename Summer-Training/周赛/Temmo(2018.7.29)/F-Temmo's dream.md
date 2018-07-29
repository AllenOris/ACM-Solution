# F-Temmo's dream

> 题库链接:[https://nanti.jisuanke.com/t/29245](https://nanti.jisuanke.com/t/29245)

> 题解作者：[DeAllen](https://github.com/AllenTaken)

## 题意

给定数列`$a_{i}$`，求1~m有多少正整数是`$a_{i}$`的倍数

## 解析
容斥原理

定理：如果p.q互质，那么1~m间所有因子含p.q的整数有`$\frac{m}{p}+\frac{m}{q}-\frac{m}{p*q} $`,很好理解，不用解释；如果是三个数p.q.r互质，那么就是`$\frac{m}{p}+\frac{m}{q}+\frac{m}{r}-\frac{m}{p*q}-\frac{m}{q*r}-\frac{m}{r*p}+\frac{m}{p*q*r} $`个，依此类推。

这个公式昕神知道，她告诉了我，我来打枚举。

然后样例错了。。

然后昕神手算了一遍，我cout了一遍，输出结果完全符合公式，昕神不信邪，说一定是样例错了，然后交了。。

然后WA了。。

因为忽略了题目给出的因子并不是互质的，想了一下，容斥的其实是数与数的最小公倍数，所以只需对分母加个lcm，就a了。

## 代码

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

const long long N=20;
long long n;
long long s[N];
long long a[N];

bool next(long long x){
    long long i,j;
    if(s[1]==n-x+1)return false;
    if(s[x]!=n){
        s[x]+=1;
        return true;
    }
    rf(i,x-1,1){
        if(s[i]!=s[i+1]-1){
            s[i]+=1;
            f(j,i+1,n)s[j]=s[j-1]+1;
            return true;
        }
    }
    return false;
}

int gcd(long long a,long long b){
    return b==0?a:gcd(b,a%b);
}

long long lcm(long long a,long long b){
    return a*b/gcd(a,b);
}

int main(){
    io_speedup
    long long T;
    cin>>T;
    while(T--){
        long long m;
        long long i,j;
        bool isplus;
        cin>>n>>m;
        mem(a,0);
        mem(s,0);
        f(i,1,n)cin>>a[i];
        long long ans=0;
        f(i,1,n){
             if(i&1)isplus=1;
                else isplus=0;
            f(j,1,i){
                s[j]=j;
            }
            do{
                bool flag=0;
                long long p=a[s[1]];
                f(j,2,i){
                    long long x=s[j];
                    p=lcm(p,a[x]);
                    if(p>m){
                        flag=1;
                        break;
                    }
                }
                if(flag)continue;
                    ans+=isplus?m/p:(0-m/p);
            }while(next(i));
        }
        cout<<ans<<endl;
    }
	return 0;
}

```

PS:我现在还不明白我为什么受了蛊惑，没过样例后点了提交按钮。