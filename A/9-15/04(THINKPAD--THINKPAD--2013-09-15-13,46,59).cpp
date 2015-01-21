#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <iostream>
#include <string>
#include <set>
#define X first
#define Y second
#define sqr(x) (x)*(x)
#pragma comment(linker,"/STACK:102400000,102400000")
using namespace std;
const double PI = acos(-1.0);
map<int, int>::iterator it;
typedef long long LL ;
template<typename T> void checkmin(T &x, T y) {x = min(x, y);}
template<typename T> void checkmax(T &x, T y) {x = max(x, y);}
#define eps 1e-8
#define zero(x) (((x)>0?(x):-(x))<eps)
struct point3 {double x, y, z;};
struct line3 {point3 a, b;};
struct plane3 {point3 a, b, c;};

//计算cross product U x V
point3 xmult(point3 u, point3 v) {
    point3 ret;
    ret.x = u.y * v.z - v.y * u.z;
    ret.y = u.z * v.x - u.x * v.z;
    ret.z = u.x * v.y - u.y * v.x;
    return ret;
}

//计算dot product U . V
double dmult(point3 u, point3 v) {
    return u.x * v.x + u.y * v.y + u.z * v.z;
}

//矢量差 U - V
point3 subt(point3 u, point3 v) {
    point3 ret;
    ret.x = u.x - v.x;
    ret.y = u.y - v.y;
    ret.z = u.z - v.z;
    return ret;
}

//取平面法向量
point3 pvec(plane3 s) {
    return xmult(subt(s.a, s.b), subt(s.b, s.c));
}
point3 pvec(point3 s1, point3 s2, point3 s3) {
    return xmult(subt(s1, s2), subt(s2, s3));
}

//两点距离,单参数取向量大小
double distance(point3 p1, point3 p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y) + (p1.z - p2.z) * (p1.z - p2.z));
}

//向量大小
double vlen(point3 p) {
    return sqrt(p.x * p.x + p.y * p.y + p.z * p.z);
}


double linetoline(line3 u, line3 v) {
    point3 n = xmult(subt(u.a, u.b), subt(v.a, v.b));
    return fabs(dmult(subt(u.a, v.a), n)) / vlen(n);
}
double linetoline(point3 u1, point3 u2, point3 v1, point3 v2) {
    point3 n = xmult(subt(u1, u2), subt(v1, v2));
    return fabs(dmult(subt(u1, v1), n)) / vlen(n);
}

int main() {
    int T;
    scanf("%d",&T);
    line3 L[2];
    while(T--)
    {
        for(int i=0;i<2;++i)
        {
            scanf("%lf%lf%lf",&L[i].a.x,&L[i].a.y,&L[i].a.z);
            scanf("%lf%lf%lf",&L[i].b.x,&L[i].b.y,&L[i].b.z);
        }
        double res = linetoline(L[0],L[1]);
        printf("%.6f\n",res);
    }
    return 0;
}
