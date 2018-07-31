#include <bits/stdc++.h>
using namespace std;

#define io_speedup           \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define ll long long
#define f(i, a, b) for (i = a; i <= b; ++i)
#define rf(i, a, b) for (i = a; i >= b; --i)
#define mem(a, n) memset(a, n, sizeof(a))
#define copy(a, b) memcpy(a, b, sizeof(b))

const double E = exp(1.0);
const double Pi = 4 * atan(1.0);

const int N = 1e7 + 5;
bool f[N];
long long x[65];
long long multi(long long a, long long b, long long p)
{
    long long ans = 0;
    while (b)
    {
        if (b & 1LL)
            ans = (ans + a) % p;
        a = (a + a) % p;
        b >>= 1;
    }
    return ans;
}

long long qpow(long long a, long long b, long long p)
{
    long long ans = 1;
    while (b)
    {
        if (b & 1LL)
            ans = multi(ans, a, p);
        a = multi(a, a, p);
        b >>= 1;
    }
    return ans;
}

bool Miller_Rabin(long long n)
{
    if (n == 1)
        return false;
    if (n == 2)
        return true;
    int s = 20, i, t = 0;
    long long u = n - 1;
    while (!(u & 1))
    {
        t++;
        u >>= 1;
    }
    while (s--)
    {
        long long a = rand() % (n - 2) + 2;
        x[0] = qpow(a, u, n);
        for (i = 1; i <= t; i++)
        {
            x[i] = multi(x[i - 1], x[i - 1], n);
            if (x[i] == 1 && x[i - 1] != 1 && x[i - 1] != n - 1)
                return false;
        }
        if (x[t] != 1)
            return false;
    }
    return true;
}

long long gcd(long long a, long long b)
{
    return b ? gcd(b, a % b) : a;
}

int get_num(string s, int &p)
{
    string str;
    int n = s.length();
    int i;
    bool f = 0;
    int q = 0;
    f(i, 0, n - 1)
    {
        if (s[i] != '.')
        {
            str += s[i];
            if (f)
                q++;
        }
        else
            f = 1;
    }
    int j = 1;
    n = str.length();
    int ans = 0;
    rf(i, n - 1, 0)
    {
        ans += (str[i] - '0') * j;
        j *= 10;
    }
    p = q;
    return ans;
}

int main()
{
    io_speedup int n;
    cin >> n;
    f[0] = f[1] = 1;
    int i;
    f(i, 1, n)
    {
        string s1, s2;
        int p1, p2;
        cin >> s1 >> s2;
        int xx = get_num(s1, p1);
        int y = get_num(s2, p2);
        int P = max(p1, p2);
        //       cout<<p1<<' '<<p2<<endl;
        xx *= (int)pow(10, max(0, P - p1));
        y *= (int)pow(10, max(0, P - p2));
        int g = gcd(xx, y);
        xx /= g;
        y /= g;
        if (xx == y && xx == 1)
        {
            cout << 2 << " " << 2 << endl;
            continue;
        }
        if (Miller_Rabin((long long)xx) && Miller_Rabin((long long)y))
            cout << xx << ' ' << y << endl;
        else
            cout << "impossible" << endl;
    }
    return 0;
}
