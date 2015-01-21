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
#pragma comment(linker, "/STACK:102400000,102400000")

const int N = 200002;
const int M = 2000003*2;
struct edge
{
    int v,pre;
} E[M];
int head[N],cnt;
int belong[N],qcnt,t_stamp,low[N],dfn[N];
bool vis[N],instack[N];
stack<int> SK;
vector<int> QLT[N];
int cnt_brigde;
int mxlen,top;
void init()
{
    cnt_brigde=0;
    for(int i=0; i<=200000; ++i)
    {
        QLT[i].clear();
    }
    mxlen=0;
    cnt=0;
    qcnt=0;
    t_stamp=0;
    top=0;
    while(!SK.empty())SK.pop();
    memset(dfn,-1,sizeof(dfn));
    memset(head,-1,sizeof(head));
    memset(instack,0,sizeof(instack));
    memset(vis,false,sizeof(vis));
}
void add_edge(int u,int v)
{
    E[cnt].v=v;
    E[cnt].pre=head[u];
    head[u]=cnt++;
}
int n,m;
int stk[N*2];
void dfs1(int u,int pre)
{
    //printf("%d   %d\n",u,pre);
    low[u]=dfn[u]=++t_stamp;
    stk[++top]=u;
    instack[u]=true;
    int v,cntpre=0;
    for(int e=head[u]; ~e; e=E[e].pre)
    {
        v = E[e].v;
        if(v==pre&&cntpre==0)
        {
            ++cntpre;
            continue;
        }
        //printf("to %d\n",v);
        if(dfn[v]==-1)
        {
            dfs1(v,u);
            low[u]=min(low[u],low[v]);
            if(dfn[u]<low[v])
            {
                ++cnt_brigde;
            }
        }
        else if(instack[v]&&low[u]>dfn[v])
        {
            low[u]=dfn[v];
        }
    }
    //puts("hered");
    if(low[u]==dfn[u])
    {
        while(stk[top]!=u)
        {
            v = stk[top--];
            belong[v]=qcnt;
            QLT[qcnt].push_back(v);
        }
        QLT[qcnt].push_back(u);
        belong[u]=qcnt++;
        --top;
    }
}

int mxdep,dpstp;
int dp[N][2];
void dfs2(int u,int pre)
{
    dp[u][1]=dp[u][0]=0;
    vis[u]=true;
    int v;
    //printf("qlt %d:\n",u);
    for(int i=0; i<QLT[u].size(); ++i)
    {
        for(int e=head[QLT[u][i]]; ~e; e=E[e].pre)
        {
            //printf("v = %d\n",v);
            v = belong[E[e].v];
            if(!vis[v]&&v!=pre&&v!=u)
            {
                dfs2(v,u);
                int vmx = dp[v][0]+1;
                if(dp[u][0]<vmx)
                {
                    dp[u][1]=dp[u][0];
                    dp[u][0]=vmx;
                }
                else if(dp[u][1]<vmx)
                {
                    dp[u][1]=vmx;
                }
            }
        }
    }
    mxlen = max(mxlen,dp[u][0]+dp[u][1]);
}
int main()
{
    while(true)
    {
        scanf("%d%d",&n,&m);
        if(n==0&&m==0)break;
        init();
        int u,v;
        for(int i=0; i<m; ++i)
        {
            scanf("%d%d",&u,&v);
            add_edge(u,v);
            add_edge(v,u);
        }
        dfs1(1,1);
        dfs2(0,0);
        //printf("  %d %d\n",cnt_brigde,mxlen);
        printf("%d\n",cnt_brigde-mxlen);

    }
    return 0;
}
