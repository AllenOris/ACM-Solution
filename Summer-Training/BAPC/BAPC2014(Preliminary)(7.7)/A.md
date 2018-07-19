# A.Choosing Ice Cream

题目链接：[https://nanti.jisuanke.com/t/28201](https://nanti.jisuanke.com/t/28201)

## 题意

​	通过一个k面的骰子在n个冰欺凌里选择，投m次骰子，使得选到的每个冰欺凌概率相等，求最小的m

## **解析** 

​   k和n的关系是任意的，可能等于，也可能大于或小于。投m次骰子，就是`$k^m$`种组合，对`$k^m$`个组合分组，如果投到其中一组的组合之一，那么选择该组所对应的冰欺凌，为了使概率相等，则要求每组包含的组合数量相同，所以问题转化为：
```math
k\ ^m\ \%\ n\ =\ 0
```
​	m存在,求最小的m；不存在,输出unbounded。

​	这样的模式很类似codeforces上[Round #483(Div.2) C](http://codeforces.com/contest/984/problem/C),如果用连乘的话当然会爆，可以使用质因数分解之类的方法，不过比较麻烦。

​	我的方法是这样的：`$k^m \%n= 0$`中的k等价于gcd(k,n)，因为只有k,n之间的公共因数才是对模n为0有贡献的，利用这样的性质不断迭代gcd，缩小n，使n缩小为1的最终操作次数即为结果。

```C++
#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    return a % b == 0 ? b : gcd(b, a % b);
}

int solve(int n, int k){
    if(n==1)return 0;	//如果只有一种选择，那么无需投骰子
    if(k==1)return -1;	//一面的骰子不可能解决两个以上的选择
    int q = gcd(n, k);
    if(q==1)
        return -1;
	
    int x=0;
    int i=0;
    while(x!=1){
        x=gcd(q,n);
        if(x!=1)
            while(n%x==0){n/=x;++i;}
       	if(n==1)return i;
    }
    return -1;    
}

int main()
{
    int T;
    cin >> T;
    while(T--){
        int n, k;
        cin >> n >> k;
        int ans = solve(n, k);
        if(ans==-1)
            cout << "unbounded\n";
        else
            cout << ans << endl;
    }
    return 0;
}
```

## 拓展

​	题目中提到的  `accept-reject method` 不太了解，好像很高达上的样子，貌似是这个[https://en.wikipedia.org/wiki/Rejection_sampling](https://en.wikipedia.org/wiki/Rejection_sampling),学习到了。