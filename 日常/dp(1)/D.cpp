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

int dp[404],color[404],val[404],c,n,idx[4];

bool check(const int x,const int y)
{
	if(idx[color[x]]!=idx[color[y]])
	{
		return idx[color[x]]>idx[color[y]];
	}
	return val[x]>val[y];
}

int main(int argc, char const *argv[])
{
	//freopen("Din.txt","r",stdin);
	scanf("%d %d",&c,&n);
	{
		int m = c*n;
		for(int i=0;i<m;i++)
		{
			scanf("%d %d",color+i,val+i);
			--color[i];
		}
		//if(m>400)while(1);
		for(int i=0;i<c;i++)
		{
			idx[i]=i;
		}
		int res = 0 ;
		do
		{
			memset(dp,0,sizeof(dp));
			for(int i=0;i<m;i++)
			{
				dp[i]=1;
				for(int j=0;j<i;j++)
				{
					if(check(i,j))
					{
						dp[i]=max(dp[i],dp[j]+1);
					}
				}
				res = max(res,dp[i]);
			}
		}while(next_permutation(idx,idx+c));
		printf("%d\n",m-res );
	}
	return 0;
}