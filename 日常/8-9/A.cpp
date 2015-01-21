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

const int N = 1005;
const int M = 20000006;
struct edge
{
    int u,v,pre;
} E1[M],E2[M];
int head[N],hd[N],nedge,cnt,dfn[N],low[N],instack[N],belong[N];
int n,m,tsp,qlen;
vector<int> qlt[N];
stack<int> S;

void init()
{
    for(int i=0; i<N; ++i)qlt[i].clear();
    memset(hd,-1,sizeof(hd));
    memset(head,-1,sizeof(head));
    memset(dfn,-1,sizeof(dfn));
    memset(instack,0,sizeof(instack));
    nedge=0;
    cnt=0;
    tsp=0;
    qlen=0;
    while(!S.empty())S.pop();
}
void add_edge(int u,int v)
{
    E1[nedge].u=u;
    E1[nedge].v=v;
    E1[nedge].pre=head[u];
    head[u]=nedge++;
}
void add_edge2(int u,int v)
{
    E2[cnt].u=u;
    E2[cnt].v=v;
    E2[cnt].pre=hd[u];
    hd[u]=cnt++;
}
void dfs(int u)
{
    //printf("u=%d\n",u);
    dfn[u]=low[u]=++tsp;
    S.push(u);
    instack[u]=1;
    //puts("ok");
    for(int e=head[u]; ~e; e=E1[e].pre)
    {
        //printf("e=%d\n",e);
        int v = E1[e].v;
        //printf("v=%d\n",v);
        if(dfn[v]==-1)
        {
            dfs(v);
            low[u]=min(low[v],low[u]);
        }
        else if(instack[v])
        {
            low[u]=min(low[u],dfn[v]);
        }
    }
    //printf("u=%d\n",u);
    if(dfn[u]==low[u])
    {
        int p = u;
        while(S.top()!=p)
        {
            qlt[qlen].push_back(S.top());
            belong[S.top()]=qlen;
            instack[S.top()]=0;
            S.pop();
        }
        qlt[qlen].push_back(p);
        belong[p]=qlen++;
        instack[p]=0;
        S.pop();
    }
}
LL dp[N];
int ind[N];
bool vis[N];
LL res;
LL mod = 1000000007LL;
void dfs2(int u)
{
    bool dfsed=false;
    dp[u]=1;
    for(int e=hd[u]; ~e; e=E2[e].pre)
    {
        int v = E2[e].v;
        dfs2(v);
        dp[u]*=dp[v];
        dp[u]%=mod;
        dfsed=true;
    }
    ++dp[u];
}
void gao()
{
    memset(vis,0,sizeof(vis));
    memset(dp,0,sizeof(dp));
    memset(ind,0,sizeof(ind));
    for(int i=0; i<nedge; ++i)
    {
        if(belong[ E1[i].u ]!=belong[ E1[i].v ])
        {
            ind[ belong[ E1[i].u ] ]++;
            add_edge2(belong[ E1[i].v ],belong[ E1[i].u ]);
        }
    }
    res=1;
    for(int i=0; i<qlen; ++i)
    {
        if(ind[i]==0)
        {
            dfs2(i);
            res *= dp[i];
            res %= mod;
        }
    }
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        init();
        for(int i=0; i<m; ++i)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            add_edge(u,v);
        }
        for(int i=1; i<=n; ++i)if(dfn[i]==-1)dfs(i);
        gao();
        //for(int i=0; i<qlen; ++i)printf("%d: %lld %lld\n",i,dp[i][0],dp[i][1]);

        printf("%lld\n",res);
    }
    return 0;
}
