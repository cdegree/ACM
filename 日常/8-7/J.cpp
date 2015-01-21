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

int n,m,L;
struct nod
{
    int id;
    int t;
}nd[1005];

int dist[105][105];

typedef long long LL;
typedef unsigned long long ULL;
typedef double DB;

const int N = 2005;
const int E = 4000005;
const int inf = 1000000000;
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
    nedge=0;
    node=_node;
    src=_src;
    dest=_dest;
    for(int i=0;i<node;i++)head[i]=-1;
}


int main()
{
    freopen("j.txt","r",stdin);
    while(1)
    {
        scanf("%d%d%d",&n,&m,&L);
        if(n==0&&m==0&&L==0)break;
        memset(dist,63,sizeof(dist));
        for(int i=0;i<n;++i)dist[i][i]=0;
        for(int i=0;i<m;++i)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            dist[u][v]=min(w,dist[u][v]);
            dist[v][u]=min(w,dist[v][u]);
        }
        for(int k=0;k<n;++k)
        {
            for(int i=0;i<n;++i)
            {
                for(int j=0;j<n;++j)
                {
                    dist[i][j]=min(dist[i][k]+dist[k][j],dist[i][j]);
                }
            }
        }
        for(int i=0;i<L;++i)
        {
            scanf("%d%d",&nd[i].id,&nd[i].t);
        }
        init(2*L+2,2*L,2*L+1);
        for(int i=0;i<L;++i)
        {
            add_edge(src,i,1);
            add_edge(i+L,dest,1);
        }
        for(int i=0;i<L;++i)
        {
            for(int j=0;j<L;++j)
            {
                if(i!=j&&nd[i].t+dist[ nd[j].id ][ nd[i].id ] <= nd[j].t )
                {
                    add_edge(i,j+L,1);
                }
            }
        }
        int res = sap();
        printf("%d\n",L-res);

    }
	return 0;
}
