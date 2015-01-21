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

const int N = 505;
const int M = 10005;

int Set[2][M][N];

inline int Find_Set(int dir,int nedge,int x)
{
	return (x==Set[dir][nedge][x])?x:(Set[dir][nedge][x]=Find_Set(dir,nedge,Set[dir][nedge][x]));
}
int n,m;
inline void init_Set(int dir,int nedge,int n)
{
	for(int i=1;i<=n;++i)
	{
		Set[dir][nedge][i]=i;
	}
}

inline void Union_Set(int dir,int nedge,int x,int y)
{
	Set[dir][nedge][Find_Set(dir,nedge,x) ]= Find_Set(dir,nedge,y);
}

int pre[M],last[M];

struct Edge
{
	int u,v;
}E[M];
int NewSet[N*2];
inline int nfind_set(int x)
{
	return x==NewSet[x]?x:NewSet[x]=nfind_set(NewSet[x]);
}
inline void nu_set(int x,int y)
{
	NewSet[nfind_set(x)]=nfind_set(y);
}
inline int count_Set(int fir,int las)
{
	
	for(int i=1;i<=n;++i)
	{
		NewSet[i] = Set[0][fir][i];
	}
	for(int i=1;i<=n;++i)
	{
		NewSet[i+n] = Set[1][las][i];
	}
	for(int i=1;i<=n;++i)
	{
		nu_set(i,i+n);
	}
	int myset[1005]={0};
	//puts("un:");
	for(int i=1;i<=n*2;++i)
	{
		//printf("%d -> %d\n",i,nfind_set(i));
		myset[nfind_set(i)]=1;
	}
	//printf("cnt = %d\n",myset.size());
	int cnt=0;
	for(int i=1;i<=n*2;++i)
	{
		cnt+=myset[i];
	}
	return cnt;
}

void pf(int dir,int nedge)
{
	printf("dir = %d , nedge = %d\n",dir,nedge);
	for(int i=1;i<=n;++i)
	{
		printf("%d -> %d\n",i,Find_Set(dir,nedge,i));
	}
}

int main(int argc, char const *argv[])
{
	//freopen("Din.txt","r",stdin);
	
	while(cin>>n>>m)
	{
		memset(pre,0,sizeof(pre));
		memset(last,0,sizeof(last));
		for(int i=1;i<=m;++i)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			E[i].u=u;
			E[i].v=v;
		}
		init_Set(0,1,n);
		for(int i=1;i<=m;++i)
		{
			Union_Set(0,i,E[i].v,E[i].u);
			for(int j=1;j<=n;++j)
			{
				Set[0][i+1][j]=Set[0][i][j];
			}
			//init_Set(1,i,n);
			//printf("pre %d:%d\n",i,count_Set(i,i));
			//pf(0,i);
		}
		init_Set(1,m,n);
		for(int i=m;i>=1;--i)
		{
			Union_Set(1,i,E[i].u,E[i].v);
			for(int j=1;j<=n;++j)
			{
				Set[1][i-1][j]=Set[1][i][j];
			}
			//init_Set(0,i,n);
			//printf("las %d:%d\n",i,count_Set(i,i));
			//pf(1,i);
		}
		int k;
		scanf("%d",&k);
		init_Set(0,0,n);
		init_Set(1,0,n);
		init_Set(0,m+1,n);
		init_Set(1,m+1,n);
		while(k--)
		{
			int l,r;
			scanf("%d%d",&l,&r);
			--l;
			++r;
			printf("%d\n",count_Set(l,r));
		}
	}

	return 0;
}