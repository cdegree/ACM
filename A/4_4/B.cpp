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
const int N = 1<<25+2;

LL mod = 55566677LL ;

LL f[55],J[55],res ;

int n,m;
bool A[55],B[55];
bool vis[55];

vector< pair<int,int> > vp;

void init()
{
	LL ans = 1;
	for(LL i=1;i<55;++i)
	{
		ans *= i;
		ans %= mod;
		J[i]= ans;
	}
	J[0]=1;
	memset(vis,false,sizeof(vis));
	memset(A,false,sizeof(A));
	memset(B,false,sizeof(B));
	memset(f,0,sizeof(f));
}

void gao(int cur,int cnt)
{
	if(cur==m)
	{
		f[cnt] += J[n-cnt];
		f[cnt] %= mod ;
		return ;
	}
	gao(cur+1,cnt);

	if( A[ vp[cur].first ] || B[ vp[cur].second ] ) return ;
	//printf("%d:%d --- %d\n",cur,vp[cur].first,vp[cur].second);

	A[ vp[cur].first ] = true ;
	B[ vp[cur].second ] = true ;

	gao( cur+1 , cnt+1 );

	A[ vp[cur].first ] = false ;
	B[ vp[cur].second ] = false ;
}

int main(int argc, char const *argv[])
{
	freopen("Bin.txt","r",stdin);
	while(~scanf("%d%d",&n,&m))
	{
		vp.clear();
		for(int i=0;i<m;i++)
		{
			int d,c;
			scanf("%d %d",&d,&c);
			vp.push_back(make_pair(d,c));
		}
		init();
		sort(vp.begin(),vp.end());
		for(int i=1;i<vp.size();)
		{
			if(vp[i].first==vp[i-1].first&&vp[i].second==vp[i-1].second)
			{
				vp.erase(vp.begin()+i);
			}
			else 
			{
				++i;
			}
		}
		//printf("len = %d \n",vp.size() );
		m=vp.size();
		gao(0,0);
		res = 0;
		for(int i=0;i<=m;++i)
		{
			int c = -1;
			if(i%2==0) c = -c ; 
			res = (res + f[i]*c + mod)%mod ;
		}
		printf("%lld\n",res );
	}
	return 0;
}

