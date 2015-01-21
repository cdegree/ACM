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

const int N = 200005;
struct edge
{
    int u,v,pre;
}E[N];
int head[N],cnt;
void add_edge(int u,int v)
{
    E[cnt].u=u;
    E[cnt].v=v;
    E[cnt].pre=head[u];
    head[u]=cnt++;
}


LL ccnt[N];

void dfs1(int u,int pre)
{
    ++ccnt[u];
    for(int e=head[u];~e;e=E[e].pre)
    {
        int v = E[e].v;
        if(v!=pre)
        {
            dfs1(v,u);
            ccnt[u]+=ccnt[v];
        }
    }
}
LL res;
int n;
void dfs2(int u,int pre)
{
    res += (ccnt[u]-1)*(LL)(n-ccnt[u]);
    LL sum = ccnt[u]-1;
    LL z=0;
    for(int e=head[u];~e;e=E[e].pre)
    {
        int v = E[e].v;
        if(v!=pre)
        {
            dfs2(v,u);
            z += ccnt[v]*(sum-ccnt[v]);
        }
    }
    res += z/2;
}
int main()
{
    while(~scanf("%d",&n))
    {
        memset(head,-1,sizeof(head));
        memset(ccnt,0,sizeof(ccnt));
        cnt=0;
        res=0;
        for(int i=1;i<n;++i)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            add_edge(u,v);
            add_edge(v,u);
        }
        res=0;
        dfs1(1,1);
        dfs2(1,1);
        res = (LL)n*(n-1)*(n-2)/6 - res;
        printf("%I64d\n",res);
    }
	return 0;
}
