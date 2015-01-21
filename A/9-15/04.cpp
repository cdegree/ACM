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

point3 xmult(point3 u, point3 v) {
    point3 ret;
    ret.x = u.y * v.z - v.y * u.z;
    ret.y = u.z * v.x - u.x * v.z;
    ret.z = u.x * v.y - u.y * v.x;
    return ret;
}

double dmult(point3 u, point3 v) {
    return u.x * v.x + u.y * v.y + u.z * v.z;
}

point3 subt(point3 u, point3 v) {
    point3 ret;
    ret.x = u.x - v.x;
    ret.y = u.y - v.y;
    ret.z = u.z - v.z;
    return ret;
}

point3 pvec(plane3 s) {
    return xmult(subt(s.a, s.b), subt(s.b, s.c));
}
point3 pvec(point3 s1, point3 s2, point3 s3) {
    return xmult(subt(s1, s2), subt(s2, s3));
}

double dist(point3 p1, point3 p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y) + (p1.z - p2.z) * (p1.z - p2.z));
}

double vlen(point3 p) {
    return sqrt(p.x * p.x + p.y * p.y + p.z * p.z);
}

point3 vect;
double linetoline(line3 u, line3 v) {
    point3 n = xmult(subt(u.a, u.b), subt(v.a, v.b));
    vect=n;
    //printf("%.6f %.6f %.6f\n",n.x,n.y,n.z);
    return fabs(dmult(subt(u.a, v.a), n)) / vlen(n);
}
double linetoline(point3 u1, point3 u2, point3 v1, point3 v2) {
    point3 n = xmult(subt(u1, u2), subt(v1, v2));
    return fabs(dmult(subt(u1, v1), n)) / vlen(n);
}


point3 intersection(line3 l,plane3 s){
	point3 ret=pvec(s);
	double t=(ret.x*(s.a.x-l.a.x)+ret.y*(s.a.y-l.a.y)+ret.z*(s.a.z-l.a.z))/
		(ret.x*(l.b.x-l.a.x)+ret.y*(l.b.y-l.a.y)+ret.z*(l.b.z-l.a.z));
	ret.x=l.a.x+(l.b.x-l.a.x)*t;
	ret.y=l.a.y+(l.b.y-l.a.y)*t;
	ret.z=l.a.z+(l.b.z-l.a.z)*t;
	return ret;
}


int main() {
    int T;
    scanf("%d",&T);
    line3 L[2];
    plane3 PL[2];
    while(T--)
    {
        for(int i=0;i<2;++i)
        {
            scanf("%lf%lf%lf",&L[i].a.x,&L[i].a.y,&L[i].a.z);
            scanf("%lf%lf%lf",&L[i].b.x,&L[i].b.y,&L[i].b.z);
        }
        double res = linetoline(L[0],L[1]);
        for(int i=0;i<2;++i)
        {
            PL[i].a = L[i].a;
            PL[i].b = L[i].b;
            point3 tmp = L[i].a;
            tmp.x += vect.x;
            tmp.y += vect.y;
            tmp.z += vect.z;
            PL[i].c = tmp;
        }
        point3 ress[2];
        for(int i=0;i<2;++i)
        {
            ress[i] = intersection(L[i],PL[1-i]);
        }
        printf("%.6f\n",res);
        for(int i=0;i<2;++i)
        {
            printf("%.6f %.6f %.6f",ress[i].x,ress[i].y,ress[i].z);
            if(i==0)putchar(' ');
        }
        puts("");
    }
    return 0;
}
