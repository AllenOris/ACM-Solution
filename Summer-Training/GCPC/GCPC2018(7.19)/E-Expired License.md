# E-Expired License 

题目链接：[https://nanti.jisuanke.com/t/28856](https://nanti.jisuanke.com/t/28856)

## 题目原文

Paul is an extremely gifted computer scientist who just completed his master's degree at a prestigious German university. Now he would like to culminate his academic career in a PhD. The problem is that there are so many great universities out there that it is hard for him to pick the best. Because some application deadlines are coming up soon, Paul's only way to procrastinate his decision is by simply applying to all of them.

Most applications require Paul to attach a portrait photo. However, it seems like there does not exist an international standard for the aspect ratio of these kinds of photos. While most European universities ask Paul to send a photograph with aspect ratio 4.54.5 by 66, some Asian countries discard the applications immediately if the photo does not have an aspect ratio of 7.147.14 by 11.2211.22, precisely.

As Paul has never been interested in photo editing, he never had a reason to spend a lot of money on proper software. He downloaded a free trial version some months ago, but that version has already expired and now only works with some funny restrictions. The cropping tool, for example, no longer accepts arbitrary numbers for setting the aspect ratio, but only primes. This makes Paul wonder whether the desired aspect ratios can even be properly expressed by two prime numbers. Of course, in case this is possible, he would also like to know the primes he has to enter.

### Input Format

The input consists of:

- one line with an integer nn (1 \le n \le 10^5)(1≤n≤105), the number of applications Paul has to file;
- nn lines,each with two real numbers aa and bb (0<a,b<100)(0<a,b<100), where a\times ba×b is the desired aspect ratio of one application.

All real numbers are given with at most 5 decimal places after the decimal point.

### Output Format

For each application, if it is possible to represent the desired aspect ratio by two prime numbers pp and qq, output one line with pp and qq. Otherwise, output impossible. If multiple solutions exist, output the one minimizing p + qp+q.

#### 样例输入

```
3
4.5 6
7.14 11.22
0.00002 0.00007
```

#### 样例输出

```
impossible
7 11
2 7
```

## 题意

给两个浮点数a,b，判断能找到两个质数p.q，满足a/b=p/q

## 解析

水题，为什么写题解是因为想说一下浮点数的问题。

给定的小数位最多是5位，所以容易想到两个数同时乘以1e5，得到的结果转成int，然后求一遍gcd，拿最简分数判断质数。然后就WA了，事实上，样例都过不了。

为什么呢？

因为[IEEE754](https://en.wikipedia.org/wiki/IEEE_754)标准的浮点数是不能准确所有小数的，当然这也不是IEEE754的问题，小数的位数是无限的，显然，有限的内存不能存无限的数(除非你直接存成分数)。

就拿样例中0.00007举例，如果输入`cout<<int(0.00007*100000)`的话，你会神奇的发现，结果为6。

~待续~

判断素数的时候用了Miller_Rabin的板子，结果一次TLE，一次WA……然后老老实实暴力判定质数。后来才发现传参时候把int传进了long long。QAQ

注意两个数相等要输出2 2

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
const int INF=~(1<<31);

const double E=exp(1.0);
const double Pi=4*atan(1.0);

const int N=1e7+5;
bool f[N];
long long x[65];

long long gcd(int a, int b) {
    return b>0 ?gcd(b, a%b) : a;
}

int get_num(string s,int &p){
    string str;
    int n=s.length();
    int i;
    bool f=0;
    int q=0;
    f(i,0,n-1){
        if(s[i]!='.'){
            str+=s[i];
            if(f)q++;
        }
        else f=1;
    }
    int j=1;
    n=str.length();
    int ans=0;
    rf(i,n-1,0){
        ans+=(str[i]-'0')*j;
        j*=10;
    }
    p=q;
    return ans;
}

bool prime(int x){
    if(x==1)return 0;
    if(x==2)return 1;
    int i;
    int m=sqrt(x);
    f(i,2,m){
        if(x%i==0)return 0;
    }
    return 1;
}

int main()
{
    io_speedup
    int n;
    cin>>n;
    f[0]=f[1]=1;
	int i, j;
	f(i,1,n){
        string s1,s2;
        int p1,p2;
        cin>>s1>>s2;
        int x=get_num(s1,p1);
        int y=get_num(s2,p2);
        int P=max(p1,p2);
        x*=(int)pow(10,max(0,P-p1));
        y*=(int)pow(10,max(0,P-p2));
        if(x==y){
            cout<<2<<' '<<2<<endl;
            continue;
        }
        int g=gcd(x,y);
        x/=g;
        y/=g;
        if(prime(x)&&prime(y))
            cout<<x<<' '<<y<<endl;
        else
            cout<<"impossible"<<endl;
	}
	return 0;
}
```







