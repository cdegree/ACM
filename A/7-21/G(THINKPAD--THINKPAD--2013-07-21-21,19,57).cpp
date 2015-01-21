/*





*/


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
using namespace std;

typedef long long LL ;

const int N = 105;
const int E = 405*2;
const int inf = 1000000000;
const double eps=1e-8;
struct Edge
{
    int st,en,next;
    double cap,flow;
    bool cut;
} edge[E];
int head[N] , now[N];
int src,dest,node,nedge;
int pre[N] , dis[N] , gap[N];

void add_edge(int st,int en,double cap)
{
    edge[nedge].st=st;
    edge[nedge].en=en;
    edge[nedge].cap=cap;
    edge[nedge].flow=0;
    edge[nedge].next=head[st];
    head[st]=nedge++;

    edge[nedge].st=en;
    edge[nedge].en=st;
    edge[nedge].cap=cap;
    edge[nedge].flow=0;
    edge[nedge].next=head[en];
    head[en]=nedge++;
}

void augment(double flow)
{
    for(int i=src;i!=dest;i=edge[now[i]].en)
    {
        edge[now[i]].flow+=flow;
        edge[now[i]^1].flow-=flow;
    }
}

double sap()
{
    memset(dis,0,sizeof(dis));
    memset(gap,0,sizeof(gap));
    memset(pre,-1,sizeof(pre));
    for(int i=0;i<node;i++)
        now[i]=head[i];
    gap[0]=node;
    int point=src;
    double flow=0;
    double min_flow=inf;
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
    nedge=0;
    node=_node;
    src=_src;
    dest=_dest;
    for(int i=0;i<node;i++)head[i]=-1;
}

int res[N];
int EG[E][3];
int len=0;
bool vis[N];
void dfs(int u)
{
    vis[u]=true;
    for(int e=head[u];~e;e=edge[e].next)
    {
        if(fabs(edge[e].flow-edge[e].cap)>eps&&!vis[edge[e].en])
        {
            dfs(edge[e].en);
        }
    }
}
int main()
{
    int n,m;
    int T=0;
    while(cin>>n>>m)
    {
        len=0;
        for(int i=0;i<m;++i)
        {
            int u,v,c;
            scanf("%d %d %d",&u,&v,&c);
            EG[i][0]=u;
            EG[i][1]=v;
            EG[i][2]=c;
        }
        double l=0,r=1e9,ans,mid;
        while(l<=r-eps)
        {
            len=0;
            init(n+1,1,n);
            mid=(l+r)/2;
            printf("mid = %lf\n",mid);
            double sum=0;
            for(int i=0;i<m;++i)
            {
                if(EG[i][2]<=mid+eps)
                {
                    sum += mid-edge[i].cap;
                }
                else
                {
                    add_edge(EG[i][0],EG[i][1],EG[i][2]-mid);
                }
            }
            printf("%lf\n",mid);
            double res = sap();
            puts("ok");
            if(sum+eps>=res)
            {
                r=mid;
            }
            else
            {
                l=mid;
            }
        }
        printf("l = %.6f\n",l);
        memset(vis,false,sizeof(vis));
        dfs(1);
        for(int i=1;i<=n;++i)
        {
            if(vis[i])printf("%d:  %d\n",i,vis[i]);
        }
        for(int i=0;i<m;++i)
        {
            if(EG[i][0]<l+eps|| vis[ EG[i][0] ]!=vis[ EG[i][1] ] )
            {
                res[len++]=i+1;
            }
        }
        printf("%d\n",len);
        for(int i=0;i<len;++i)
        {
            printf("%d%c",res[i],i==len-1?'\n':' ');
        }
    }
	return 0;
}
