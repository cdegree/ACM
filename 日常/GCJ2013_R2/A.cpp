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

struct trip
{
	LL st,ed,cnt;
}Tr[1000005];
const LL mod = 1000002013LL;
bool cmp(trip a,trip b)
{
	if(a.st!=b.st)
	{
		return a.st<b.st;
	}
	return a.ed<b.ed;
}
void pf()
{
	for(int i=0;i<m;++i)
	{
		printf("%lld %lld %lld\n",Tr[i].st,Tr[i].ed,Tr[i].cnt);
	}
}
LL cal(LL st,LL ed,LL cnt)
{
	LL len = ed-st;
	LL ret = (n-len+1+n)%mod;
	ret = (ret)*len/2;
	ret %= mod;
	ret *= cnt;
	ret %= mod;
	return ret;
}
int main(int argc, char const *argv[])
{
	freopen("Ain.txt","r",stdin);
	//freopen("","w",stdout);
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;++t)
	{
		scanf("%d %d",&n,&m);
		LL presum=0;
		for(int i=0;i<m;++i)
		{
			cin>>Tr[i].st>>Tr[i].ed>>Tr[i].cnt;
			presum += cal(Tr[i].st , Tr[i].ed , Tr[i].cnt);
			presum %= mod;
		}
		pf();
		LL nowsum=0;
		sort(Tr,Tr+m,cmp);

		for(int i=0;i<m;++i)
		{
			for(int j=0;j<i;++j)
			{
				if(Tr[i].st<=Tr[j].ed&&Tr[i].ed>Tr[j].ed)
				{
					LL mn = min(Tr[i].cnt,Tr[j].cnt);
					LL mx = max(Tr[i].cnt,Tr[j].cnt);
					if(mn>0)
					{
						int tmp = Tr[j].ed;
						Tr[j].ed = Tr[i].ed;
						Tr[j].cnt=mn;
						Tr[i].cnt=mx;
						Tr[i].ed = tmp;
					}
				}
			}
		}
		//printf("m = %d\n",m);
		pf();
		for(int i=0;i<m;++i)
		{
			nowsum += cal(Tr[i].st , Tr[i].ed , Tr[i].cnt);
			nowsum %= mod;
		}


		printf("%lld  %lld\n",presum,nowsum);
		LL res = (presum - nowsum +mod)%mod;
		printf("Case #%d: %lld\n",t,res);
	}
	return 0;
}