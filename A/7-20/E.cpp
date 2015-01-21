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

int n,m,s,t;
const int inf=1e7;
struct Edge
{
    int v;
    int pre;
    int be;
}E[404*404];

int head[404],cnt;
void add_edge(int u,int v)
{
    E[cnt].v=v;
    E[cnt].pre=head[u];
    E[cnt].be=inf;
    head[u]=cnt++;

}
int dis[404];
vector<int> crt[404];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(E,0,sizeof(E));
        memset(head,-1,sizeof(head));
        cnt=0;
        for(int i=1;i<404;++i)crt[i].clear();
        scanf("%d%d%d%d",&n,&m,&s,&t);
        for(int i=1;i<404;++i)dis[i]=inf;
        for(int i=1;i<=m;++i)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            add_edge(u,v);
            add_edge(v,u);
        }
        queue<int> Q;
        while(!Q.empty())Q.pop();
        Q.push(s);
        dis[s]=0;
        bool vis[404];
        memset(vis,false,sizeof(vis));
        while(!Q.empty())
        {
            int u = Q.front();
            vis[u]=true;
            Q.pop();
            for(int e=head[u];~e;e=E[e].pre)
            {
                int v = E[e].v;
                dis[v]=min(dis[v],dis[u]+1);
                if(!vis[v])
                {
                    vis[v]=true;
                    Q.push(v);
                }
            }
        }
        memset(vis,false,sizeof(vis));
        Q.push(s);
        while(!Q.empty())
        {
                        int u = Q.front();
            vis[u]=true;
            Q.pop();
            for(int e=head[u];~e;e=E[e].pre)
            {
                int v = E[e].v;
                if(dis[v]==dis[u]+1)
                {
                    E[e].be=min(E[e].be,dis[v]);
                    E[e].be=min(E[e].be,dis[t]);
                }
                if(!vis[v])
                {
                    vis[v]=true;
                    Q.push(v);
                }
            }

        }
        for(int i=0;i<cnt;i++)
        {
            if(E[i].be!=inf)crt[E[i].be].push_back(i/2+1);
        }
        //puts("ok2");
        printf("%d\n",dis[t]);
        for(int i=1;i<=dis[t];++i)
        {
            int len=crt[i].size();
            printf("%d",len);
            for(int j=0;j<len;++j)
            {
                printf(" %d",crt[i][j]);
            }
            puts("");
        }
        if(T!=0)puts("");
    }
	return 0;
}
