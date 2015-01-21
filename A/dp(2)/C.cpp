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

int r,c;

LL dp[505][505];

LL k;
char s[505][505];
char res[1055];
const LL inf = 1e9+7;
int main(int argc, char const *argv[])
{
	freopen("Cin.txt","r",stdin);
	while(~scanf("%d %d %d",&r,&c,&k))
	{
		//memset(s,'\0',sizeof(s));
		for(int i=0;i<r;++i)
		{
			scanf("%s",s[i]);
		}

		memset(dp,0,sizeof(dp));
		for(int i=r;i>=1;--i)
		{
			for(int j=c;j>=1;--j)
			{
				if(i==r&&j==c)
				{
					dp[i][j]=1;
					continue;
				}
				dp[i][j]=0;
				if(s[i-1][j-1]=='.'&&s[i][j-1]=='.') 
				{
					dp[i][j] += dp[i+1][j] ;
				}
				if(s[i-1][j-1]=='.'&&s[i-1][j]=='.' )
				{
					dp[i][j] += dp[i][j+1] ;
				}
				if(dp[i][j]>inf)
				{
					dp[i][j]=inf;
				}
			}
		}
		/*
		for(int i=1;i<=r;++i)
		{
			for(int j=1;j<=c;++j)
			{
				printf("%8d",dp[i][j]);
			}
			puts("");
		}
		puts("");
		*/
		if(dp[1][1]<k)
		{
			puts("impossible");
		}
		else 
		{
			int row=1,col=1;
			int len=0;
			while(row<r||col<c)
			{
				if(dp[row+1][col]>=k)
				{
					++row;
					res[len++]='D';
				}
				else 
				{
					k -= dp[row+1][col];
					res[len++]='R';
					++col;
				}
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