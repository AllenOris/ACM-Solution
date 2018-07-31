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
int gcd(int a, int b){
	return a % b == 0 ? b : gcd(b, a % b);
}
int solve(int n, int k){
	if(n==1)
		return 0;
	if(k==1)
		return -1;
	int q = gcd(n, k);
	if(q==1)
		return -1;
	long long x = 1;
	int i = 0;
	while(1){
		x *= (long long)q;
		++i;
		if(x==(long long)(n))
			return i;
		if(x>(long long)(n))
			return -1;
	}
}

int main()
{
	int T;
	cin >> T;
	while(T--){
		int n, k;
		cin >> n >> k;
		int ans = solve(n, k);
		if(ans==-1)
			cout << "unbounded\n";
		else
			cout << ans << endl;
	}
	//getchar();
	return 0;
}