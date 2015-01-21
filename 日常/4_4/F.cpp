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
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef double DB;

const int N = 603;
const int E = 200005;
const int inf = 1e8;
double eps = 1e-8;
struct Edge
{
    int en,cap,flow,next;
} edge[E];
int head[N] , now[N];
int src,dest,node,nedge;
int pre[N] , dis[N] , gap[N];

void add_edge(int st,int en,int cap)
{
    edge[nedge].en=en;
    edge[nedge].cap=cap;
    edge[nedge].flow=0;
    edge[nedge].next=head[st];
    head[st]=nedge++;

    edge[nedge].en=st;
    edge[nedge].cap=0;
    edge[nedge].flow=0;
    edge[nedge].next=head[en];
    head[en]=nedge++;
}

void augment(int flow)
{
    for(int i=src;i!=dest;i=edge[now[i]].en)
    {
        edge[now[i]].flow+=flow;
        edge[now[i]^1].flow-=flow;
    }
}

int sap()
{
    memset(dis,0,sizeof(dis));
    memset(gap,0,sizeof(gap));
    memset(pre,-1,sizeof(pre));
    for(int i=0;i<node;i++)
        now[i]=head[i];
    gap[0]=node;
    int point=src,flow=0,min_flow=inf;
    while(dis[src]<node)
    {
        bool fg=false;
        for(int i=now[point];~i;i=edge[i].next)
            if(edge[i].cap-edge[i].flow>0 && dis[point]==dis[edge[i].en]+1)
            {
                min_flow=min(min_flow,edge[i].cap-edge[i].flow);
                now[point]=i;
                pre[edge[i].en]=point;
                point=edge[i].en;
                if(point==dest)
                {
                    flow+=min_flow;
                    augment(min_flow);
                    point=src;
                    min_flow=inf;
                }
                fg=true;
                break;
            }
        if(fg) continue;
        if(--gap[dis[point]]==0) break;
        int Min=node;
        for(int i=head[point];~i;i=edge[i].next)
            if(edge[i].cap-edge[i].flow>0 && Min>dis[edge[i].en])
            {
                Min=dis[edge[i].en];
                now[point]=i;
            }
        gap[dis[point]=Min+1]++;
        if(point!=src) point=pre[point];
    }
    return flow;
}

void init(int _node,int _src,int _dest)
{
    node=_node;
    src=_src;
    dest=_dest;
    nedge=0;
    for(int i=0;i<node;i++)head[i]=-1;
}

struct point
{
    double x,y,z;
    int f,l;
}P[105];


double get_dis(point a,point b)
{
    return sqrt( (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) + (a.z-b.z)*(a.z-b.z)  );
}

int n;
int sum = 0 ;
bool judge(double K)
{
    init(2*n+2,2*n+1,0);

    for(int i=1;i<n;++i)
    {
        add_edge(src,i,P[i].f);
        add_edge(i,i+n,P[i].l);
        if(get_dis(P[i],P[dest])<=K+eps)
        {
            add_edge(i+n,dest,inf);
        }
    }
    
    for(int i=1;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(get_dis(P[i],P[j])<=K+eps)
            {
                add_edge(i+n,j,inf);
                add_edge(j+n,i,inf);
            }
        }
    }
    int ss = sap();
    if(ss+P[0].f==sum)return true;
    else return false;    
}



int main()
{
    freopen("Fin.txt","r",stdin);
    while(~scanf("%d",&n))
    {
        sum=0;
        for(int i=0;i<n;++i)
        {
            scanf("%lf %lf %lf %d %d",&P[i].x,&P[i].y,&P[i].z,&P[i].f,&P[i].l);
            sum+=P[i].f;
        }  
        double l=0,r=inf,mid,ans=-1;
        bool ok=false;
        for(int i=0;i<200;i++)
        {
                mid = (l+r)/2;
                if(judge(mid))
                {
                    ok=true;
                    ans = mid ;
                    r = mid ;
                    //printf("r = %f  mid = %f\n",r,mid );
                }
                else 
                {
                    l = mid ;
                }
        }
        if(  !ok  )
        {
            printf("-1\n");
        }
        else 
        {
            printf("%.7f\n", ans);
        }
    }
    return 0;
}
