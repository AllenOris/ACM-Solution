#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

const double epsi = 1e-8;
const double pi = acos(-1.0);
const int maxn = 20001;

struct PPoint
{ //结构体尽量不要定义成Point这种,容易和C/C++本身中的变量同名
    double x;
    double y;

    PPoint(double _x = 0, double _y = 0) : x(_x), y(_y)
    {
    }

    PPoint operator-(const PPoint &op2) const
    {
        return PPoint(x - op2.x, y - op2.y);
    }

    double operator^(const PPoint &op2) const
    {
        return x * op2.y - y * op2.x;
    }
};

inline int sign(const double &x)
{
    if (x > epsi)
    {
        return 1;
    }

    if (x < -epsi)
    {
        return -1;
    }

    return 0;
}

inline double sqr(const double &x)
{
    return x * x;
}

inline double mul(const PPoint &p0, const PPoint &p1, const PPoint &p2)
{
    return (p1 - p0) ^ (p2 - p0);
}

inline double dis2(const PPoint &p0, const PPoint &p1)
{
    return sqr(p0.x - p1.x) + sqr(p0.y - p1.y);
}

inline double dis(const PPoint &p0, const PPoint &p1)
{
    return sqrt(dis2(p0, p1));
}

int n;
PPoint p[maxn];
PPoint convex_hull_p0;

inline bool convex_hull_cmp(const PPoint &a, const PPoint &b)
{
    return sign(mul(convex_hull_p0, a, b) > 0) || (sign(mul(convex_hull_p0, a, b)) == 0 && dis2(convex_hull_p0, a) < dis2(convex_hull_p0, b));
}

int convex_hull(PPoint *a, int n, PPoint *b)
{
    int i;
    for (i = 1; i < n; ++i)
    {
        if (sign(a[i].x - a[0].x) < 0 || (sign(a[i].x - a[0].x) == 0 && sign(a[i].y - a[0].y) < 0))
        {
            swap(a[i], a[0]);
        }
    }

    convex_hull_p0 = a[0]; //这两行代码不要顺序调换了..否则会WA
    sort(a, a + n, convex_hull_cmp);

    b[0] = a[0];
    b[1] = a[1];
    int newn = 2;
    for (i = 2; i < n; ++i)
    {
        while (newn > 1 && sign(mul(b[newn - 1], b[newn - 2], a[i])) >= 0)
        {
            newn--;
        }

        b[newn++] = a[i];
    }

    return newn;
}

double crossProd(PPoint A, PPoint B, PPoint C)
{
    return (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        scanf("%d", &n);
        int i;
        for (i = 0; i < n; ++i)
        {
            scanf("%lf %lf", &p[i].x, &p[i].y);
        }

        n = convex_hull(p, n, p);
        p[n] = p[0];

        double max_ans = -1;

        int j;
        int k;

        double ans = 0;
        for (i = 0; i < n; i++)
        {
            for (j = i+1; j < n; j++)
            {
                if (i == j)
                    continue;
                double M1 = 0, M2 = 0;
                for (k = 0; k < n; k++)
                {
                    if (k == i || k == j)
                        continue;
                    double a = p[i].y - p[j].y, b = p[j].x - p[i].x, c = p[i].x * p[j].y - p[j].x * p[i].y;
                    double temp;
                    temp = a * p[k].x + b * p[k].y + c;
                    if (temp > 0)
                    {
                        M1 = max(fabs(crossProd(p[i], p[j], p[k]) / 2), M1);
                    }
                    else if (temp < 0)
                    {
                        M2 = max(fabs(crossProd(p[i], p[j], p[k]) / 2), M2);
                    }
                }
                max_ans = max(max_ans, M1 + M2);
            }
        }
        if (fabs(max_ans - int(max_ans)) < 1e-9)
            printf("%d\n", int(max_ans));
        else
            printf("%d.5\n", (int)max_ans);
    }

    return 0;
}
//  if (fab (ans - int(ans)) < 1e-9)
//      printf("%d\n", int(ans));
//  else
//     printf("%d.5\n", (int)ans);
