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
using namespace std;
const double eps = 1e-8 ;
typedef long long LL ;

const int N = 1000005;

LL dp[N][2][5],sum[N][2];
LL mod;
char s[N*10];
int main(int argc, char const *argv[])
{
	int n;
	freopen("Din.txt","r",stdin);
	
	while(~scanf("%d%lld",&n,&mod))
	{
		memset(dp,0,sizeof(dp));
		dp[n-1][1][1] = dp[n-1][0][3] = 1;
		sum[n-1][1] = sum[n-1][0] = 1 ;
		for(int i=n-2;i>=0;--i)
		{
			dp[i][0][3] = dp[i+1][1][4] + dp[i+1][0][4];   // L is one more than P 
			dp[i][0][2] = dp[i+1][1][3] + dp[i+1][0][3];   // L is equal to P
			dp[i][0][1] = dp[i+1][1][2] + dp[i+1][0][2];   // L is one less than P
			dp[i][0][0] = dp[i+1][1][1] + dp[i+1][0][1];   // L is two less than P

			dp[i][1][1] = dp[i+1][1][0] + dp[i+1][0][0];   //
			dp[i][1][2] = dp[i+1][1][1] + dp[i+1][0][1];
			dp[i][1][3] = dp[i+1][1][2] + dp[i+1][0][2];
			dp[i][1][4] = dp[i+1][1][3] + dp[i+1][0][3];

			sum[i][0] = sum[i][1] = 0 ;
			for(int j=0;j<5;++j)
			{
				dp[i][0][j] %= mod;
				dp[i][1][j] %= mod;
				sum[i][0] += dp[i][0][j];
				sum[i][1] += dp[i][1][j];
			}
			sum[i][0] %= mod;
			sum[i][1] %= mod;
		}
		for(int i=0;i<n;++i)
		{
			printf("%10lld %10lld\n",sum[i][0],sum[i][1]);
		}
		scanf("%s",s);
		LL res = (sum[0][0] + sum[0][1]) % mod;
		int L=0,P=0;
		for(int i=0;i<n;++i)
		{
			if(s[i]=='L')
			{
				
			}
			else 
			{

			}
		}
		printf("%lld\n",res);
	}
	return 0;
}
