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

const int N = 2005;
struct Hori
{
    int x0,x1,y;
    bool removed;
} H[N];

struct Vert
{
    int x,y0,y1;
    bool removed;
} V[N];
bool overlap(Hori a,Vert b)
{
    if(a.y==b.y0)
    {
        if(a.x0==b.x||a.x1==b.x)return true;
        else return false;
    }
    else if(a.y==b.y1)
    {
        if(a.x0==b.x||a.x1==b.x)return true;
        else return false;
    }
    else
    {
        return false;
    }
}
int n,m;
int res=0;
void pf()
{
    res=0;
    for(int i=0; i<n; ++i)
    {
        if(!H[i].removed)++res;
        else
        {
            //printf("re h%d %d\n",H[i].x0,H[i].y);
        }
    }
    for(int i=0; i<m; ++i)
    {
        if(!V[i].removed)++res;
        else
        {
            //printf("re v%d %d\n",V[i].x,V[i].y0);
        }
    }
    printf("%d\n",res);
}
struct edge
{
    int u,v,pre;
}E[N*4];
int head[N*2],cnt,len;
void add_edge(int u,int v)
{
    E[cnt].u=u;
    E[cnt].v=v;
    E[cnt].pre=head[u];
    head[u]=cnt++;
}
bool vis[N*2];
int deg[N*2];
void dfs(int u,int pre)
{
    vis[u]=true;
    ++len;
    for(int e=head[u];~e;e=E[e].pre)
    {
        int v = E[e].v;
        if(!vis[v])
        {
            dfs(v,u);
        }
    }
}
int main()
{
    while(true)
    {
        scanf("%d %d",&n,&m);
        if(n==0&&m==0)break;
        memset(vis,0,sizeof(vis));
        memset(deg,0,sizeof(deg));
        memset(head,-1,sizeof(head));
        cnt=0;
        for(int i=0; i<n; ++i)
        {
            scanf("%d %d",&H[i].x0,&H[i].y);
            H[i].x1=H[i].x0+1;
            H[i].removed=false;
        }
        for(int i=0; i<m; ++i)
        {
            scanf("%d %d",&V[i].x,&V[i].y0);
            V[i].y1=V[i].y0+1;
            V[i].removed=false;
        }
        //pf();
        for(int i=0; i<n; ++i)
        {
            int cnt=0;
            for(int j=0; j<m; ++j)
            {
                if(overlap(H[i],V[j]))
                {
                    //printf("%d -> %d\n",i,j);
                    add_edge(i,n+j);
                    add_edge(j+n,i);
                }
            }
        }
        res=0;
        for(int i=0;i<n+m;++i)
        {
            if(!vis[i])
            {
                len=0;
                dfs(i,i);
                //printf("len = %d\n",len);
                res += len/2;
            }
        }
        printf("%d\n",n+m-res);
    }
    return 0;
}
