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
LL dis[N][2];

struct edge
{
    int u,v,pre,w;
    int tp;
}E[N*4];
int head[N],cnt;
void add_edge(int u,int v,int tp,int w)
{
    E[cnt].u=u;
    E[cnt].v=v;
    E[cnt].w=w;
    E[cnt].tp=tp;
    E[cnt].pre=head[u];
    head[u]=cnt++;
}
bool vis[N];
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        const LL inf=1000000000000LL;
        for(int i=0;i<N;++i)dis[i][0]=dis[i][1]=inf;
        int u,v,w,tp;
        char s[22];
        dis[1][0]=0;
        memset(head,-1,sizeof(head));
        cnt=0;
        for(int i=0;i<m;++i)
        {
            scanf("%d%d%d%s",&u,&v,&w,s);
            if(s[0]=='L')
            {
                add_edge(u,v,0,w);
            }
            else if(s[0]=='P')
            {
                add_edge(u,v,1,w);
            }
            else
            {
                add_edge(u,v,2,w);
            }
        }
        for(int i=1;i<=n;++i)
        {
            for(int j=head[i];~j;j=E[j].pre)
            {
                int v = E[j].v;
                int tp=E[j].tp;
                if(tp==0)
                {
                    if(dis[i][0]<inf)
                    {
                        dis[v][0]=min(dis[v][0],dis[i][0]+E[j].w);
                    }
                }
                else if(tp==1)
                {
                    if(dis[i][0]<inf)
                    {
                        dis[v][1]=min(dis[v][1],dis[i][0]+E[j].w);
                    }
                    if(dis[i][1]<inf)
                    {
                        dis[v][1]=min(dis[v][1],dis[i][1]+E[j].w);
                    }
                }
                else
                {
                    if(dis[i][0]<inf)
                    {
                        dis[v][0]=min(dis[v][0],dis[i][0]+E[j].w);
                    }
                    if(dis[i][1]<inf)
                    {
                        dis[v][1]=min(dis[v][1],dis[i][1]+E[j].w);
                    }
                }
            }
        }
        if(dis[n][0]<inf||dis[n][1]<inf)
        {
            puts("Online");
            printf("%I64d\n",min(dis[n][1],dis[n][0]));
        }
        else
        {
            puts("Offline");
        }
    }
	return 0;
}
