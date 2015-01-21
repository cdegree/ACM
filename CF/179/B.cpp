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

const int N =505;

LL matrix[N][N];
LL dis[N][N];
LL a[N];
LL inf = 1e18;
int now[N];

LL res[N];
LL sum;
int len;
void gao(int cur)
{
	now[++len]=cur;
	for(int i=1;i<len;++i)
	{
		dis[ i ][ len ] = matrix[ now[i] ][ now[len] ];
		dis[len][ i ] = matrix[ now[len] ][ now[i] ] ;
	}

	dis[len][len]=0;
	for(int i=1;i<=len;++i)
	{
		for(int j=1;j<=len;++j)
		{
			if(dis[ i ][j] > dis[i ][len]+dis[len][j] )
			{
				dis[i][j] = dis[i ][len]+dis[len][j] ;
			}
		}
	}
	bool vis[N];
	memset(vis,false,sizeof(vis));
	for(int i=0;i<len;++i)
	{
		dis[len][len] = 0;
		LL mn = inf;
		int pos = -1;
		for(int j=1;j<=len;++j)
		{
			if(!vis[j]&&dis[len][j]<mn)
			{
				mn=dis[len][j];
				pos = j;
			}
		}
		vis[pos]=true;
		if(pos==-1)break;
		for(int j=1;j<=len;++j)
		{
			if(!vis[j]&&dis[len][j] > dis[len][pos] + dis[pos][j])
			{
				dis[len][j] = dis[len][pos] + dis[pos][j];
			}
		}
	}
	memset(vis,false,sizeof(vis));
	for(int i=0;i<len;++i)
	{
		LL mn = inf;
		int pos = -1;
		for(int j=1;j<=len;++j)
		{
			if(!vis[j]&&dis[j][len]<mn)
			{
				mn=dis[j][len];
				pos = j;
			}
		}
		vis[pos]=true;
		if(pos==-1)break;
		for(int j=1;j<=len;++j)
		{
			if(!vis[j]&&dis[j][len] > dis[j][pos] + dis[pos][len])
			{
				dis[j][len] = dis[j][pos] + dis[pos][len];
			}
		}
	}
	for(int i=1;i<=len;++i)
	{
		for(int j=1;j<=len;++j)
		{
			if(dis[ i ][j] > dis[i ][len]+dis[len][j] )
			{
				dis[i][j] = dis[i ][len]+dis[len][j] ;
			}
		}
	}
	
	//printf("len = %d\n",len);
	for(int i=1;i<=len;++i)
	{
		for(int j=1;j<=len;++j)
		{
			sum += dis[i][j] ;
			//printf("%10I64d",dis[i][j]);
		}
		//puts("");
	}
	//puts("");
}

int main(int argc, char const *argv[])
{
	//freopen("Bin.txt","r",stdin);
	int n;
	while(cin>>n)
	{
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=n;++j)
			{
				cin>>matrix[i][j];
				dis[i][j]=inf;
			}
		}
		vector<int> va;
		for(int i=1;i<=n;++i)
		{
			cin>>a[i];
			va.push_back(a[i]);
		}
		reverse(va.begin(),va.end());
		sum=0;
		len=0;
		for(int i=0;i<va.size();++i)
		{
			sum=0;
			gao(va[i]);
			res[i] = sum;
		}
		//puts("");
		for(int i=n-1;i>=0;--i)
		{
			cout<<res[i]<<" ";
		}
		cout<<endl;
		/*
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=n;++j)
			{
				dis[i][j]=matrix[i][j];
			}
		}
		for(int k=1;k<=n;++k)
		{
			for(int i=1;i<=n;++i)
			{
				for(int j=1;j<=n;++j)
				{
					if(dis[i][j]>dis[i][k]+dis[k][j])
					{
						dis[i][j] = dis[i][k]+dis[k][j];
					}
				}
			}
		}
		


		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=n;++j)
			{
				cout<<dis[i][j]<<"  ";
			}
			cout<<endl;
		}
		*/

	}
	return 0;
}