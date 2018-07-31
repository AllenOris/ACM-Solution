#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cstdio>
using namespace std;

#define rep(i,a,b) for(__typeof(b) i=a; i<(b); ++i)

typedef pair<int, int> pii;
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    vector<pii> intervals(n);
    rep(i,0,n)
        scanf("%d %d", &intervals[i].second, &intervals[i].first);

    sort(intervals.begin(), intervals.end());
    multiset<int, greater<int> > ends;
    rep(i,0,k) ends.insert(0);
    int res = 0;
    for (pii &o : intervals)
    {
        auto it = ends.lower_bound(o.second);
        if (it != ends.end())
        {
            ends.erase(it);
            ends.insert(o.first);
            res++;
        }
    }

    cout << res << endl;
}