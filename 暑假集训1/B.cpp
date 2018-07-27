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

struct E
{
	long long s;
	int v, next;
} e[200000];

long long max(long long a,long long b)
{
	return a > b ? a : b;
}

int n,d,c;
int len = 0,head[10010];
bool used[10010];
long long l[10010];

void add(int a,int b,int t)
{
	e[len].s = t;
	e[len].v = b;
	e[len].next = head[a];
	head[a] = len++;
}

void SPFA()
{
	queue<int> que;
	que.push(c);
	used[c] = 1;
	for (int i = 0; i < 10010;i++)
	{
		l[i] = 999999999LL;
	}
	l[c] = 0;
	while(!que.empty())
	{
		int now = que.front();
		que.pop();
		used[now] = 0;
		for (int i = head[now]; i != -1; i=e[i].next )
		{
			int v = e[i].v, s = e[i].s;
			if(l[v]>l[now]+s)
			{
				l[v] = l[now] + s;
				if(!used[v])
				{
					que.push(v);
					used[v]=1;
				}
			}
		}
	}
}


int main()
{
	int T;
	cin >> T;
	while(T--){
		len = 0;
		memset(e, 0, sizeof(e));
		memset(used, 0, sizeof(used));
		for (int i = 0; i < 10010;i++)
			head[i] = -1;
		cin >> n >> d >> c;
		for (int i = 0; i <d ;i++)
		{
			int a, b, t;
			scanf("%d %d %d", &a, &b, &t);
			add(b, a, t);
		}

		SPFA();
		int lans = 0;
		long long lmax = 0;
		for (int i = 1; i <= n;i++)
		{
			if(l[i]!=999999999LL)
			{
				lans++;
				lmax = max(lmax, l[i]);
			}
			
			
		}
		cout << lans << " " << lmax << endl;
	}
	//getchar();
	return 0;
}