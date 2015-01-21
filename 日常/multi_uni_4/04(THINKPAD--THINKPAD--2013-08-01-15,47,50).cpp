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

const int N = 100009;
struct edge
{
    int u,v,pre;
}E[N*2];

int head[N],nedge;
int n,m,dfn[N],low[N],tim,instack[N];
stack<int> stk;
int qlen,belong[N];
vector<int> qlt[N];
int ind[N];

void init()
{
    memset(ind,0,sizeof(ind));
    memset(head,-1,sizeof(head));
    nedge=0;
    tim=0;
    qlen=0;
    for(int i=0;i<N;++i)
    {
        qlt[i].clear();
    }
    while(!stk.empty())stk.pop();
    memset(instack,0,sizeof(instack));
    memset(dfn,-1,sizeof(dfn));
}

void add_edge(int u,int v)
{
    E[nedge].u=u;
    E[nedge].v=v;
    E[nedge].pre=head[u];
    head[u]=nedge++;
}




void dfs(int u)
{
    low[u]=dfn[u]=++tim;
    instack[u]=1;
    stk.push(u);
    printf("u = %d\n",u);
    for(int e=head[u];~e;e=E[e].pre)
    {
        int v = E[e].v;
        if(dfn[v]==-1)
        {
            dfs(v);
            low[u]=min(low[u],low[v]);
        }
        else if(instack[v]&&dfn[u]>dfn[v])
        {
            low[u]=min(low[u],dfn[v]);
        }
    }
    if(low[u]==dfn[u])
    {
        while(stk.top()!=u)
        {
            qlt[qlen].push_back(stk.top());
            belong[stk.top()]=qlen;
            instack[stk.top()]=0;
            stk.pop();
        }
        belong[u]=qlen;
        qlt[qlen].push_back(u);
        instack[u]=0;
        qlen++;
        stk.pop();
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;++t)
    {
        scanf("%d %d",&n,&m);
        init();
        int u,v;
        for(int i=0;i<m;++i)
        {
            scanf("%d %d",&u,&v);
            add_edge(u,v);
        }
        printf("Case %d: ",t);
        for(int i=1;i<=n;++i)
        {
            if(dfn[i]==-1)
            {
                dfs(i);
            }
        }
//        for(int i=1;i<=n;++i)
//        {
//            printf("%d:  %d %d\n",i,dfn[i],low[i]);
//        }
        //printf("qcnt = %d\n",qlen);
//        for(int i=0;i<qlen;++i)
//        {
//            printf("%d: ",i);
//            for(int j=0;j<qlt[i].size();++j)
//            {
//                printf("%d ",qlt[i][j]);
//            }
//            puts("");
//        }

        if(qlen==1)
        {
            puts("-1");
        }
        else
        {
            LL sum = n*(n-1);
            for(int i=0;i<m;++i)
            {
                int u = E[i].u;
                int v = E[i].v;
                if(belong[u]!=belong[v])
                {
                    ++ind[ belong[v] ];
                }
            }
            LL cnt=1e8;
            for(int i=0;i<qlen;++i)
            {
                if((ind[i]==0||ind[i]==qlen-1)&&qlt[i].size()<cnt)
                {
                    cnt=qlt[i].size();
                }
            }
            sum = sum - cnt*(n-cnt) - m ;
            printf("%I64d\n",sum);
        }
    }
	return 0;
}
