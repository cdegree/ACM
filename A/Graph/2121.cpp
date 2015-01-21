#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#define X first
#define Y second
#define sqr(x) ((x)*(x))
using namespace std;
const double eps = 1e-8 ;


typedef long long LL ;
const int N = 50005;
const int E = 1000005;
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



int main(int argc, char const *argv[])
{
	int n,m;
	//freopen("2121in.txt","r",stdin);
	scanf("%d%d",&m,&n);
	init(n+2,0,n+1);
	for(int i=1;i<=m;++i)
	{
		add_edge(src,i,1);
	}
	for(int i=m+1;i<=n;++i)
	{
		add_edge(i,dest,1);
	}
	while(true)
	{
		int u,v;
		scanf("%d %d",&u,&v);
		if(u==-1&&v==-1)break;
		add_edge(u,v,1);
	}
	int ans = sap();
	if(ans>0)
	{
		printf("%d\n",ans);
		for(int i=1;i<=m;++i)
		{
			bool found=false;
			int ed;
			for(int e = head[i];~e;e=edge[e].next)
			{
				int v = edge[e].en;
				if(edge[e].flow>0)
				{
					ed=v;
					found=true;
					break;
				}
			}
			if(!found)continue;
			printf("%d %d\n",i,ed);
		}
	}
	else
	{
		puts("No Solution!");
	}
	return 0;
}
