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

const int N = 55;
const int K = 8;
int dp[1<<K][1<<K][N];
bool inqueue[1<<K][1<<K][N];

int T,n,m,k;

struct edge
{
    int u,v,w,pre;
} E[N*N];

int BT[N],FT[N];
int head[N],cnt;
void add_edge(int u,int v,int w)
{
    E[cnt].u=u;
    E[cnt].v=v;
    E[cnt].w=w;
    E[cnt].pre=head[u];
    head[u]=cnt++;
}
int ticket[N],attraction[N];
int ccost[1<<K][1<<K];
const int inf=1e8;
void init()
{
    memset(head,-1,sizeof(head));
    for(int i=0; i<(1<<K); ++i)for(int j=0; j<(1<<K); ++j)for(int k=0; k<N; ++k)dp[i][j][k]=inf;
    memset(ticket,0,sizeof(ticket));
    memset(attraction,0,sizeof(attraction));
    memset(inqueue,0,sizeof(inqueue));
    cnt=0;
}
inline bool test_bit(int mask,int pos)
{
    return ((1<<pos)&mask)!=0;
}
inline bool all(int mask)
{
    return mask==((1<<k)-1);
}

bool mp[55][55];
int W[55][55];

void dfs(int u,int Imask,int Jmask)
{
    //printf("u=%d, Imask = %d, Jmask = %d\n",u,Imask,Jmask);
    //for(int e=head[u]; ~e; e=E[e].pre)
    for(int i=1; i<=n; ++i)
    {
        if(!mp[u][i])continue;
        int v = i;
        int w = W[u][i];
        int NewImask = Imask;
        int NewJmask = Jmask;
        int cost = w;
        NewJmask |= ticket[v];
        NewImask |= attraction[v];
        cost += ccost[ NewJmask ][ attraction[v] ];
        NewJmask |= NewImask;
        //printf("v = %d NewImask = %d NewJmask = %d\n",v,NewImask,NewJmask);
        //printf("%d cmpto %d\n",dp[Imask][Jmask][u],dp[NewImask][NewJmask][v]);
        if(dp[NewImask][NewJmask][v] > dp[Imask][Jmask][u] + cost)
        {
            dp[NewImask][NewJmask][v] = dp[Imask][Jmask][u] + cost;
            dfs(v,NewImask,NewJmask);
        }
        if(dp[Imask][NewJmask][v] > dp[Imask][Jmask][u] + w )
        {
            dp[Imask][NewJmask][v] = dp[Imask][Jmask][u] + w;
            dfs(v,Imask,NewJmask);
        }
    }
}


int main()
{
    scanf("%d",&T);
    for(int t=1; t<=T; ++t)
    {
        scanf("%d%d%d",&n,&m,&k);
        int u,v,w;
        init();
        memset(mp,0,sizeof(mp));
        memset(W,66,sizeof(W));
        for(int i=0; i<m; ++i)
        {
            scanf("%d%d%d",&u,&v,&w);
            //add_edge(u,v,w);
            mp[u][v]=1,mp[v][u]=1;
            W[u][v]=W[v][u]=min(W[u][v],w);
            //add_edge(v,u,w);
        }
        for(int i=0; i<=n; ++i)W[i][i]=0;
        mp[0][1]=mp[1][0]=1,W[1][0]=W[0][1]=0;
        for(int u=0; u<=n; ++u)
        {
            for(int i=0; i<=n; ++i)
            {
                for(int j=0; j<=n; ++j)
                {
                    W[i][j]=min(W[i][k]+W[k][j],W[i][j]);
                }
            }
        }
        int f,fn;
        for(int i=0; i<k; ++i)
        {
            scanf("%d%d%d%d",&f,BT+i,FT+i,&fn);
            int pk = (1<<i);
            attraction[f] |= pk;
            for(int j=0; j<fn; ++j)
            {
                int fi;
                scanf("%d",&fi);
                ticket[fi] |= pk;
            }
        }
        for(int i=0; i<(1<<k); ++i)
        {
            for(int j=0; j<(1<<k); ++j)
            {
                ccost[i][j]=0;
                for(int p=0; p<k; ++p)
                {
                    if(test_bit(j,p))
                    {
                        if(test_bit(i,p))
                        {
                            ccost[i][j]+=FT[p];
                        }
                        else
                        {
                            ccost[i][j]+=BT[p];
                        }
                    }
                }
            }
        }
        printf("Case #%d: ",t);
        int mask = (1<<k);
        dp[0][0][0]=0;

        for(int Imask=0; 0&&Imask<mask; ++Imask)
        {
            for(int Jmask=0; Jmask<mask; ++Jmask)
            {
                if((Imask&Jmask)==Imask)
                {
                    for(int u=0; u<=n; ++u)
                    {
                        if(dp[Imask][Jmask][u]<inf)
                        {
                            for(int v=1; v<=n; ++v)
                            {
                                if(ticket[v]||attraction[v])
                                {
                                    int w = W[u][v];
                                    int NewImask = Imask;
                                    int NewJmask = Jmask;
                                    int cost = w;
                                    NewImask |= attraction[v];
                                    NewJmask |= ticket[v];
                                    cost += ccost[ NewJmask ][ attraction[v] ];
                                    printf("v = %d NewImask = %d NewJmask = %d\n",v,NewImask,NewJmask);
                                    printf("%d cmpto %d\n",dp[Imask][Jmask][u],dp[NewImask][NewJmask][v]);
                                    if(dp[NewImask][NewJmask][v] > dp[Imask][Jmask][u] + cost)
                                    {
                                        dp[NewImask][NewJmask][v] = dp[Imask][Jmask][u] + cost;
                                    }
                                    if(dp[Imask][NewJmask][v] > dp[Imask][Jmask][u] + cost )
                                    {
                                        dp[Imask][NewJmask][v] = dp[Imask][Jmask][u] + w;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        queue<int> Q;
        Q.push(0);
        Q.push(0);
        Q.push(0);
        while(!Q.empty())
        {
            int Imask = Q.front();
            Q.pop();
            int Jmask = Q.front();
            Q.pop();
            int u = Q.front();
            Q.pop();
            for(int v=1; v<=n; ++v)
            {
                if(v==u)continue;
                if(ticket[v]||attraction[v]||v==1)
                {
                    int NewImask = Imask;
                    int NewJmask = Jmask;
                    int cost = W[u][v];
                    NewImask |= attraction[v];
                    NewJmask |= ticket[v];
                    cost += ccost[ NewJmask ][ attraction[v] ];
                    if(dp[NewImask][NewJmask][v] > dp[Imask][Jmask][u] + cost)
                    {
                        dp[NewImask][NewJmask][v] = dp[Imask][Jmask][u] + cost;
                    }
                    if(dp[Imask][NewJmask][v] > dp[Imask][Jmask][u] + W[u][v] )
                    {
                        dp[Imask][NewJmask][v] = dp[Imask][Jmask][u] + W[u][v];
                    }
                    if(!inqueue[NewImask][NewJmask][v])
                    {
                        inqueue[NewImask][NewJmask][v]=1;
                        Q.push(NewImask);Q.push(NewJmask);Q.push(v);
                    }
                    if(!inqueue[Imask][NewJmask][v])
                    {
                        inqueue[Imask][NewJmask][v]=1;
                        Q.push(Imask);Q.push(NewJmask);Q.push(v);
                    }
                }
            }
        }




        //dfs(0,0,0);
        int res = 1e8;
        for(int i=0; i<(1<<k); ++i)
        {
            res = min(res,dp[(1<<k)-1][i][1]);
        }
        printf("%d\n",res);
    }
    return 0;
}
