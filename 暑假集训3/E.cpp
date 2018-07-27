#include <iostream>
#include <queue>
#include <cstring>
#define INT_MAX 999900900000LL
using namespace std;
const long long maxN=20024;
const long long maxM=1002400;
long long head[maxN];
long long head1[maxN];
long long dis[maxN];
long long cnt[maxN];
long long cnt1[maxN];
long long n,m,e,e1,s,f;
long long ffff, ssss[maxN]; 

typedef pair<long long,long long> pii;
priority_queue<pii,vector<pii>,greater<pii> > q;
 
struct Edge
{
	long long v,w,next;
}edge[maxM*2],edge1[maxM*2];
void update(long long maxDis)
{
	long long i;
	for(long long i=1;i<=n;++i){
		if(dis[i]==maxDis){
			for(long long e=head1[i];e!=-1;e=edge1[e].next){
				long long v=edge1[e].v,w=edge1[e].w;
				if(dis[v]+w==dis[i]+1)
					cnt1[i]+=cnt[v];	
			}	
		}
	}
	
}
long long dij(long long s,long long t)
{		
	memset(cnt,0,sizeof(cnt));
	memset(cnt1,0,sizeof(cnt1));
	long long i,maxDis;
	for(i=1;i<=n;++i)
		dis[i]=INT_MAX;	
	dis[s]=0;
	cnt[s]=1;
	maxDis=0;
	q.push(make_pair(dis[s],s));
	while(!q.empty())
	{
		pii u=q.top();q.pop();
		long long x=u.second;
		if(u.first>dis[x])
			continue;
		if(maxDis<dis[x]){
			update(maxDis);			
			maxDis=dis[x];
		}
		for(long long e=head1[x];e!=-1;e=edge1[e].next){
			long long v=edge1[e].v,w=edge[e].w;
			if(dis[v]+w==dis[x]){
				cnt[x]+=cnt[v];	
				cnt1[x]+=cnt1[v];
			}
		}
		for(long long e=head[x];e!=-1;e=edge[e].next)
			if(dis[x]+edge[e].w<dis[edge[e].v]){
				dis[edge[e].v]=dis[x]+edge[e].w;
				q.push(make_pair(dis[edge[e].v],edge[e].v));
			}
	}
	update(maxDis);
	return dis[t];
}
 
int main()
{
		memset(head,-1,sizeof(head));
		memset(head1,-1,sizeof(head1));
		e=e1=0;

        scanf("%lld%lld%lld",&n,&m,&ffff);
 		long long s,t;
        for (long long i = 0; i < ffff;i++)
        {
            scanf("%lld", &ssss[i]);
            if(i==0)
                s=ssss[i];
            if(i==ffff-1)
            	t=ssss[i];
        }
            while (m--)
            {
                long long a, b, c;
                scanf("%lld%lld%lld", &a, &b, &c);
                edge[e].v = b;
                edge[e].w = c;
                edge[e].next = head[a];
                head[a] = e++;
                
                edge[e].v = a;
                edge[e].w = c;
                edge[e].next = head[b];
                head[b] = e++;
                
                edge1[e1].v = a;
                edge1[e1].w = c;
                edge1[e1].next = head1[b];
                head1[b] = e1++;
                edge1[e1].v = b;
                edge1[e1].w = c;
                edge1[e1].next = head1[a];
                head1[a] = e1++;
                
            }
            long long tmpans = 0;
            for (int i = 0; i < ffff-1;i++)
            {
                long long minnn = 200000LL;
                for (int j = head[ssss[i]]; j != -1;j=edge[j].next)
                {
                    if(edge[j].v==ssss[i+1])
                    minnn = min(minnn, edge[j].w);
                }
                tmpans += minnn;
            }
            cout << tmpans << endl;
            if (dij(t, s) == tmpans &&cnt[n]>=2 )
            {
                cout << "yes" << endl;
        }
        else
            cout << "no" << endl;
        return 0;	
} 