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

const int N=100005;
struct p{
	int x,y;
}q[N];

bool cmp(p a,p b){
	if(a.y!=b.y)return a.y<b.y;
	else return a.x<b.x;
}

int main(){
	int n,k,ans=0;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d%d",&q[i].x,&q[i].y);
	}
	sort(q,q+n,cmp);
	vector<int>c;
	for(int i=0;i<k;i++)c.push_back(0);
    
	for(int i=0;i<n;i++){
		int tmp=upper_bound(c.begin(),c.end(),q[i].x)-c.begin();
		// cout<<tmp<<endl;
		if(tmp!=0){
			c.erase(c.begin()+tmp-1);
			c.push_back(q[i].y);
			ans++;
		}
	}
	cout<<ans<<endl;
    return 0;
}