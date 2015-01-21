#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#define X first
#define Y second
#define sqr(x) ((x)*(x))
using namespace std;
const double eps = 1e-8 ;

typedef long long LL ;

const int N = 10005;
const int M = 2*100005;
int dirto[M],head[N],next[M],nedge,wt[M];
int k;
void init()
{
    nedge=0;
    memset(head,-1,sizeof(head));
}
void add_edge(int u,int v,int w)
{
    dirto[nedge]=v;
    next[nedge]=head[u];
    wt[nedge]=w;
    head[u]=nedge++;
}
int src[1005],dis[N],vis[N];
void spfa()
{
    for(int i=1;i<N;++i)dis[i]=1e9;
    memset(vis,false,sizeof(vis));

    queue<int> Q;
    for(int i=0;i<k;++i)
    {
        Q.push(src[i]);
        dis[ src[i] ] = 0;
        vis[ src[i] ] = true;
    }
    while(!Q.empty())
    {
        int u = Q.front(),v;
        Q.pop();
        vis[u]=false;
        int d = dis[u];
        for(int e=head[u];~e;e=next[e])
        {
            v = dirto[e];
            if(d + wt[e] < dis[v] )
            {
                dis[v] = d + wt[e];
                if(!vis[v])
                {
                    Q.push(v);
                    vis[v]=true;
                }
            }
        }
    }
}

int main(int argc, char const *argv[])
{
	int T;
	int n,m;
	freopen("Ein.txt","r",stdin);
	scanf("%d",&T);

	while(T--)
	{
	    scanf("%d%d",&n,&m);
	    init();
	    for(int i=0;i<m;++i)
	    {
	        int u,v,w;
	        scanf("%d%d%d",&u,&v,&w);
	        add_edge(u,v,w);
	        add_edge(v,u,w);
	    }
	    scanf("%d",&k);
	    for(int i=0;i<k;++i)
	    {
	        scanf("%d",src+i);
	    }
	    spfa();
	    int q;
	    scanf("%d",&q);
	    while(q--)
	    {
	        int u;
	        scanf("%d",&u);
	        printf("%d\n",(dis[u]==1e9)?-1:dis[u]);
	    }
	    puts("");
	}
	return 0;
}
