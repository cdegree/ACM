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
set<pair<int,int> > sp;  // pos, id
int a[N];
int n;

struct building
{
	LL cnt_one;
	LL cnt_zero;
	bool equal_pre;
	int idx;
}BD[N];


int main(int argc, char const *argv[])
{
	freopen("Ain.txt","r",stdin);
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;++t)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
		{
			scanf("%d",a+i);
		}
		for(int i=0;i<=n+1;++i)
		{
			BD[i].idx=i;
			BD[i].cnt_zero=BD[i].cnt_one=0;
			BD[i].equal_pre=false;
		}
		BD[0].cnt_zero=1,BD[n+1].cnt_one=1;
		sp.clear();
		sp.insert(make_pair(0,0));
		sp.insert(make_pair(5000005,n+1));
		LL res1=0,res2=0;
		for(int i=1;i<=n;++i)
		{
			pair<int,int> mp = make_pair(a[i],i);
			sp.insert(mp);
			set<pair<int,int> >::iterator it = sp.find(mp);
			pair<int,int> pre = *(--it);
			++it;
			pair<int,int> next = *(++it);
			int preid = pre.second;
			int nextid = next.second;
			if(BD[nextid].equal_pre)
			{
				BD[i].cnt_one = BD[nextid].cnt_one ;
				BD[i].cnt_zero = BD[nextid].cnt_zero + 1;
				BD[i].equal_pre=true;
				BD[nextid].equal_pre=false;

				res1 += BD[i].cnt_one + BD[i].cnt_zero;
				res2 += BD[i].cnt_one;
			}
			else 
			{
				BD[i].cnt_one = BD[preid].cnt_one + 1;
				BD[i].cnt_zero = BD[preid].cnt_zero ;
				BD[i].equal_pre=true;

				res1 += BD[i].cnt_one + BD[i].cnt_zero;
				res2 += BD[i].cnt_one;
			}
		}
		//for(int i=0;i<=n+1;++i)printf("%d: cnt_one = %d ,  cnt_zero = %d, equal_pre = %d\n",i,BD[i].cnt_one,BD[i].cnt_zero,BD[i].equal_pre);
		
		printf("Case #%d: %lld %lld\n",t,res1+2,res2+1);
	}
	return 0;
}