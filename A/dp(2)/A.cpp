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
struct stick
{
	int l,w;
}S[5005];
bool cmp(stick a,stick b)
{
	if(a.l!=b.l)
	{
		return a.l>b.l;
	}
	return a.w>b.w;
}
int dp[5005];
int main(int argc, char const *argv[])
{
	int T;
	freopen("Ain.txt","r",stdin);
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&S[i].l,&S[i].w);
		}
		sort(S,S+n,cmp);
		int len = 0 ; 
		int res = 0 ;
		dp[0]=0;
		for(int i=0;i<n;++i)
		{
			int l,r,mid,ans;
			l=0,r=len;
			while(l<=r)
			{
				mid = (l+r)>>1;
				if( dp[mid]<S[i].w )
				{
					ans = mid ;
					l = mid + 1;
				}
				else 
				{
					r = mid - 1;
				}
			}
			dp[ans+1]=S[i].w;
			len=max(len,ans+1);
		}
		printf("%d\n",len );
	}
	return 0;
}