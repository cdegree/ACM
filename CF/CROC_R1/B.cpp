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

const int N = 100005;

int dirto[N*2],next[N*2],nedge,head[N],degree[N];
int n,m;
void init()
{
	nedge=0;
	memset(degree,0,sizeof(degree));
	memset(head,-1,sizeof(head));
}

void add_edge(int u,int v)
{
	dirto[nedge]=v;
	next[nedge]=head[u];
	head[u]=nedge++;
}


int main(int argc, char const *argv[])
{
	//freopen("Bin.txt","r",stdin);
	while(cin>>n>>m)
	{
		init();
		for(int i=0;i<m;++i)
		{
			int u,v;
			scanf("%d %d",&u,&v);
			add_edge(u,v);
			degree[u]++;
			degree[v]++;
		}
		int cnt1=0,cnt2=0,cntn_1=0;
		for(int i=1;i<=n;++i)
		{
			if(degree[i]==1)
			{
				++cnt1;
			}
			else if(degree[i]==2)
			{
				++cnt2;
			}
			else if(degree[i]==n-1)
			{
				++cntn_1;
			}
		}
		if(cnt1==2&&cnt2==n-2)
		{
			puts("bus topology");
		}
		else if(cnt2==n)
		{
			puts("ring topology");
		}
		else if(cnt1==n-1&&cntn_1==1)
		{
			puts("star topology");
		}
		else 
		{
			puts("unknown topology");
		}
	}
	return 0;
}