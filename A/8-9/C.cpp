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
const int N = 10005;
const int M = 20000006;
struct edge
{
    int u,v,pre;
    double w;
} E1[M];
int head[N],hd[N],nedge,cnt,dfn[N],low[N],instack[N],belong[N];
int n,m,tsp,qlen;
vector<int> qlt[N];
stack<int> S;
vector<edge> QE[N];
void init()
{
    for(int i=0; i<N; ++i)qlt[i].clear();
    for(int i=0;i<N;++i)QE[i].clear();
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
void add_edge(int u,int v,double w)
{
    E1[nedge].u=u;
    E1[nedge].w=w;
    E1[nedge].v=v;
    E1[nedge].pre=head[u];
    head[u]=nedge++;
}
void dfs(int u,int pre)
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
        if(v==pre)continue;
        //printf("v=%d\n",v);
        if(dfn[v]==-1)
        {
            dfs(v,u);
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
struct point
{
    double x,y;
}P[N];
double qsum[N];
int Set[N];
int Find_Set(int x)
{
    if(x==Set[x])return x;
    return Set[x]=Find_Set(Set[x]);
}
void Union_Set(int x,int y)
{
    Set[Find_Set(x)]=Find_Set(y);
}
bool cmp(edge a,edge b)
{
    return a.w>b.w;
}
double res;
void gao()
{
    memset(qsum,0,sizeof(qsum));
    for(int i=0;i<N;++i)Set[i]=i;
    for(int i=0; i<nedge; ++i)
    {
        if(belong[ E1[i].u ]==belong[ E1[i].v ])
        {
            qsum[ belong[ E1[i].u ] ] +=  E1[i].w;
            QE[ belong[ E1[i].u ] ].push_back( E1[i] );
            ++i;
            //printf("%d - %d\n",E1[i].u,E1[i].v);
        }
    }
//    for(int i=1;i<=n;++i)
//    {
//        printf("belong[%d]=%d\n",i,belong[i]);
//    }
    res = 0 ;
//    for(int i=0;i<qlen;++i)
//    {
//        printf("%d: ");
//        for(int j=0;j<qlt[i].size();++j)
//        {
//            printf("%d ",qlt[i][j]);
//        }
//        puts("");
//    }

    for(int i=0;i<qlen;++i)
    {
        int len = QE[i].size();
        //printf("%d:%d\n",i,len);
        sort(QE[i].begin(),QE[i].end(),cmp);
        for(int j=0;j<len;++j)
        {
            int x = QE[i][j].u ;
            int y = QE[i][j].v;
            double w = QE[i][j].w;
            if(Find_Set(x)==Find_Set(y))
            {
                //printf("cut %d %d\n",x,y);
                res += w;
            }
            else
            {
                //rintf("connected %d %d\n",x,y);
                Union_Set(x,y);
            }
        }
    }
}
double get_dis(point a,point b)
{
    return sqrt( sqr(a.x-b.x) + sqr(a.y-b.y) );
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        init();
        for(int i=1;i<=n;++i)
        {
            scanf("%lf %lf",&P[i].x,&P[i].y);
        }
        for(int i=0;i<m;++i)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            double w = get_dis(P[u],P[v]);
            add_edge(u,v,w);
            add_edge(v,u,w);
        }
        for(int i=1;i<=n;++i)if(dfn[i]==-1)dfs(i,i);
        gao();
        printf("%.3f\n",res);
    }
	return 0;
}
