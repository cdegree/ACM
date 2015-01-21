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

const int N = 105,M=55;
const int inf = 2e9+7;
int dp[N][M][N];
int dirto[N*2],next[N*2],cost[N*2],head[N*2],nedge,pre[N];
int produce[N];
int n,m;
void init()
{
	for(int i=0;i<N;++i)
	{
		for(int j=0;j<M;++j)
		{
			for(int k=0;k<N;++k)
			{
				dp[i][j][k]=inf;
			}
		}
	}
	nedge=0;
	memset(head,-1,sizeof(head));
}
void add_edge(int u,int v,int c)
{
	dirto[nedge]=v;
	cost[nedge]=c;
	next[nedge]=head[u];
	head[u]=nedge++;
}



int main(int argc, char const *argv[])
{
	while(~scanf("%d%d",&n,&m))
	{
		init();
		for(int i=1;i<=n;++i)
		{
			int w,v,d;
			scanf("%d%d%d",&w,&v,&d);
			add_edge(v,i,d);
			produce[i]=w;
			pre[i]=v;
		}
		
	}
	return 0;
}