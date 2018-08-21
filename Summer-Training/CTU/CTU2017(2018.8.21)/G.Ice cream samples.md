---
title: CTU 2017 G.Ice cream samples
date: 2018-08-21 19:50:23
categories: 杂
---
题解作者:[LeFlacon](https://github.com/LeFlacon)
# CTU 2017 G.Ice cream samples

To encourage visitors active movement among the attractions, a circular path with ice cream
stands was built in the park some time ago. A discount system common for all stands was
also introduced. When a customer buys ice cream at some stand, he is automatically granted a
discount for one day at the next stand on the path. When visitors start at any stand and follow
systematically the discount directions to the next stands, they eventually traverse the whole
circular path and return back to the stand they started at.

Ice creams of various brands are sold at the stands. Additionally, each stand sells a nice sample
box which contains small samples of popular ice cream brands. The number of samples in the
box depends on the stand and various stands may put different brands into their sample boxes.

Each box contains samples of one or more brands. A brand may be represented by one or more
samples in the box, or it may be completely missing. 

Each stand sells only one type of sample
box (the brands of the samples in the box are always the same for that particular stand).

Quido and Hugo are going to exploit the discount system for their own benefit. They decided
to start at some stand and then continue in the direction of the discounts buying one ice cream
sample box at each stand they visit in a consecutive sequence. Their goal is to collect at least
one sample of each ice cream brand sold in the park.

Simultaneously, to respect their stomach
capacities, they want to minimize the total number of ice cream samples they buy.

### Input Specification
There are more test cases. Each case starts with a line containing two integers N, K separated
by space (1 ≤ N, K ≤ 106
). N is the number of ice cream stands, K is the total number of
different ice cream brands sold at all stands. The brands are labeled by numbers 1, 2, . . . , K.
Next, there are N lines describing stands in their visiting order. Each such line contains the
list of brands of all ice cream samples sold in the sample box at that particular stand. Each list
starts with one positive integer L, describing its length, followed by L integers. Each list item
represents the brand of one ice cream sample in the sample box sold at this stand. You may
assume that even if a visitor buys one sample box at each stand, he/she will collect at most 107
ice cream samples.
### Output Specification
For each test case, print a single line with one integer denoting the minimum number of ice
cream samples Quido and Hugo have to buy in order to obtain a sample of each ice cream brand
sold in the park. If it is impossible to obtain samples of all brands output −1.
### Sample Input
```
4 3
4 1 3 1 3
1 2
2 3 3
1 1
5 3
1 2
1 3
2 1 1
2 2 2
1 1
3 2
2 1 1
1 1
3 1 1 1
```
### Output for Sample Input
```
4
3
-1
```
---
### 题意：
给N个序列，N个序列不一定长度相同，序列由1~K的整数构成，现在选定连续的几个序列（首尾也算连续，想象它们是一个圈），使得1、2、3……K全在这些数列中，求选出数列所有数字个数和的最小值

### 题解：

序列只能整个整个的取，而且要连续，所以肯定要加倍，循环2*n，设两个指针cur1=0，cur2=-1，然后开始实行扩圈和缩圈的操作

如果当前k个数都有了，就更新ans，然后缩圈（cur1++），看看是否有更少的解

如果k个数还没有全，就要继续扩圈（cur2++），然后把新的序列里的数遍历一遍

这里要注意的是，cur2达到上限或已经取了n个连续序列时，就没有扩圈的机会了，只能缩圈找最优

复杂度我也不知道。。这种题大概就是瞎搞吧。。

res记录当前冰淇淋个数，vis[i]存第i种冰淇淋目前的个数，num为当前冰淇淋种类数

### 代码：
```
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

const int INF=0x3f3f3f3f;
const int N=1000005;
vector<int>a[N];
int ans,vis[N],cur1,cur2,n,k,res,num;
int main(){
	while(scanf("%d%d",&n,&k)!=EOF){
		for(int i=0;i<n;i++)a[i].clear();
		memset(vis,0,sizeof(vis));
		int l,c;
		for(int i=0;i<n;i++){
			scanf("%d",&l);
			for(int j=0;j<l;j++){
				scanf("%d",&c);
				a[i].push_back(c);
			}
		}
		ans=INF;
		res=0;num=0;
		cur1=0;cur2=-1;
		while(cur1<2*n){
			if(num==k){
				//如果有k个数了就缩圈找最优
				ans=min(ans,res);
				for(int i=0;i<a[cur1%n].size();i++){
					if(vis[a[cur1%n][i]]>1)vis[a[cur1%n][i]]--;
					else{
						num--;
						vis[a[cur1%n][i]]--;
					}
				}
				res-=a[cur1%n].size();
				cur1++;
			}
			else if(cur2-cur1+1==n||cur2==2*n-1){
				//因为是2n为了保证循环到所有情况
				//所以如果当前取得已经有n个了或者cur2到了上限就只能缩圈
				for(int i=0;i<a[cur1%n].size();i++){
					if(vis[a[cur1%n][i]]>1)vis[a[cur1%n][i]]--;
					else{
						num--;
						vis[a[cur1%n][i]]--;
					}
				}
				res-=a[cur1%n].size();
				cur1++;
			}
			else{
				//扩圈
				cur2++;
				for(int i=0;i<a[cur2%n].size();i++){
					if(vis[a[cur2%n][i]]==0){
						num++;
						vis[a[cur2%n][i]]++;
					}
					else vis[a[cur2%n][i]]++;//漏了这个至关重要的更新可让我好找。。
				}
				res+=a[cur2%n].size();
			}
		}
		printf("%d\n",ans==INF?-1:ans);
	}
    return 0;
}
```



