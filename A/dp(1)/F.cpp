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
const double eps = 1e-8 ;
typedef long long LL ;

int dp[22][80];
int o[1005],n[1005],w[1005];

int main(int argc, char const *argv[])
{
	int T;
	freopen("Fin.txt","r",stdin);
	scanf("%d",&T);
	while(T--)
	{
		int O,N;
		scanf("%d%d",&O,&N);
		int q;
		scanf("%d",&q);
		for(int i=0;i<q;++i)
		{
			scanf("%d %d %d",o+i,n+i,w+i);
		}
		for(int i=0;i<=O;++i)
		{
			for(int j=0;j<=N;++j)
			{
				dp[i][j]=1e8;
			}
		}
		dp[0][0]=0;
		for(int k=0;k<q;++k)
		{
			int oo = o[k];
			int nn = n[k];
			int ww = w[k];
			for(int i=O;i>=0;--i)
			{
				for(int j=N;j>=0;--j)
				{
					if(dp[i][j]!=1e8)
					{
						dp[min(i+oo,O)][min(j+nn,N)] = min(dp[min(i+oo,O)][min(j+nn,N)] ,dp[i][j]+ww);
					}
				}	
			}
		}

		int res=dp[O][N];
		printf("%d\n", res);
	}
	return 0;
}