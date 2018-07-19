# D-Carpets(GCPC 15)

[2015 German Collegiate Programming Contest (GCPC 15) ](https://www.jisuanke.com/contest/1405) 

## 题意

​	用若干形状的小矩形填满一个大矩形，判断能不能填满

## 解析

​	DFS+贪心

​	事实上，题目给的小矩形个数最多有七个，直接全排列枚举，作为填放次序。重点在于如何安排填放策略，使得不会漏掉正解。这个时候就要用到贪心的方法，优先填一个角落，这里使用优先填放左上角，而且必须保证横向是平坦的，即填上去之后上面不会有镂空的缝隙。

​	所以每次DFS，添加一个low数组，大小为W(大矩形横向的宽)，记录横向每个单位长度的高，填充矩形之后，对区间进行修改。

​	填满DFS结束。

​	复杂度`$O(n!*2^n*W)$`，`$2^n$`指小矩形的翻转，枚举横着摆和竖着摆。

​	没错，复杂度看上去很高，但其实n很小。在使用next_permution构造全排列时，加上判重操作，去掉相同形状的重复排列，可以很大程度减小`$n!$`

​	附上代码

```c++
#include <bits/stdc++.h>
using namespace std;

#define io_speedup ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define f(i,a,b) for(i=a;i<=b;++i)
#define rf(i,a,b) for(i=a;i>=b;--i)
#define mem(a,n) memset(a,n,sizeof(a))

int n,m,k;
const int N=8;
const int W=100+5;

struct Block{
    int x, y;
}a[N];

int block_map[N];
set<int>repeat;
int num[N];
int low[W];

bool repeat_block(int *num, int k){
    int i;
    int p=1;
    int q=0;
    f(i,0,k-1){
        q+=block_map[ num[i] ]*p;
        p*=10;
    }
    if(repeat.find(q)==repeat.end()){
        repeat.insert(q);
        return false;
    }
    return true;
}

int find_low(int x, int y){
    int i,j;
    i=1;
    while(i<=n-x+1){
        bool plain=1;
        for(j=i+1;j<=i+x-1;++j){
            if(low[j]!=low[j-1]){
                plain=0;
                i=j;
                break;
            }
        }
        if(plain&&low[i]+y<=m)
            return i;
        else if(plain)
            i+=x;
    }
    return -1;
}

void dfs(int x,int s_size){
    if(s_size==0){
        cout<<"yes\n";
        exit(0);
    }
    if(x>=k)return;
    int i=num[x],j;
    //横着摆
    int x1=find_low(a[i].x,a[i].y);
    if(x1!=-1){
        f(j,x1,x1+a[i].x-1)
            low[j]+=a[i].y;
        dfs(x+1, s_size-a[i].x*a[i].y);
        f(j,x1,x1+a[i].x-1)
            low[j]-=a[i].y;
    }
    //竖着摆
    int x2=find_low(a[i].y,a[i].x);
    if(x2!=-1){
        f(j,x2,x2+a[i].y-1)
            low[j]+=a[i].x;
        dfs(x+1,  s_size-a[i].x*a[i].y);
        f(j,x2,x2+a[i].y-1)
            low[j]-=a[i].x;
    }
}

int main()
{
    io_speedup
    int p;
    cin>>n>>m>>p;
	int i, j;
	k=0;
	f(i,0,p-1){
	    int x,y,block_num;
	    cin>>block_num>>x>>y;
	    f(j,0,block_num-1){
            a[k].x=x;
            a[k].y=y;
            block_map[k++]=i;//记录形状类，做后面的去重
	    }
	}
    f(i,0,k-1)num[i]=i;
    do{
       if(!repeat_block(num,k)){
            mem(low,0);
            dfs(0,n*m);
        }
    }while(next_permutation(num,num+k));
    cout<<"no\n";
	return 0;
}

```

