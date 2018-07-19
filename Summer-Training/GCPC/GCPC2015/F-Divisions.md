
# F- Divisions(GCPC 15)

  

[2015 German Collegiate Programming Contest (GCPC 15) ](https://www.jisuanke.com/contest/1405)

  

## 题意

  

​ 求数字$N$的因数个数，($N<=10^{18}$)

  

## 解析
设N的质因子分解为`$N=\prod_{i=1}^m{a_i}^{k_i}$`
其中`$a$`为`$N$`的质因子
那么`$N$`的因数个数为`$num=\prod_{i=1}^m(k_i+1)$`

### Pollard_rho算法
  Pollard_rho算法可以在$O(\sqrt[4]n )$的时间里分解$N$的质因数
  其原理为通过判断$n$是否为质数(Miller_Rabin算法)，如果不是质数，则存在不为1和本身的质因数，通过不断选取$x,y$计算$gcd(|y-x|,n)$求得$n$的因数$p$，然后递归调用去分解$p$和$n/p$直到得到所有质因数
最后排序获得的质因数计算$num=\prod_{i=1}^m(k_i+1)$
### 附上代码
```c++
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

const int MAXN = 65;
long long x[MAXN];
vector<long long> f;

long long multi(long long a, long long b, long long p) {
    long long ans = 0;
    while(b) {
        if(b&1LL) ans = (ans+a)%p;
        a = (a+a)%p;
        b >>= 1;
    }
    return ans;
}

long long qpow(long long a, long long b, long long p) {
    long long ans = 1;
    while(b) {
        if(b&1LL) ans = multi(ans, a, p);
        a = multi(a, a, p);
        b >>= 1;
    }
    return ans;
}

bool Miller_Rabin(long long n) {
    if(n == 2) return true;
    int s = 20, i, t = 0;
    long long u = n-1;
    while(!(u & 1)) {
        t++;
        u >>= 1;
    }
    while(s--) {
        long long a = rand()%(n-2)+2;
        x[0] = qpow(a, u, n);
        for(i = 1; i <= t; i++) {
            x[i] = multi(x[i-1], x[i-1], n);
            if(x[i] == 1 && x[i-1] != 1 && x[i-1] != n-1) return false;
        }
        if(x[t] != 1) return false;
    }
    return true;
}

long long gcd(long long a, long long b) {
    return b ? gcd(b, a%b) : a;
}

long long Pollard_Rho(long long n, int c) {
    long long i = 1, k = 2, x = rand()%(n-1)+1, y = x;
    while(true) {
        i++;
        x = (multi(x, x, n) + c)%n;
        long long p = gcd((y-x+n)%n, n);
        if(p != 1 && p != n) return p;
        if(y == x) return n;
        if(i == k) {
            y = x;
            k <<= 1;
        }
    }
}

void find(long long n, int c) {
    if(n == 1) return;
    if(Miller_Rabin(n)) {
        f.push_back(n);
        return;
    }
    long long p = n, k = c;
    while(p >= n) p = Pollard_Rho(p, c--);
    find(p, k);
    find(n/p, k);
}
```
