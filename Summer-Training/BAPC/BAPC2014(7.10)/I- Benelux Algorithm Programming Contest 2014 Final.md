


# I- Benelux Algorithm Programming Contest 2014 Final

  

  

[Benelux Algorithm Programming Contest 2014 Final ](https://www.jisuanke.com/contest/1404)

  

  

## 题意

​ 给定数字$N(N\leq10^9)$,$N$出现于以a,b开头的斐波那契数列中,寻找最早出现的数列a,b <br>


其中最早定义为( $(a,b)<(\dot{a},\dot{b}) | b<\dot{b},b=\dot{b} \bigwedge a<\dot{a}$ )<br>

  

  

## 解析

我们列出以a,b开头的斐波那契数列前几项

$$a\qquad b\qquad a+b\qquad a+2*b\qquad 2*a+3*b \qquad \cdots$$

观察易得a,b前的系数分别为

$$a:1\qquad 0\qquad 1\qquad 1\qquad 2 \qquad 3\qquad\cdots$$

$$b:0\qquad 1\qquad 1\qquad 2\qquad 3 \qquad 5\qquad\cdots$$

设$F_n$为以1 1开头的斐波那契额数列第n项,那么以a,b开头的斐波那契额数列第n项$F^{a,b}_{n}为F_{n-1}*a+F_{n}*b$记a b为$F^{a,b}的第-1项和第0项$

若N可以被a,b开头的斐波那契额数列表示,那么满足$N=F_{n-1}*a+F_{n}*b$<br>

显然 $\forall n \quad gcd(F_{n-1},F_{n})=1$，那么根据扩展欧几里得算法我们可以得到一组x,y使得$\dot x*F_{n-1}+\dot y*F_{n}=\ gcd(F_{n-1},F_{n})\ =\ 1$
又因为$-F_{n}*F_{n-1}+F_{n-1}*F_{n}=\ 0$，根据通解的组成性质,得到$$ x=\dot{x}-k*F_{n} $$ $$y=\dot{y}+k*F_{n-1}$$

两边同时乘以N即得到$N=F_{n-1}*x*N+F_{n}*y*N$
又因为满足$0<a\leq b$
所以$\dot{x}-k*F_{n}\leq\dot{y}+k*F_{n-1}\Rightarrow k\geq$${\dot x-\dot y }\over {F_{n}+F_{n-1}}$因为$b=y=\dot{y}+k*F_{n-1}$ 随 k 单调递增,所以当$k=\lceil\frac{\dot x-\dot y}{F_{n}+F_{n-1}}\rceil$时b最小,所以首先预处理前五十项斐波那契额数列，枚举以后求得a，b判断是否大于0，最后在所有求得的组合中选择最小的那一项
总体时间复杂度$O(50*log(F_{t}))$
### 附上代码

```c++
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
long long n;
long long F[51];
int len;

struct P
{
    long long x, y;
} p[200];

long long exGcd(long long a, long long b, long long &x, long long &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    long long r = exGcd(b, a % b, x, y);
    long long t = x;
    x = y;
    y = t - a / b * y;
    return r;
}

void init()
{
    int i = 2;
    F[0] = F[1] = 1;
    do
    {
        F[i] = F[i - 1] + F[i - 2];
    } while (F[i++] < 200000000LL);
    len = i;
    for (int j = 1; j < len; j++)
    {
        exGcd(F[j - 1], F[j], p[j].x, p[j].y);
    }
}

int main()
{
    long long T;
    init();
    cin >> T;
    while (T--)
    {
        long long a = 0, b = 999999999LL;
        cin >> n;
        for (int i = 1; i < len; i++)
        {
            long long c = (n * p[i].x - n *p[i].y) / (F[i - 1] + F[i]);
            long long x = n * p[i].x - c * F[i];
            long long y = n * p[i].y + c * F[i - 1];
            if(x>y)
            {
                x -= F[i];
                y += F[i - 1];
            }
            if(y<=0||x<=0)
                continue;
            if(y<b)
            {
                a = x;
                b = y;
            }
            else if(y==b&&a<=x)
            {
                a = x;
                b = y;
            }
        }
        cout << a << " " << b << endl;
    }
    return 0;
}

```
