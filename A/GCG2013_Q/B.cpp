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
int n,m;

int a[105][105];

bool OK1(int x,int y)
{
	int h = a[x][y];
	for(int i=0;i<n;++i)
	{
		if(a[i][y]>h)
		{
			return false;
		}
	}
	return true;
}

bool OK2(int x,int y)
{
	int h = a[x][y];
	for(int j=0;j<m;++j)
	{
		if(a[x][j]>h)
		{
			return false;
		}
	}
	return true;
}

bool check(int x,int y)
{
	
	if(OK1(x,y)||OK2(x,y))
	{
		return true;
	}
	else 
	{
		return false;
	}
}
bool gao()
{
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			if(!check(i,j))
			{
				return false;
			}
		}
	}
	return true;
}
int main(int argc, char const *argv[])
{
	//freopen("B-small-attempt0.in","r",stdin);
	//freopen("B-small-attempt0.out","w",stdout);
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;++t)
	{
		scanf("%d %d",&n,&m);
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<m;++j)
			{
				scanf("%d",&a[i][j]);
			}
		}
		printf("Case #%d: ",t);
		if(gao())
		{
			puts("YES");
		}
		else 
		{
			puts("NO");
		}
	}
	return 0;
}