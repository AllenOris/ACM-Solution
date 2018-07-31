# C-Minimum Cut

> 题目链接：[https://nanti.jisuanke.com/t/29122](https://nanti.jisuanke.com/t/29122)
>
> 题解作者：[LeFlacon](https://github.com/LeFlacon)

##　题意

先给一棵生成树，再在此基础上给图，删去树的一个边和图一些边使图不连通，求删去的最少边数

## 题解

要使图不连通且只能删树的一个边，就要找树上度数为1的点，然后加上图中和这个点相连的边，求最小的即可



```c++
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <cmath>
using namespace std;

#define LL long long 
const int N=20005;
const int INF=0x3f3f3f3f;
int d1[N],d2[N];
int main(){
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		int n,m,ans=INF;
		scanf("%d%d",&n,&m);
		memset(d1,0,sizeof(d1));
		memset(d2,0,sizeof(d2));
		int u,v;
		for(int i=0;i<n-1;i++){
			scanf("%d%d",&u,&v);
			d1[u]++;d1[v]++;
		}
		for(int i=n-1;i<m;i++){
			scanf("%d%d",&u,&v);
			d2[u]++;d2[v]++;
		}
		for(int i=1;i<=n;i++){
			if(d1[i]==1)ans=min(ans,1+d2[i]);
		}
		printf("Case #%d: %d\n",i,ans);
	}
    return 0;
}
```

