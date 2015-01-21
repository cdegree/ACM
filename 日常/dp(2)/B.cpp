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

char c[2];

LL dp[55][4];

char res[55];
void reverse(int len)
{
	for(int i=0;i<=len/2;++i)
	{
		swap(res[i],res[len-i-1]);
	}
}
int main(int argc, char const *argv[])
{
	int n,k;
	freopen("Bin.txt","r",stdin);
	
	while(~scanf("%s%d%d",c,&n,&k))
	{
		int id = c[0] - 'A';
		memset(dp,0,sizeof(dp));
		dp[0][id]=1;
		for(int i=1;i<=n;++i)
		{
			dp[i][0] = dp[i-1][1] + dp[i-1][2];
			dp[i][1] = dp[i-1][0] + dp[i-1][3];
			dp[i][2] = dp[i-1][0] + dp[i-1][3];
			dp[i][3] = dp[i-1][1] + dp[i-1][2];
		}
		/*
		for(int i=0;i<=n;++i)
		{
			for(int j=0;j<4;++j)
			{
				printf("%30lld",dp[i][j]);
			}
			puts("");
		}
		puts("");
		*/
		if(dp[n][0]<k)
		{
			puts("impossible");
		}
		else 
		{
			int len = 0 ;
			id = 0 ;
			while(n>0)
			{
				if(id==0||id==2)
				{
					if(dp[n-1][(id+2)%4]>=k)
					{
						id = (id+2)%4;
						res[len++] = '0';
					}
					else 
					{
						k -= dp[n-1][(id+2)%4];
						id = (id+1)%4;
						res[len++] = '1';
					}
				}
				else 
				{
					if(dp[n-1][(id+2)%4]>=k)
					{
						id = (id+2)%4;
						res[len++] = '0';
					}
					else 
					{
						k -= dp[n-1][(id+2)%4];
						id = (id+3)%4;
						res[len++] = '1';
					}
				}
				--n;
			}
			for(int i=0;i<len;++i)
			{
				printf("%c",res[i]);
			}
			puts("");
		}
	}
	return 0;
}