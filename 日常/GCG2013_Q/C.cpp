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

vector<LL> res;
int poss[19];
bool inline check(LL x)
{
	int ret[19],len=0;
	while(x>0)
	{
		ret[len++] = x%10 ;
		x/=10;
	}
	reverse(ret,ret+len);
	for(int i=0;i<len;++i)
	{
		if( ret[i] != ret[len-i-1] )
		{
			return false;
		}
	}
	return true;
}

LL stoLL(int len)
{
	LL e = 1,ret = 0;
	for(int i=len;i>=0;--i)
	{
		ret += e*(poss[i]);
		e *= 10;
	}
	return ret;
}
int len;


void gao(int cur,int n)
{
	//printf("cur = %d\n",cur);
	if(cur==n)
	{
		if(len&1)
		{
		    for(int i=1;i<n;++i)
		    {
		        poss[ len - i + 1 ] = poss[i];
		    }
		}
		else
		{
		    for(int i=1;i<=n;++i)
		    {
		        poss[ len - i + 1 ] = poss[i];
		    }
		}
		//printf("oh!!");
		LL nowans = stoLL(len)*stoLL(len);
		if(nowans<=100000000000000LL&&check(nowans))
		{
			res.push_back(nowans);
		}
		return ;
	}
	for(int i=0;i<10;++i)
	{
		poss[cur+1]=i;
		gao(cur+1,n);
	}
}

void init()
{
	//printf("ok\n");
	for(len=8;len>=1;--len)
	{
		//printf("len = %d\n",len);
		if(len&1)
		{
			int m = len / 2 + 1;
			for(int j=1;j<10;++j)
			{
				poss[1]=j;
				gao(1,m);
			}
		}
		else
		{
			int m = len / 2 ;
			for(int j=1;j<10;++j)
			{
				poss[1]=j;
				gao(1,m);
			}
		}
	}
	res.push_back(100000000000000000LL);
	sort(res.begin(),res.end());
	//printf("res.size = %d\n",res.size());for(int i=0;i<res.size();++i){printf("%lld\n",res[i]);}

}

int get_ans(LL R)
{
	for(int i=0;i<res.size();i++)
	{
		if(res[i]>R)
		{
			return i;
		}
	}
}

int main(int argc, char const *argv[])
{
	//freopen("C-small-attempt0.in","r",stdin);
	//freopen("C-small-attempt0.out","w",stdout);
	freopen("C-large-1.in","r",stdin);
	freopen("C-large-1.out","w",stdout);
	//freopen("Cin.txt","r",stdin);
	//freopen("Cout.txt","w",stdout);
	int T;
	res.clear();
	init();
	LL n,m;
	scanf("%d",&T);
	for(int t=1;t<=T;++t)
	{
		cin>>n>>m;
		printf("Case #%d: ",t);
		cout<<get_ans(m)-get_ans(n-1)<<endl;
		//cout<<m<<"   "<<n-1<<endl;
		//cout<<get_ans(m)<<"  "<<get_ans(n-1)<<endl;
	}
	return 0;
}
