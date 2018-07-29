# Teemo's convex p

> 题库链接：[https://nanti.jisuanke.com/t/29294](https://nanti.jisuanke.com/t/29294)

> 题解作者：[DeAllen](https://github.com/AllenTaken)

## 题意

n凸多边形(n<1e18)，求多边形内所有对角形被分成了多少线段(对角线无交叉)

## 解析

公式题。

求每个对角线被多少条线穿过即可。

线段数量为`$\frac{n}{2}\sum_{k=1}^{n-3}(k*(n-2-k)+1)$`

n大小是1e18，打一发python a掉。。

```python
from __future__ import division
try:
    T=int(input())
    mod=1000000007
    
    def sum2(n):
        return n*(n+1)*(2*n+1)//6
    
    for i in range(T):
        n=int(input())
        ans=n*(n-3+(n-2)*(n-2)*(n-3)//2 -sum2(n-3))//2%mod
        print(ans)
except:
    pass
```