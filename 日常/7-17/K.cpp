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

const int N = 1000005;
const int M = 2*N;
int next[M],head[N],dirto[M],cnt;
bool dead[N];
void init()
{
    cnt=0;
    memset(dead,false,sizeof(dead));
    memset(head,-1,sizeof(head));
}
void add_edge(int u,int v)
{
    dirto[cnt]=v;
    next[cnt]=head[u];
    head[u]=cnt++;
}
int p[N];

void dfs(int pre,int u,int dep)
{
    p[u]=dep;
    int q = dep;
    if(dead[u])++q;
    for(int e=head[u];~e;e=next[e])
    {
        int v = dirto[e];
        if(v!=pre)
        {
            dfs(u,v,q);
        }
    }
}
int main()
{
    int n,T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        init();
        for(int i=1;i<n;++i)
        {
            int u,v;
            scanf("%d %d",&u,&v);
            add_edge(u,v);
            add_edge(v,u);
        }
        int m;
        scanf("%d",&m);
        while(m--)
        {
            int q;
            scanf("%d",&q);
            dead[q]=true;
        }
        dfs(1,1,0);
        double res=0;
        for(int i=1;i<=n;++i)
        {
            //printf("%d:%d\n",i,p[i]);
            res += ( 1.0 - (1.0/(p[i]+1.0)) );
        }
        printf("%.9f\n",res);
    }
	return 0;
}
