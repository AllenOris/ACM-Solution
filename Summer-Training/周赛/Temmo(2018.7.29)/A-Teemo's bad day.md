# A - Teemo's bad day

> 题库链接:[https://nanti.jisuanke.com/t/29203](https://nanti.jisuanke.com/t/29203)

> 题解作者: [DeAllen](https://github.com/AllenTaken)

## 题意

给两个数组，定义一种操作(a,b)，能同时将两个数组任意数量的a转换成b，b转换成a，求使两数组完全一样的最少操作次数

## 解析

题目有点绕，我就一开始没看懂题，还是昕神秒出思路，拿了一血。

并查集。

这里贴上官方的解析吧：

考虑一组简单样例 

数组A  1  2  3 

数组B  2  3  1

1与2不同，应买一张包含1和2的卡片；2和3不同，应买一张包含2和3的卡片。3与1不同，但是由于1和3因为前两张卡片都可以变成2，所以不需要再买卡片。如果我们在需要买卡片的两个数字之间连一条边，那么不需要买卡片的两个数字要么相同，要么两者可以分别通过某条路到达同一个点，顾最终转化为并差集问题。

## 代码

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
int fa[N];
int find(int x){
    int tmp=x;
    while(fa[tmp]!=tmp)tmp=fa[tmp]; 
    fa[x]=tmp;
    return tmp;
}
void join(int x,int y){
    if(find(x)!=find(y))fa[find(x)]=fa[find(y)];
}
int a[N*5],b[N*5];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=N;i++)fa[i]=i;
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)scanf("%d",&b[i]);
        int ans=0;
        for(int i=1;i<=n;i++){
            int aa=find(a[i]),bb=find(b[i]);
            if(aa==bb)continue;
            else{
                ans++;
                join(aa,bb);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
```

