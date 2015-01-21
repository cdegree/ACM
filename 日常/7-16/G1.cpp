#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
#define eps 1e-10
#define max 10000.0
#define N 10005
struct Point
{
    double x,y;
};
struct Line
{
    Point a,b;
};
struct Polygon
{
    int n;
    Point p[N];
};
Polygon pg,tpg;
Line ls[N];
int dq[N];
int ord[N];
double ang[N];
int n;
double Xmult(Point o,Point a,Point b)
{
    return (a.x-o.x)*(b.y-o.y)-(b.x-o.x)*(a.y-o.y);
}
int Sig(double a)
{
    return (a<-eps)?-1:(a>eps);
}
Point Intersection(Line u,Line v)
{
    Point ret=u.a;
    double t=((u.a.x-v.a.x)*(v.a.y-v.b.y)-(u.a.y-v.a.y)*(v.a.x-v.b.x))/
             ((u.a.x-u.b.x)*(v.a.y-v.b.y)-(u.a.y-u.b.y)*(v.a.x-v.b.x));
    ret.x+=(u.b.x-u.a.x)*t;
    ret.y+=(u.b.y-u.a.y)*t;
    return ret;
}
Line Get_line(Point a,Point b)
{
    Line l;
    l.a=a;
    l.b=b;
    return l;
}
Point Move_line(Point a,Point b,Point ret,double L)
{
    Point tmp;
//根据向量平面以后 线上点的(x,y)增减 进行加减
    tmp.x=a.y-b.y;
    tmp.y=b.x-a.x;
    double len=sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
    tmp.x/=len,tmp.x*=L;
    tmp.y/=len,tmp.y*=L;
    tmp.x+=ret.x;
    tmp.y+=ret.y;
    return tmp;
}
bool Judgeout(int x,int y,int z)
{
    Point pnt = Intersection(ls[x],ls[y]); //平面交点
    return  Sig(Xmult(ls[z].a,ls[z].b,pnt))<0;//判断交点是否在当前平面外 如果要排除三点共线，改成<=
}
int Cmp(int u,int v)
{
    if(Sig(ang[u]-ang[v])==0)
        return Xmult(ls[u].a,ls[u].b,ls[v].b)<=0;
    return ang[u]<ang[v];
}
void HalfPlaneIntersection()
{
    int i;
    int tmpn;
    for(i=0; i<n; i++)
    {
        ang[i]=atan2(ls[i].b.y-ls[i].a.y,ls[i].b.x-ls[i].a.x);
        ord[i]=i;
    }
    sort(ord,ord+n,Cmp);
    for(i=tmpn=1; i<n; i++)
        if(Sig(ang[ord[i]]-ang[ord[i-1]])!=0)
            ord[tmpn++]=ord[i];
    n=tmpn;
    int bot=1,top=2;//双端栈，bot为栈底，top为栈顶
    dq[bot]=ord[0],dq[top]=ord[1];//先压两根线进栈
    for(i=2; i<n; i++)
    {
//bot < top 表示要保证栈里至少有2条线段，如果剩下1条，就不继续退栈
//judgeout，判断如果栈中两条线的交点如果在当前插入先的右边，就退栈
// 即 平面的交点在当前平面外 退栈
        while( bot < top && Judgeout(dq[top-1] , dq[top] , ord[i]) ) top--;
//对栈顶要同样的操作
        while( bot < top && Judgeout(dq[bot+1] , dq[bot] , ord[i]) ) bot++;
        dq[++top] = ord[i];
    }
//最后还要处理一下栈里面存在的栈顶的线在栈底交点末尾位置，或者栈顶在栈尾两条线的右边
    while( bot < top && Judgeout(dq[top-1] , dq[top] , dq[bot]) ) top--;
    while( bot < top && Judgeout(dq[bot+1] , dq[bot] , dq[top]) ) bot++;
    pg.n = 0;
    if(bot+1>=top)
        return ;
    dq[--bot] = dq[top];  //最后一条线是重合的 便于算交点
    for(i = bot + 1; i <= top ; i++) //求相邻两条线的交点
        pg.p[pg.n++] = Intersection(ls[dq[i-1]],ls[dq[i]]);
}
int Judge(double L)
{
    int i,j;
    for(i=0; i<tpg.n; i++)
    {
        ls[i].a=Move_line(tpg.p[i],tpg.p[i+1],tpg.p[i],L);
        ls[i].b=Move_line(tpg.p[i],tpg.p[i+1],tpg.p[i+1],L);
    }
    HalfPlaneIntersection();
    if(pg.n)
        return 1;
    return 0;
}
int main()
{
    int i;
    int t;
    while(scanf("%d",&n) && n)
    {
        tpg.n=n;
        for(i=0; i<n; i++)
            scanf("%lf%lf",&tpg.p[i].x,&tpg.p[i].y);
        tpg.p[n]=tpg.p[0];
        double left=0,right=100000000;
        double mid;
        while(left+eps<right)
        {
            mid=(left+right)*0.5;
            if(Judge(mid))
                left=mid;
            else
                right=mid;
        }
        printf("%.6lf\n",right);
    }
    return 0;
}
