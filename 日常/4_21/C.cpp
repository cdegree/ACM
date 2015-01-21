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
int a,b,c;
int res;
void gao(int cur,int nowsum,int len)
{
	if(cur==0)
	{
		for(int i=1;i<=len/3;++i)
		{
			a=i;
			gao(cur+1,a,len);
		}
	}
	else if(cur==1)
	{
		int to = (len-a)/2;
		int from = max(a,(len-2*a)/2);
		while(2*from<=len-2*a)++from;
		if(from>to)return ;
		//printf("%d: %d -> %d\n",a,from,to);
		res += (to - from + 1)*2;

		if(from<=a&&to>=a)--res;
		if(2*from<=len-a&&2*to>=len-a)--res;
		if(len%3==0&&len/3==a&&2*from<=len-a&&2*to>=len-a)++res;
		//printf("res = %d\n",res);
	}
}
int main(int argc, char const *argv[])
{
	int n;
	int T;
	freopen("Cin.txt","r",stdin);
	scanf("%d",&T);
	while(T--)
	{
		int t;
		scanf("%d %d",&t,&n);
		res=0;
		gao(0,n,n);
		printf("%d %d\n",t,res);
	}
	return 0;
}