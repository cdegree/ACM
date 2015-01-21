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
#include <stdlib.h>
#include <stdio.h>

using namespace std;

typedef long long LL ;

const int N = 50002;
const int M = N*2;
const int mod = 321555123;

int n,m;

int dirto[M],next[M],head[N],cost[M],nedge;

const int K = 105;
int cnt[N][K],cnt_down[N][K];

void add_edge(int u,int v,int c)
{
	dirto[nedge]=v;
	cost[nedge]=c;
	next[nedge]=head[u];
	head[u]=nedge++;
}

void init()
{
	nedge=0;
	memset(head,-1,sizeof(head));
	memset(cnt,0,sizeof(cnt));
	memset(cnt_down,0,sizeof(cnt_down));
	for(int i=0;i<N;++i)
	{
		cnt_down[i][0]=1;
	}
}

void dfs1(int u,int pre)
{
	for(int e=head[u];~e;e=next[e])
	{
		int v = dirto[e];
		if(v==pre)continue;
		int c = cost[e];
		dfs1(v,u);
		for(int j=c;j<K;++j)
		{
			cnt_down[u][j] += cnt_down[v][j-c];
			cnt_down[u][j] %= mod;
		}
	}
}
int tmp[K];
void dfs2(int u,int pre)
{
	for(int e=head[u];~e;e=next[e])
	{
		int v = dirto[e];
		if(v==pre)continue;
		int c = cost[e];
		for(int j=0;j<K;++j)
		{
			tmp[j] = cnt[u][j];
		}
		for(int j=c;j<K;++j)
		{
			tmp[j] -= cnt_down[v][j-c];
		}
		for(int j=c;j<K;++j)
		{
			cnt[v][j] = tmp[j-c];
		}

		for(int j=0;j<K;++j)
		{
			cnt[v][j] += cnt_down[v][j];
			cnt[v][j] %= mod;
		}
		
		dfs2(v,u);
	}
}


int main(int argc, char const *argv[])
{
	freopen("Ein.txt","r",stdin);

	while(~scanf("%d%d",&n,&m))
	{
		init();
		for(int i=1;i<n;++i)
		{
			int u,v,c;
			scanf("%d%d%d",&u,&v,&c);
			add_edge(u,v,c);
			add_edge(v,u,c);
		}

		//puts("OK1");
		dfs1(1,1);
		for(int i=0;i<K;++i)
		{
			cnt[1][i] = cnt_down[1][i];
		}

		dfs2(1,1);

		int res = 0 ;
		for(int i=1;i<=n;++i)
		{
			res += cnt[i][m];
			res %= mod;
		}
		printf("%d\n",res/2);
	}
	return 0;
}
