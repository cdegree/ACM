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
LL res;
inline void gao(LL n)
{
	res = max(n,res);
	if(n==1)return ;
	if(n&1)
	{
		gao(n*3+1);
	}
	else 
	{
		gao(n/2);
	}
}
int main(int argc, char const *argv[])
{
	LL n;
	freopen("Ain.txt","r",stdin);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int t;
		scanf("%d %lld",&t,&n);
		res = n;
		gao(n);
		printf("%d %lld\n",t,res);
	}
	return 0;
}