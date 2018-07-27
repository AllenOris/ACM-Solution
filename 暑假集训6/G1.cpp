#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
const int maxn=1<<17;
const int INF=1000000000;
const int maxm=25;
int anssum,ansmin,ansmax;
int r,c,m,op,x1,x2,y1,y2,v;
struct IntervalTree
{
    int sum[maxn],mino[maxn],maxo[maxn],addo[maxn],seto[maxn];
    void maintain(int num,int l,int r)
    {
        //sum[num]=mino[num]=maxo[num]=0;
        if(r>l)
        {
            sum[num]=sum[num*2]+sum[num*2+1];
            mino[num]=min(mino[num*2],mino[num*2+1]);
            maxo[num]=max(maxo[num*2],maxo[num*2+1]);
        }
 
        if(seto[num]>=0) {sum[num]=seto[num]*(r-l+1);mino[num]=maxo[num]=seto[num];}
        if(addo[num]){sum[num]+=addo[num]*(r-l+1);mino[num]+=addo[num];maxo[num]+=addo[num];}
 
    }
    void pushdown(int num)
    {
        if(seto[num]>=0)
        {
            seto[num*2]=seto[num*2+1]=seto[num];
            addo[num*2]=addo[num*2+1]=0;
            seto[num]=-1;
        }
        if(addo[num])
        {
            addo[num*2]+=addo[num];
            addo[num*2+1]+=addo[num];
            addo[num]=0;
        }
    }
    void update(int num,int l,int r)
    {
        if(l>=y1&&r<=y2)
        {
            if(op==1)addo[num]+=v;
            else {seto[num]=v;addo[num]=0;}
        }
        else
        {
            pushdown(num);
            int m=l+(r-l)/2;
            if(y1<=m)
                update(num*2,l,m);
            else
                maintain(num*2,l,m);
            if(y2>m)
                update(num*2+1,m+1,r);
            else
                maintain(num*2+1,m+1,r);
        }
        maintain(num,l,r);
    }
    void query(int num,int l,int r,int add)
    {
        if(seto[num]>=0)
        {
            int val=seto[num]+add+addo[num];
            anssum+=val*(min(r,y2)-max(l,y1)+1);
            ansmin=min(ansmin,val);
            ansmax=max(ansmax,val);
        }
        else if(y1<=l&&y2>=r)
        {
            anssum+=sum[num]+add*(r-l+1);
            ansmin=min(ansmin,mino[num]+add);
            ansmax=max(ansmax,maxo[num]+add);
        }
        else
        {
            int m=l+(r-l)/2;
            if(y1<=m)query(num*2,l,m,add+addo[num]);
            if(y2>m)query(num*2+1,m+1,r,add+addo[num]);
        }
    }
};
IntervalTree tree[maxm];
int main()
{
freopen("in.txt","r",stdin);
    while(scanf("%d%d%d",&r,&c,&m)!=EOF)
    {
        memset(tree, 0, sizeof(tree));
        for(int x = 1; x <= r; x++) {
            memset(tree[x].seto, -1, sizeof(tree[x].seto));
            tree[x].seto[1] = 0;
        }
        while(m--)
        {
            scanf("%d%d%d%d%d",&op,&x1,&y1,&x2,&y2);
            if(op<3)
            {
                scanf("%d",&v);
 
                for(int i=x1;i<=x2;i++)
                    tree[i].update(1,1,c);
            }
            else if(op==3)
            {
                anssum=0;
                ansmax=-INF;
                ansmin=INF;
                for(int i=x1;i<=x2;i++)
                    tree[i].query(1,1,c,0);
                cout<<anssum<<" "<<ansmin<<" "<<ansmax<<endl;
            }
        }
    }
    return 0;
}