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

typedef long long LL ;


LL res,n,k;

bool vis[9],ok[9];
int p[9];
bool OK()
{
	memset(vis,false,sizeof(vis));
	memset(ok,false,sizeof(ok));
	ok[1]=0;
	for(int i=2;i<=k;i++)
	{
		int go = p[i];
		while(   (go!=1&&!vis[go]) )
		{
			vis[go]=1;
			//printf("%d\n",go );
			go = p[go];
		}
		if(go!=1&&!ok[go])
		{
			return false;
		}
		go = p[i];
		while(go!=1)
		{
			ok[go]=1;
			go=p[go];
		}
	}
	return true;
}
void gao(int cur)
{
	if(cur==k+1)
	{
		if(OK())
		{
			++res;
		}
		return ;
	}
	for(int i=1;i<=k;i++)
	{
		p[cur]=i;
		gao(cur+1);
	}
}
const LL mod =1000000007LL ;
LL P(LL m,LL y)
{
	LL ret = 1;
	for(int i=0;i<y;i++)
	{
		ret *= m;
		ret %= mod;
	}
	return ret;
}
int main(int argc, char const *argv[])
{
	//freopen("Bin.txt","r",stdin);
	while(cin>>n>>k)
	{
		res=0;
		gao(2);
		//cout<<res*k<<endl;
		res *=k;
		res %=mod;
		res*=P(n-k,n-k);
		res %=mod;
		cout<<res<<endl;
	}
	return 0;
}