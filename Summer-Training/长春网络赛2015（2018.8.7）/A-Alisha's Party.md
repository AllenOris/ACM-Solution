# A - Alisha's Party 

> 题目链接：[https://nanti.jisuanke.com/t/29328](https://nanti.jisuanke.com/t/29328)
>
> 题解作者：[DeAllen](https://github.com/AllenTaken)

# 题意

n个人拿着一定价值的礼物按顺序到，规定他们的进门顺序：当第ai个人到的时候，放bi个人进来，这bi个人是所拿礼物价值最大的。问最终进门的顺序。

## 解析

优先队列模拟

## 代码

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

const int N=15e4+5;
struct Person{
        int v;
        int num;
        bool operator<(const Person&P)const{
            if(v!=P.v)return v<P.v;
            return num>P.num;
        }
}a[N];
string name[N];
int num[N];
pair<int,int>p[N];
void solve();

int main()
{
    //io_speedup
    int n;
    cin>>n;
	int i, j;
	while(n--){
        solve();
	}
	return 0;
}
void solve(){
    mem(num,0);
    int i,j;
    f(i,0,N-1){
        name[i]="";
        a[i].num=a[i].v=0;
    }
    int n,m,k;
    cin>>n>>m>>k;
    f(i,0,n-1){
        cin>>name[i]>>a[i].v;
        a[i].num=i;
    }
    f(i,0,m-1){
        cin>>p[i].first>>p[i].second;
    }
    sort(p,p+m);
    priority_queue <Person>q;
    int pos=0;int cnt=0;
    f(i,0,m-1){
        f(j,pos,p[i].first-1){
            q.push(a[j]);
        }
        pos=p[i].first;
        f(j,0,p[i].second-1){
            if(!q.empty()){
                num[cnt++]=q.top().num;
                q.pop();
            }
        }
    }
    f(i,pos,n-1)q.push(a[i]);
    while(!q.empty()){
        num[cnt++]=q.top().num;
        q.pop();
    }
    f(i,1,k){
        int x;
        cin>>x;
        cout<<name[num[x-1]]<<' ';
    }
    cout<<endl;
}

```



