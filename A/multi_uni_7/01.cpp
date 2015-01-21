#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#define F(i,a,b) for(int i=a;i<b;i++)
using namespace std;

double const jd=1e-9;
double const pi=3.141592653589793238;
double const inf=1e100;
int const maxn=100001;
int const fa=101;
int N,M;

struct wgh3
{
    double x1,y1,x2,y2,x3,y3;
} a3[fa];
struct point
{
    double x,y;
    double r;
    int u;
    point() {}
    point(double _x, double _y)
    {
        x = _x;
        y = _y;
    }
    point(point a, point b)
    {
        x=b.x-a.x;
        y=b.y-a.y;
    }
    point operator+(point a)
    {
        return point(x + a.x, y + a.y);
    }
    point operator-(point a)
    {
        return point(x-a.x, y-a.y);
    }
    double operator*(point a)
    {
        return x * a.y-y * a.x;
    }
    point Rotate(double theta)
    {
        return point(x * cos(theta)-y * sin(theta), x * sin(theta) +
                     y * cos(theta));
    }
    double get_dis()
    {
        return sqrt( x*x + y*y );
    }
//    point rotate(point center, double theta)
//    {
//        point tmp = *this-center;
//        return tmp.rotate(theta) + center;
//    }
};
point op,v[maxn],a1[fa];

inline int realcmp(double a,double b)
{
    if (fabs(a-b)<jd)return 0;
    if (a>b) return 1;
    else return -1;
}//a>b则返回1,==返回0 a<b返回-1

double dis(point a,point b)
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

double vdet(point op,point p1,point p2)
{
    return (p1.x-op.x)*(p2.y-op.y)-(p2.x-op.x)*(p1.y-op.y);
}

int cmp(const point &p1,const point &p2)
{
    double temp=vdet(op,p1,p2);
    if (realcmp(temp,0)==0)return dis(p2,op)>dis(p1,op);
    return temp>0;
}

void gethull(point p[],int np,point v[],int &nv)
{
    point minp;
    int lc;
    minp.y=inf;
    for(int i=0; i<np; i++)
    {
        if (realcmp(minp.y,p[i].y)==1 || (realcmp(minp.y,p[i].y)==0 && realcmp(minp.x,p[i].x)==1))
            minp=p[i],lc=i;
    }
    op=minp;
    swap(p[0],p[lc]);
    sort(p+1,p+np,cmp);
    int st[maxn],top=2;
    st[0]=0,st[1]=1;
    for(int i=2; i<np; i++)
    {
        while(top>=2)
        {
            int id1=st[top-1],id2=st[top-2];
            if (realcmp((p[id1].x-p[id2].x)*(p[i].y-p[id1].y)-(p[id1].y-p[id2].y)*(p[i].x-p[id1].x),0)!=-1)break;
            top--;
        }
        st[top++]=i;
    }
    for(int i=0; i<top; i++)
        v[i]=p[st[i]];
    v[top]=v[0],nv=top;
}//求凸包，p为原始点集，v为凸包点集，有一点注意的是，如果边界某连续三点共线，则把它们都放到凸包中！
//返回nv个顶点的凸包，但是 注意多边形封闭储存，所以v数组存到nv为止！
double dd(point a,point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
void calc_qie(point poi,point o,double r,point &result1,point &result2)
{
    double line = sqrt((poi.x-o.x)*(poi.x-o.x)+(poi.y-o.y)*(poi.y-o.y));
    double angle = acos(r/line);
    point unitvector,lin;
    lin.x = poi.x-o.x;
    lin.y = poi.y-o.y;
    unitvector.x = lin.x/sqrt(lin.x*lin.x+lin.y*lin.y)*r;
    unitvector.y = lin.y/sqrt(lin.x*lin.x+lin.y*lin.y)*r;
    result1 = unitvector.Rotate(-angle);
    result2 = unitvector.Rotate(angle);
    result1.x += o.x;
    result1.y += o.y;
    result2.x += o.x;
    result2.y += o.y;
}
int tc,tn;
point tp[8000],c[700];
void gao()
{
    tn = 0;
    tc=N;
    for (int i = 0; i < tc; i++)
    {
        point oo;
        oo.x=a1[i].x;
        oo.y=a1[i].y;
        oo.r=a1[i].r;
        c[i]=oo;
    }
    point a,b,vab;
    double tab,tt,dis,theta;
    for (int i = 0; i < tc; i++)
        for (int j = 0; j < tc; j++)
            if (i != j)
            {
                a = c[i];
                b = c[j];
                vab = point(a,b);
                tab = atan2(vab.y,vab.x);
                dis = sqrt(vab.x*vab.x+vab.y*vab.y);
                if (b.r > a.r)
                    tt = asin((b.r-a.r)/dis);
                else
                    tt =-asin((a.r-b.r)/dis);
                theta = tab+pi/2+tt;

                tp[tn] = point(a.x+a.r*cos(theta),a.y+a.r*sin(theta));
                tp[tn++].u=i;
                tp[tn] = point(b.x+b.r*cos(theta),b.y+b.r*sin(theta));
                tp[tn++].u=j;
            }
}
double hu(point a,point b)
{
    int u=a.u;
    point xx,yy;
    xx=a-a1[u];
    yy=b-a1[u];
    //printf("o =%lf,%lf\n",a1[u].x,a1[u].y);
    //printf("v1=%lf,%lf\n",xx.x,xx.y);
    //printf("v2=%lf,%lf\n",yy.x,yy.y);

    double d1=xx.get_dis();
    double d2=yy.get_dis();
    double cs = (xx.x*yy.x+xx.y*yy.y)/d1/d2;
    //if(cs>1)cs=1;
    //if(cs<-1)cs=-1;
    double st= acos(cs);
    point tb = yy.Rotate(st);
    //printf("cos=%.6f\t acos = %.6f\n",cs,st);
    if( fabs(tb.x-xx.x) +fabs(tb.y-xx.y) > 1e-7 )
    {
        st = 2*pi-st;
    }
    //printf("st = %.6f\n",st);
    return st*a1[u].r;
}
point p[50005],h[50005];
void work()
{

    int  n,m,l;
    n=0;
    {
        F(i,0,M)
        {
            p[i*3].x=a3[i].x1;
            p[i*3].y=a3[i].y1;
            p[i*3].u=i+N;
            p[i*3+1].x=a3[i].x2;
            p[i*3+1].y=a3[i].y2;
            p[i*3+1].u=i+N;
            p[i*3+2].x=a3[i].x3;
            p[i*3+2].y=a3[i].y3;
            p[i*3+2].u=i+N;
        }
        n=M*3;
        F(i,0,M*3)
        {
            F(j,0,N)
            {
                point b1,b2;
                point o;
                o.x=a1[j].x;
                o.y=a1[j].y;
                calc_qie(p[i],o,a1[j].r,b1,b2);
                p[n].x=b1.x;
                p[n].y=b1.y;
                p[n].u=j;
                n++;
                p[n].x=b2.x;
                p[n].y=b2.y;
                p[n].u=j;
                n++;
            }
        }
        gao();
        F(i,0,tn)
        {
            p[n]=tp[i];
            //printf("%lf %lf\n",p[i].x,p[i].y);
            n++;
        }
        gethull(p,n,h,m);
        double len=0;
        //F(i,1,m+1)
        {
            //printf("%lf %lf\n",h[i].x,h[i].y);
        }
        F(i,1,m+1)
        {
            if(h[i].u!=h[i-1].u)
            {
                len+=dd(h[i],h[i-1]);
                //cout<<dd(h[i],h[i-1])<<endl;
            }
            else
            {
                if(h[i].u<N)
                {
                    len+=hu(h[i],h[i-1]);
                    //cout<<hu(h[i],h[i-1])<<endl;
                }
                else
                {
                    len+=dd(h[i],h[i-1]);
                    //cout<<dd(h[i],h[i-1])<<endl;
                }
            }
        }
        printf("%.5f\n",len);
    }
}
int main()
{
    int i,j,k;
    while(~scanf("%d%d",&N,&M))
    {

        for(i=0; i<N; i++)
        {
            scanf("%lf%lf%lf",&a1[i].x,&a1[i].y,&a1[i].r);
        }
        for(i=0; i<M; i++)
        {
            scanf("%lf%lf%lf%lf%lf%lf",&a3[i].x1,&a3[i].y1,&a3[i].x2,&a3[i].y2,&a3[i].x3,&a3[i].y3);
        }
        if(N==1&&M==0)
        {
            printf("%.5f\n",pi*a1[0].r*a1[0].r);
            continue;
        }
        work();
    }
}
