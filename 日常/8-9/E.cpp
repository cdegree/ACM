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
double eps=1e-7;
struct point
{
    double x,y;
};
const int N = 40004;
struct Segment
{
    point st,ed;
    point vec;
    double mxs,mxe;
    double len,A,B,C;
    void pre()
    {
        A = st.y - ed.y;
        B = ed.x - st.x;
        C =  (st.x-ed.x)*st.y-(st.y-ed.y)*st.x;
        vec.x=ed.x-st.x;
        vec.y=ed.y-st.y;
        len = sqrt(sqr(vec.x)+sqr(vec.y) );
    }
    point cross(Segment l)
    {
        point ret ;
        double A1=A, B1=B, C1=C;
        double A2=l.A, B2=l.B, C2=l.C;
        //printf("A1=%f,B1=%f,C1=%f\n",A1,B1,C1);
        //printf("A2=%f,B2=%f,C2=%f\n",A2,B2,C2);
        ret.x=(B1*C2-B2*C1)/(A1*B2-A2*B1);
        ret.y=(A1*C2-A2*C1)/(A2*B1-A1*B2);
        return ret;
    }
} S[N];
int n;
double a;

bool parr(Segment a,Segment b)
{
    return fabs( (a.st.x-a.ed.x)*(b.st.y-b.ed.y) - (a.st.y-a.ed.y)*(b.st.x-b.ed.x)  )<eps;
}
double dot(Segment a,Segment b)
{
    return a.vec.x*b.vec.x+a.vec.y*b.vec.y;
}
double get_m(Segment a)
{
    return sqrt(sqr(a.vec.x)+sqr(a.vec.y) );
}
double get_cos(Segment a,Segment b)
{
    return dot(a,b)/get_m(a)/get_m(b);
}
double get_dis(point a,point b)
{
    return sqrt( sqr(a.x-b.x) + sqr(a.y-b.y) );
}
double get_r(Segment a,Segment b)
{
    if(fabs(fabs(get_cos(a,b))-1)<eps)
    {
        return get_dis(a.ed,b.st)/2.0;
    }
    point p,q;
    p.x = a.ed.x + b.vec.x;
    p.y = a.ed.y + b.vec.y;
    q.x = b.st.x + a.vec.x;
    q.y = b.st.y + a.vec.y;
    Segment pp,qq ;
    pp.st = p;
    pp.ed = a.ed;
    qq.st = q;
    qq.ed = b.st;
    pp.pre();
    qq.pre();
    //printf("p=%f,%f\n",p.x,p.y);
    //printf("q=%f,%f\n",q.x,q.y);
    point ret = pp.cross(qq);
    //printf("segment %f,%f -> %f,%f\n and %f,%f -> %f,%f\n",a.st.x,a.st.y,a.ed.x,a.ed.y,b.st.x,b.st.y,b.ed.x,b.ed.y);
    //printf("cross at %f,%f\n",ret.x,ret.y);
    return get_dis(ret,a.ed);
}
double res;

void gao(double mxs,double mxe,double len,double v0,double &v1,double &t)
{
    double S1,S2,t1,t2;
    v1=0,t=0;
    //printf("%f %f %f %f %f %f\n",mxs,mxe,len,v0,v1,t);
    if( sqrt( sqr(v0) + 2.0*a*len ) > mxe )
    {
        v1 = mxe;
    }
    else
    {
        v1 = sqrt( sqr(v0) + 2*a*len );
    }
    //printf("v0 = %f v1 = %f a = %f\n",v0,v1,a);
    S1 = len/2 + ((sqr(v1)-sqr(v0))/a/4);
    //printf("%.6f %.6f %.6f %.6f\n",S1,S2,t1,t2);
    S2 = len/2 - ((sqr(v1)-sqr(v0))/a/4);
    //printf("%.6f %.6f %.6f %.6f\n",S1,S2,t1,t2);

    t1 = (-v0+sqrt( fabs( sqr(v0) + 2*a*S1)) )/a;
    //printf(" sqrt = %f\n",sqr(v0)+ 2*a*S1);
    //printf("%.6f %.6f %.6f %.6f\n",S1,S2,t1,t2);
    double v2 = t1*a+v0;
    t2 = ( v2-sqrt( fabs( sqr(v2) - 2*a*S2)) )/a;
    //printf("%.6f %.6f %.6f %.6f\n",S1,S2,t1,t2);
    t=t1+t2;
}

point turn_right(point a)
{
    point ret = a;
    swap(ret.x,ret.y);
    ret.y=-ret.y;
    return ret;
}

double mulx(point a,point b)
{
    return a.x*b.y - a.y*b.x;
}

bool judge(Segment x,Segment y)
{
    point v2 = turn_right( x.vec );
    point v3;
    v3.x = y.st.x - x.ed.x;
    v3.y = y.st.y - x.ed.y;
    //printf("mx = %f\n",mulx(v2,v3));
    if( mulx(v2,v3) >= -eps )
    {
        return true;
    }
    else
    {
        return false;
    }
}
void gao()
{
    for(int i=0; i<n-1; ++i)
    {
        double r = get_r(S[i],S[i+1]);
        //printf(" %f,%f   r = %.7f\n",S[i].st.x,S[i].st.y,r);
        S[i].mxe = sqrt( r*a );
        //printf("mxe = %f\n",S[i].mxe);
    }
    S[n-1].mxe=0;
    double v0=0,v,t;
    for(int i=n-1; i>=0; --i)
    {
        v0=S[i].mxe;
        S[i].mxs = sqrt(sqr(v0)+2.0*a*S[i].len);
        if(i>0&&S[i].mxs<S[i-1].mxe)S[i-1].mxe=S[i].mxs;
    }
    for(int i=0; i<n; ++i)
    {
        //printf("%.6f %.6f\n",S[i].mxs,S[i].mxe);
    }
    res=0;
    double v1;
    v0=0;
    for(int i=0; i<n; ++i)
    {
        gao(S[i].mxs,S[i].mxe,S[i].len,v0,v1,t);
        if(i+1<n)
        {
            double r = get_r(S[i],S[i+1]);
            double cos = get_cos(S[i],S[i+1]);
            //printf("r = %f cos=%f\n",r,cos);
            if( fabs(cos)<eps )
            {
                //printf("cosa=%f\n",1.0);
                if(judge(S[i],S[i+1]))
                {
                    //printf("small\n");
                    t += PI*r/v1/2.0;
                }
                else
                {
                    //printf("big\n");
                    t += 3.0/2.0*PI*r/v1;
                }
            }
            else if( fabs(fabs(cos)-1)<eps )
            {
                //printf("sem\n");
                t += PI/v1*r;
            }
            else while(1);
            //printf("r = %f\n",r);
        }
        v0=v1;
        res += t;
        //printf("res = %.6f\n",res);
    }
}
int main()
{
    freopen("10.in","r",stdin);
    while(~scanf("%d%lf",&n,&a))
    {
        double sx,sy,ex,ey;
        for(int i=0; i<n; ++i)
        {
            scanf("%lf %lf %lf %lf",&sx,&sy,&ex,&ey);
            S[i].st.x=sx;
            S[i].st.y=sy;
            S[i].ed.x=ex;
            S[i].ed.y=ey;
            S[i].pre();
            //printf("%f,%f -> %f,%f\n",S[i].st.x,S[i].st.y,S[i].ed.x,S[i].ed.y);
        }
        gao();
        printf("%.8f\n",res);
    }
    return 0;
}
