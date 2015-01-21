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
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;

typedef long long LL ;

const int N = 100005;
const int M = 1000005;

int point[N],head[N],vis[N];
int nedge,cost[M*2],next[M*2];
void add_edge(int u,int v,int c)
{
    point[nedge]=v;cost[nedge]=c;next[nedge]=head[u];head[u]=nedge++;
}
int n,m;

bool OK;

void dfs(int u,int pre)
{
    if(OK)return ;
    vis[u]=true;
    int v;
    for(int e=head[u];~e;e=next[e])
    {
        v = point[e];
        if(v!=pre)
        {
            if(vis[v])
            {
                OK=true;
                return ;
            }
            dfs(v,u);
            if(OK)return ;
        }
    }
}

bool circle()
{
    memset(vis,0,sizeof(vis));
    OK=false;
    for(int i=1;i<=n;++i)
    {
        if(!vis[i])
        {
            dfs(i,i);
            if(OK)return OK;
        }
    }
    return false;
}
int res;
int dfs2(int u)
{
    vis[u]=true;
    int mx=0,mx2=0,v,c;
    for(int e=head[u];~e;e=next[e])
    {
        v = point[e] ;
        if(!vis[v])
        {
            c = dfs2(v) + cost[e];
            if(c>mx)
            {
                mx2=mx;
                mx=c;
            }
            else if(c>mx2)
            {
                mx2=c;
            }
        }
    }
    res = res>(mx+mx2)?res:(mx+mx2);
    return mx;
}
void straight()
{
    memset(vis,false,sizeof(vis));
    for(int i=1;i<=n;++i)
    {
        if(!vis[i])
        {
            dfs2(i);
        }
    }
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        int u,v,c;
        memset(head,-1,sizeof(head));

        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&u,&v,&c);
            add_edge(u,v,c);
        }
        if(circle())
        {
            puts("YES");
        }
        else
        {
            res=0;
            straight();
            printf("%d\n",res);
        }

    }
	return 0;
}
