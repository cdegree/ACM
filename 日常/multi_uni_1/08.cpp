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
int n,m;
const int N = 100005;

struct edge
{
    int u,v,pre;
}E[N*2];
int head[N],cnt;
void add_edge(int u,int v)
{
    E[cnt].u=u;
    E[cnt].v=v;
    E[cnt].pre=head[u];
    head[u]=cnt++;
}
void init()
{
    cnt=0;
    memset(head,-1,sizeof(head));
}
int dp[N][2];
int mx;
void dfs(int u,int pre)
{
    dp[u][0]=dp[u][1]=0;
    for(int e=head[u];~e;e=E[e].pre)
    {
        int v = E[e].v;
        if(pre!=v)
        {
            dfs(v,u);
            int vmx = dp[v][0]+1;
            if(vmx>dp[u][0])
            {
                dp[u][1]=dp[u][0];
                dp[u][0]=vmx;
            }
            else if(vmx>dp[u][1])
            {
                dp[u][1] = vmx;
            }
        }
    }
    mx = max(mx,dp[u][0]+dp[u][1]);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        init();
        for(int i=1;i<n;++i)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            add_edge(u,v);
            add_edge(v,u);
        }
        mx=0;
        dfs(1,1);
        ++mx;
        //printf("len = %d\n",mx);
        for(int i=0;i<m;++i)
        {
            int q;
            scanf("%d",&q);
            if(q<=mx)
            {
                printf("%d\n",q-1);
            }
            else
            {
                int res = q-mx;
                printf("%d\n",res*2+mx-1);
            }
        }
    }
	return 0;
}
