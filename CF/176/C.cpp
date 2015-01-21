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
const int N =1000005;
int orther[N];
bool vis[N];

int get_left(int mask)
{
	int i;
	for( i=22;i>=0;i--)
	{
		if((1<<i)&mask)
		{
			break;
		}
	}
	return i;
}

int main(int argc, char const *argv[])
{
	//freopen("Cin.txt","r",stdin);
	int n;
	while(cin>>n)
	{
		memset(vis,false,sizeof(vis));
		for(int i=n;i>=0;--i)
		{
			if(vis[i])continue;
			int l=get_left(i);
			int o = ((1<<(l+1))-1)&(~i);
			orther[i]=o;
			orther[o]=i;
			vis[o]=true;
		}
		long long sum = 0 ;
		for(int i=0;i<=n;i++)
		{
			sum += i^orther[i];
		}
		printf("%I64d\n",sum );
		for(int i=0;i<=n;i++)
		{
			printf("%d ",orther[i] );
		}
		puts("");
	}
	return 0;
}