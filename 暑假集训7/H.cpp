#include <bits/stdc++.h>

using namespace std;

long long N, K;

const long long mod = 1e9 + 7;
long long C[2000], A[2000];

struct Matrix
{
    long long num[1005][1005];
    long long l;
    Matrix()
    {
        l = N;
        for (long long i = 0; i < N; i++)
            for (long long j = 0; j < N; j++)
                num[i][j] = 0;
    }
    Matrix(long long a)
    {
        l = N;
        for (long long i = 0; i < N; i++)
            for (long long j = 0; j < N; j++)
                num[i][j] = 0;
        for (long long i = 0; i < N; i++)
            num[i][i] = a;
    }
};

Matrix mytimes(const Matrix &a,const Matrix &b)
{
    Matrix c(0LL);
    for (long long i = 0; i < N; i++)
        for (long long k = 0; k < N; k++)
            if (a.num[i][k] != 0)
            {
                for (long long j = 0; j < N; j++)
                {
                    c.num[i][j] += (a.num[i][k] * b.num[k][j]) % mod;
                    c.num[i][j] %= mod;
                }
            }
    return c;
}

Matrix qpow(Matrix b, long long c)
{
    Matrix tmpans(1LL);
    while (c)
    {
        if (c & 1)
        {
            tmpans = mytimes(tmpans, b);
        }
        b = mytimes(b, b);
        c >>= 1;
    }
    return tmpans;
}

int main()
{

    while (scanf("%lld %lld", &N, &K) != -1)
    {

        for (long long i = 0; i < N; i++)
        {
            scanf("%lld", &A[i]);
        }
        for (long long i = 0; i < N; i++)
        {
            scanf("%lld", &C[i]);
        }

        Matrix ans(0LL);
        for (long long i = 0; i < N; i++)
        {
            ans.num[0][i] = C[i];
        }
        for (long long i = 0; i < N - 1; i++)
        {
            ans.num[i + 1][i] = 1;
        }
        ans = qpow(ans, K-N);
        long long tmpans = 0;
        for (long long i = 0; i < N; i++)
        {
            tmpans = (tmpans + (ans.num[0][i] * A[i]) % mod) % mod;
        }
        printf("%lld\n", tmpans);
    }

    return 0;
}