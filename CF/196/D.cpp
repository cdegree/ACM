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

const int N = 100005;
struct edge
{
    int u,v,pre;
}E[2*N];
int head[N],cnt;

void add_edge(int u,int v)
{
    E[cnt].u=u;
    E[cnt].v=v;
    E[cnt].pre=head[u];
    head[u]=cnt++;
}
int dis[N];
bool heard[N];
void dfs1(int u,int pre)
{
    dis[u]=0;
    for(int e=head[u];~e;e=E[e].pre)
    {
        int v = E[e].v;
        if(v!=pre)
        {
            if(heard[v])dis[u]=max(dis[u],1);
            dfs1(v,u);
            if(dis[v]>0)dis[u]=max(dis[u],dis[v]+1);
        }
    }
}
int res;
int n,m,k;
void dfs2(int u,int pre,int famx)
{
    printf("u=%d,pre=%d,famx=%d\n",u,pre,famx);
    if(max(dis[u],famx)<=k)
    {
        ++res;
        printf("add\n");
    }
    int mx1=0,mx2=0;
    for(int e=head[u];~e;e=E[e].pre)
    {
        int v = E[e].v;
        if(v==pre)continue;
        if(dis[v]>mx1)
        {
            mx2=mx1;
            mx1=dis[v];
        }
        else if(dis[v]>mx2)mx2=dis[v];
    }
    printf("%d %d\n",mx1,mx2);
    for(int e=head[u];~e;e=E[e].pre)
    {
        int v = E[e].v;
        if(v==pre)continue;
        int omx=0;
        if(dis[v]<mx1)
        {
            omx=mx1;
        }
        else if(dis[v]==mx1)omx=mx2;
        int q=0;
        if(heard[u])q=1;
        if(omx>0&&famx==0)dfs2(v,u,max(q,omx+2));
        else if(omx==0&&famx==0)dfs2(v,u,max(q,0));
        else if(famx>0&&omx==0)dfs2(v,u,max(q,famx+1));
        else dfs2(v,u,max(q,max(famx+1,omx+2)));
    }
}
int main()
{
    while(cin>>n>>m>>k)
    {
        memset(head,-1,sizeof(head));
        memset(heard,0,sizeof(heard));
        cnt=0;
        int u,v;
        for(int i=0;i<m;++i)
        {
            scanf("%d",&u);
            heard[u]=1;
        }
        for(int i=1;i<n;++i)
        {
            scanf("%d%d",&u,&v);
            add_edge(u,v);
            add_edge(v,u);
        }
        res=0;
        dfs1(1,1);
        for(int i=1;i<=n;++i)printf("dis[%d]=%d\n",i,dis[i]);

        dfs2(1,1,0);
        cout<<res<<endl;
    }
	return 0;
}
