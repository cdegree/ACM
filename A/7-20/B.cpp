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

const int N = 808;
const int E = 650005;
const int inf = 1e8;

struct Edge
{
    int en,cap,flow,next;
}edge[E];
int head[N], now[N];
int src,dest,node,nedge;
int pre[N],dis[N],gap[N];

void add_edge(int st,int en,int cap)
{
    edge[nedge].en=en;
    edge[nedge].cap=cap;
    edge[nedge].flow=0;
    edge[nedge].next=head[st];
    head[st]=nedge++;
}
/*
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
    for(int i=0;i<node;++i)now[i]=head[i];
    gap[0]=node;
    int point=src,flow=0,min_flow=inf;
    while(dis[src]<node)
    {
        bool fg=false;
        for(int i=now[point];~i;i=edge[i].next)
        {
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
        }
        if(fg)continue;
        if(--gap[dis[point]]==0 )break;
        int Min=node;
        for(int i=head[point];~i;i=edge[i].next)
        {
            if(edge[i].cap-edge[i].flow>0 && Min>dis[edge[i].en])
            {
                Min=dis[edge[i].en];
                now[point]=i;
            }
        }
        gap[dis[point]=Min+1]++;
        if(point!=src)point=pre[point];
    }
    return flow;
}
*/
void init(int _node,int _src,int _dest)
{
    nedge=0;
    node=_node;
    src=_src;
    dest=_dest;
    for(int i=0;i<node;++i)head[i]=-1;
}

int linked[404],used[404],flag[404],marry[404];

bool find(int u)
{
    if(flag[u])
    {
        return false;
    }
    flag[u]=true;
    for(int i=head[u];~i;i=edge[i].next)
    {
        int v = edge[i].en;
        if(!linked[ v ]||find(linked[v]))
        {
            linked[v]=u;
            marry[u]=v;
            return true;
        }
    }
    return false;
}
int n;
int max_match()
{
    int ans=0;
    bool ffind=false;
    memset(linked,false,sizeof(linked));
    memset(used,0,sizeof(used));
    memset(marry,0,sizeof(marry));
    while(1)
    {
        memset(flag,false,sizeof(flag));
        ffind=false;
        for(int i=1;i<=n;++i)
        {
            if(!used[i]&&find(i))
            {
                used[i]=true;
                ++ans;
                ffind=true;
                break;
            }
        }
        if(!ffind)
        {
            return ans;
        }
    }
}

struct Son
{
    int A;
    int marry;
    vector<int> like;
    int id;
}S[402];
int res[402];
bool cmp(Son a,Son b)
{
    return a.A>b.A;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        for(int i=0;i<402;++i)S[i].like.clear();
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
        {
            scanf("%d",&S[i].A);
            S[i].id=i;
            S[i].A=S[i].A*S[i].A;
        }
        init(2*n+3,0,2*n+2);
        for(int i=1;i<=n;++i)
        {
            int k;
            scanf("%d",&k);
            int v;
            while(k--)
            {
                scanf("%d",&v);
                S[i].like.push_back(v);
            }
        }
        sort(S+1,S+n+1,cmp);
        for(int i=1;i<=n;++i)
        {
            for(int j=0;j<S[i].like.size();++j)
            {
                add_edge(i,S[i].like[j],1);
            }
        }
        //puts("ok");
        max_match();
        //puts("ok2");
        for(int i=1;i<=n;++i)
        {
            res[S[i].id]=marry[i];
            //printf("%d:\n",i);
        }
        //puts("ok3");
        for(int i=1;i<=n;++i)
        {
            printf("%d%c",res[i],i==n?'\n':' ');
        }
        if(T!=0)puts("");
    }
	return 0;
}
