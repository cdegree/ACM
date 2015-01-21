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


const int N = 205;
const int E = 10005;
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
int a[N],pos[N];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&a[i]);
        pos[ a[i] ] = i;
    }
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int p,x,y;
        scanf("%d%d%d",&p,&x,&y);
        if(p==2)
        {
            swap(a[x],a[y]);
            swap( pos[ x ], pos[ y ] );
        }
        else
        {
            int cnt=1;
            int pre=-1;
            //printf("%d -> %d\n",pos[x],pos[y]);
            int l=pos[x],r=pos[y];
            if(l>r)swap(l,r);

            init(2*n+2,0,2*n+1);
            for(int i=x;i<=y;++i)
            {
                add_edge(src,i,1);
                add_edge(i+n,dest,1);
            }
            for(int i=1;i<=n;++i)
            {
                for(int j=i+1;j<=n;++j)
                {
                    if(a[i]>=x&&a[i]<=y&&a[j]>=x&&a[j]<=y&&a[i]+1==a[j])
                    {
                        add_edge(i,j+n,1);
                    }
                }
            }
            int ans = sap();
            printf("%d\n",r-l+1-ans);

            /*

            for(int i=1;i<=n;++i)
            {
                for(int j=i+1;j<=n;++j)
                {
                    if(a[i]<a[j])
                    {
                        add_edge(i,j+n,1);
                    }
                }
            }

            */
        }
    }
	return 0;
}
