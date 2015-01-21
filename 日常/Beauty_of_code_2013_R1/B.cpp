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
const int N = 50005;
char s1[N],s2[N];

int gao()
{
	int n1 = strlen(s1);
	int n2 = strlen(s2);
	int res = N;
	for(int st=0;st+n2<=n1;++st)
	{
		int cnt=0;
		for(int j=0;j<n2;++j)
		{
			if( s1[st+j ]!=s2[j] )
			{
				++cnt;
			}
		}
		res = min(res,cnt);
	}
	return res;
}

int main(int argc, char const *argv[])
{
	freopen("Bin.txt","r",stdin);
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;++t)
	{
		scanf("%s",s1);
		scanf("%s",s2);
		printf("Case #%d: ",t);
		int res = gao();
		printf("%d\n",res);
	}
	return 0;
}