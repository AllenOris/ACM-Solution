#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <set>

using namespace std;

int f[10005];

int v[100005];
int head[100005];
int len = 0;
int lenn = 0;

struct MyStruct
{
    int next, to;
}e[10005*2];
int anss[100005];


void add(int a,int b)
{
    e[len].to = b;
    e[len].next = head[a];
    head[a] = len++;
}

void find(int t)
{
    int now = e[head[t]].to;
    int tmpans = 1;
    while(v[now]!=2)
    {
        now = e[head[now]].to;
        tmpans++;
    }
    anss[lenn++] = tmpans;
}


int main()
{
	int t,num=0;
	scanf("%d", &t);
	while(t--){
		int n,m,k,ans=0;
		memset(f,0,sizeof(f));
        memset(e, 0, sizeof(e));
        len = 0;
        lenn = 0;
        for (int i = 0; i < 100005;i++)
            head[i] = -1;
        scanf("%d%d%d", &n, &m, &k);
		int a,b;
		for(int i=0;i<m;i++){
			scanf("%d%d",&a,&b);
			v[a]++;v[b]++;
            add(a, b);
            add(b, a);
        }
		for(int i=1;i<=n;i++){
			if(f[i]==1)
            {
                find(i);
            }
		}

        sort(anss, anss + lenn);
        if(k>=lenn)
        {
            printf("0\n");
        }
		else
            printf("%d\n", anss[lenn - k - 1]);
    }
	return 0;
}