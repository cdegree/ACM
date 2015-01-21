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
using namespace std;
const double PI = acos(-1.0);
map<int,int>::iterator it;
typedef long long LL ;
#pragma comment(linker,"/STACK:102400000,102400000")
const double eps = 1e-7;
struct point
{
    double x,y;
    double r;
};
double xmult(point p1,point p2,point p0)
{
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
double get_dis(point p1,point p2)
{
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

point intersection(point u1,point u2,point v1,point v2)
{
    point ret=u1;
    double t=((u1.x-v1.x)*(v1.y-v2.y)-(u1.y-v1.y)*(v1.x-v2.x))
             /((u1.x-u2.x)*(v1.y-v2.y)-(u1.y-u2.y)*(v1.x-v2.x));
    ret.x+=(u2.x-u1.x)*t;
    ret.y+=(u2.y-u1.y)*t;
    return ret;
}

point ptoseg(point p,point l1,point l2)
{
    point t=p;
    t.x+=l1.y-l2.y,t.y+=l2.x-l1.x;
    if (xmult(l1,t,p)*xmult(l2,t,p)>eps)
        return get_dis(p,l1)<get_dis(p,l2)?l1:l2;
    return intersection(p,t,l1,l2);
}
double get_dis(double x1,double y1,double x2,double y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

double ptoconvex(point *p,int n,point q)
{
    double ret=1e9;
    for(int i=0;i<n;++i)
    {
        ret = min(ret, get_dis(q,ptoseg(q,p[0],p[(i+1)%n])));
    }
    return ret;
}

point P[4];


int main()
{
    point st;
    while(~scanf("%lf%lf",&st.x,&st.y))
    {
        if( fabs(st.x)<eps&&fabs(st.y)<eps )break;
        point r;
        scanf("%lf%lf%lf",&r.x,&r.y,&r.r);
        double x1,y1,x2,y2;
        scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
        P[0].x=x1,P[0].y=y1;
        P[1].x=x1,P[1].y=y2;
        P[2].x=x2,P[2].y=y1;
        P[3].x=x2,P[3].y=y2;
        double res = 1e9;
        const int m = 2000;
        for(int i=0;i<m;++i)
        {
            double x = r.x+r.r*cos(2.0*i*PI/m);
            double y = r.y+r.r*sin(2.0*i*PI/m);
            point p ;
            p.x=x,p.y=y;
            double dis = get_dis(x,y,st.x,st.y) + ptoconvex(P,4,p) ;
            res = min(res,dis);
        }
        printf("%.2f\n",res);
    }
	return 0;
}
