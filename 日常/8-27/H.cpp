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
const int N=1005;
int dis[N][N];
const int inf=10005;
map<string,int> mp;
bool vis[N];
int d[N];
struct edge
{
    int u,v,pre;
} E[N*20];
int cnt,head[N];
void add_edge(int u,int v)
{
    E[cnt].u=u;
    E[cnt].v=v;
    E[cnt].pre=head[u];
    head[u]=cnt++;
}
void spfa(int x)
{
    memset(vis,false,sizeof(vis));
    queue<int> Q;
    Q.push(x);
    while(!Q.empty())
    {
        int u = Q.front();
        vis[u]=0;
        Q.pop();
        for(int e=head[u]; ~e; e=E[e].pre)
        {
            int v = E[e].v;
            if(dis[x][v]>dis[x][u]+1)
            {
                dis[x][v]=dis[x][u]+1;
                if(!vis[v])
                {
                    vis[v]=1;
                    Q.push(v);
                }
            }
        }
    }
}
int du[N];
int c[N][N];
int main()
{
    int n;
    while(1)
    {
        scanf("%d",&n);
        if(n==0)break;
        mp.clear();
        for(int i=0; i<n; ++i)for(int j=0; j<n; ++j)dis[i][j]=inf;
        string s;
        char c[12];
        for(int i=0; i<n; ++i)
        {
            scanf("%s",c);
            s=c;
            mp[s]=i;
        }
        memset(du,0,sizeof(du));
        int m;
        scanf("%d",&m);
        char c1[12],c2[12];
        string s1,s2;
        for(int i=0; i<n; ++i)dis[i][i]=0;
        memset(head,-1,sizeof(head));
        cnt=0;
        while(m--)
        {
            scanf("%s%s",c1,c2);
            s1=c1,s2=c2;
            int u = mp[s1];
            int v = mp[s2];
            add_edge(u,v);
            add_edge(v,u);
        }
        spfa(0);
        int mx=-1;
        for(int i=1;i<n;++i)
        {
            mx=max(mx,dis[0][i]);
        }
        if(mx>7)
        {
            puts("-1");
            continue;
        }
        for(int i=1;i<n;++i)
        {
            spfa(i);
        }
        mx=0;
        for(int i=0;i<n;++i)
        {
            for(int j=i+1;j<n;++j)
            {
                if(dis[i][j]>mx)mx=dis[i][j];
            }
        }
        if(mx>7&&mx!=inf)while(1);
        printf("%d\n",mx==inf?-1:mx);
    }
    return 0;
}
