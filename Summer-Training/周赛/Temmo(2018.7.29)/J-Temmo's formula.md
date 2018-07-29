# J-Temmo's formula

> 题库链接：[https://nanti.jisuanke.com/t/29324](https://nanti.jisuanke.com/t/29324)

> 题解作者：[DeAllen](https://github.com/AllenTaken)

## 题意

给N，求`$\sum_{i=1}^{N}k^2C_{n}^{k}$`

## 解析

模板题，不多说了

## 直接贴代码

```c++
#include <cstdio>
#include <cstring>
#include <ctype.h>
#include <cstdlib>
#include <climits>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <deque>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <stack>
#include <set>
#include <numeric>
#include <sstream>
#include <iomanip>
#include <limits>
using namespace std;

const int N=100005;
#define LL long long
const LL p=1000000007;

LL qpow(LL a,LL b){
    LL ans=1;
    while(b){
        if(b&1)
        {
            ans=ans*a%p;
            b--;
        }
        a=a*a%p;
        b>>=1;
    }
    return ans;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        LL n;
        scanf("%lld",&n);
        LL res=(qpow(2,n-2)*(n*(n+1)%p))%p;
        printf("%lld\n",res);
    }
    return 0;
}
```