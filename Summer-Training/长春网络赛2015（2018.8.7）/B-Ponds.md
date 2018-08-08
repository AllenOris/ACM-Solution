# B - Ponds

> 题目链接：[https://www.jisuanke.com/contest/1468?view=challenges](https://www.jisuanke.com/contest/1468?view=challenges)
>
> 题解作者：[LeFlacon](https://github.com/LeFlacon)
> 
# 题意
给一个无向图，池塘之间有管道相连，每个池塘有一个权值，现在要拆掉所有度数小于2的池塘，直至不能拆为止，最后求连通个数为奇数的池塘的权值和

# 题解
删除一个度数为1的结点之后，这个点的边所通向的点的度数也要减一，就可能产生新的度数小于2的点，有点拓扑排序的意思，出现度数小于2的点就存入q，直到q为空，按照题意写就行

#代码
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
const int N=1000005;
int d[N],w[N],u[N],v[N],sum[N];
LL ans;
vector<vector<int> >tu;
bool vis[N];
int fa[N];
void init(int x){
	for(int i=1;i<=x;i++)fa[i]=i;
	memset(d,0,sizeof(d));
	memset(vis,false,sizeof(vis));
	memset(sum,0,sizeof(sum));
	tu.resize(x+1);
	tu.clear();
}
int find(int x){
    int tmp=x;
    while(fa[tmp]!=tmp)tmp=fa[tmp]; 
    fa[x]=tmp;
    return tmp;
}
void join(int x,int y){
    if(find(x)!=find(y))fa[find(x)]=fa[find(y)];
}
int main(){
	int t,n,m;
	scanf("%d",&t);
	while(t--){
		ans=0;
		scanf("%d%d",&n,&m);
		init(n);
		for(int i=1;i<=n;i++)scanf("%d",&w[i]);
		for(int i=1;i<=m;i++){
			scanf("%d%d",&u[i],&v[i]);
			d[u[i]]++;d[v[i]]++;
			tu[u[i]].push_back(v[i]);
			tu[v[i]].push_back(u[i]);
		}
		queue<int>q;
		for(int i=1;i<=n;i++){
			if(d[i]<=1){
				vis[i]=true;
				q.push(i);
			}
		}
		while(!q.empty()){
			int tmp=q.front();
			q.pop();
			for(int i=0;i<tu[tmp].size();i++){
				int nod=tu[tmp][i];
				d[nod]--;
				if(d[nod]<=1&&vis[nod]==false){
					vis[nod]=true;
					q.push(nod);
				}
			}
		}
		for(int i=1;i<=m;i++){
			if(vis[u[i]]==false&&vis[v[i]]==false)join(u[i],v[i]);
		}
		for(int i=1;i<=n;i++){
			if(vis[i]==false)sum[find(i)]++;
		}
		for(int i=1;i<=n;i++){
			if(vis[i]==false&&sum[find(i)]&1)ans+=w[i];
		}
		printf("%lld\n",ans);

	}
	return 0;
}
```