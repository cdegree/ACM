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
const int mod = 100;

LL dp[100][100][2],val[mod];

int main(int argc, char const *argv[])
{
	freopen("Ein.txt","r",stdin);
	int n;
	
	//freopen("Edata.txt","w",stdout);

	while(~scanf("%d",&n))
	{
		for(int i=0;i<n;i++)
		{
			scanf("%lld",val+i);
		}
		for(int i=0;i<mod;++i)
		{
			for(int j=0;j<mod;++j)
			{
				for(int k=0;k<2;++k)
				{
					dp[i][j][k] = 1e18;
				}
			}
		}
		//printf("dp = %lld\n",dp[0][0][0] );
		for(int i=0;i<n;i++)
		{
			dp[i][i][0]=val[i];
			dp[i][i][1]=0;
		}
		for(int len = 2;len <= n;++len)
		{
			for(int st = 0;st+len-1<n;st++)
			{
				int ed =  st + len - 1 ;
				//printf("%d ---> %d\n",st,ed );
				for(int j=st;j < ed;j++)
				{
								//printf("%d -> %d\n",j,j+1 );
					if(dp[st][j][1]+dp[j+1][ed][1]+dp[st][j][0]*dp[j+1][ed][0]<dp[st][ed][1])
					{
						dp[st][ed][1] = dp[st][j][1]+dp[j+1][ed][1]+dp[st][j][0]*dp[j+1][ed][0];
						dp[st][ed][0] = (dp[st][j][0]+dp[j+1][ed][0])%mod;
					}
				}
			}
		}
		LL res=dp[0][n-1][1];
		printf("%lld\n", res);
	}
	return 0;
}