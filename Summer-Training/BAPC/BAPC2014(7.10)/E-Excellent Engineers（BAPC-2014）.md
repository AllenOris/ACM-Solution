# E题-Excellent Engineers

题目链接[https://nanti.jisuanke.com/t/28315](https://nanti.jisuanke.com/t/28315)

#  题意

每个人有三种属性的相应排名。如果一个人，满足：没有另外的人三种属性排名都比他高，那么这个人就是Excellent Engineer,求Excellent Engineer的个数。

## 解析

拿样例举例，三人的排名分别是：

```
1 2 3
2 3 1
3 1 2
```

​	首先，对于第一个人，他的排名分别是1 2 3，虽然他的第三个属性比第二个人靠后，但第一个属性更靠前；虽然他的第二个属性比第三个人靠后，但第一个属性也更靠前，所以第一个人满足条件。

​	同理，第二、三人也满足条件。

​	数据1e5，暴力不可为。

​	线段树解法之一。

​	首先对第一个属性排序，排名由前至后，排序之后你会发现一个很有趣的性质，后面的人永远不会撼动前面人的地位。拿上面的样例举例，按第一属性排序后顺序不变，不管后面的人其余两个属性如何，第一个属性肯定不会前面的人排名靠前。那么一个人是否满足条件，之后受前面的人影响。

​	于是，以第二属性建一个线段树，按照排序后的顺序，插入第三属性，线段数的节点即为该区域的第三属性的排名最小值。对于第i个人来说，他的第二属性为y，第三属性为z，那么如果线段树1~y-1区域最小值比z大，那么这个人一定满足条件。

​	实际上就是简单的点更新，区间查询。排序O(nlogn),线段树O(nlogn)

​	附上代码

```c++
#include <bits/stdc++.h>
using namespace std;

#define io_speedup ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define f(i,a,b) for(i=a;i<=b;++i)
#define rf(i,a,b) for(i=a;i>=b;--i)
#define mem(a,n) memset(a,n,sizeof(a))
#define copy(a,b) memcpy(a,b,sizeof(b))
const int INF=~(1<<31);

const double E=exp(1.0);
const double Pi=4*atan(1.0);

int solve();
int get_region(int num, int l, int r, int _l, int _r);
void point_update(int num, int l,int r, int pos,int x);
void build(int num,int l, int r);
void print_tree(int n);

int main()
{
    io_speedup
    int T;
    cin>>T;
    while(T--){
        cout<<solve()<<endl;
    }
	return 0;
}

const int N=1e5+5;
int n;
struct eng{
    int x,y,z;
    bool operator<(const eng &A)const{
        return x<A.x;
    }
}e[N];

struct tree{
    int v;
    int lazy;
}a[4*N];

int solve(){
    mem(a,0);
    int ans=0;
    cin>>n;
    int i,j;

    f(i,0,n-1){
        cin>>e[i].x>>e[i].y>>e[i].z;
    }
    sort(e,e+n);

    build(1,1,n);
    f(i,0,n-1){
        if(e[i].y==1)ans+=1;
        else {
            int x=get_region(1,1,n,1,e[i].y-1);
            if(e[i].z<x)
                ans+=1;
        }
        point_update(1,1,n,e[i].y,e[i].z);
    }
    return ans;
}

void build(int num,int l, int r){
    if(l==r){
        a[num].v=n+1;
        return;
    }
    int mid=(l+r)>>1,n1=num<<1,n2=(num<<1)|1;
    build(n1,l,mid);
    build(n2,mid+1,r);
    a[num].v=min(a[n1].v,a[n2].v);
}

void point_update(int num, int l,int r, int pos,int x){
    if(l==r){
        a[num].v=min(a[num].v,x);
        return;
    }
    int mid=(l+r)>>1;
    int n1=num<<1,n2=(num<<1)|1;
    if(pos<=mid)
        point_update(n1,l,mid,pos,x);
    else
        point_update(n2,mid+1,r,pos,x);
    a[num].v=min(a[n1].v,a[n2].v);
}

int get_region(int num, int l, int r, int _l, int _r){
    if(_l<=l&&_r>=r)
        return a[num].v;
    int mid=(l+r)>>1;
    int n1=num<<1,n2=(num<<1)|1;
    int v1=n+1,v2=n+1;
    if(_l<=mid)
        v1=get_region(n1,l,mid,_l,_r);
    if(_r>mid)
        v2=get_region(n2,mid+1,r,_l,_r);
    return min(v1,v2);
}

void print_tree(int n){
    cout<<n<<":"<<endl;
    int i,j;
    int num=1;
    for(i=0;int(pow(2,i-1))<=n;++i){
        f(j,1,int(pow(2,i)))
            cout<<a[num++].v<<' ';
        cout<<endl;
    }
    cout<<endl;
}

```

