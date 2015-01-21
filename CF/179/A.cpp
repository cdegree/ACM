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

const int N = 100005;
struct cmd
{
	LL l,r,d;
}CD[N];

LL a[N];
struct query
{
	LL l,r;
}Q[N];
bool cmp(query a,query b)
{
	if(a.l!=b.l)
	{
		return a.l<b.l;
	}
	return a.r<b.r;
}
bool cmp2(cmd a,cmd b)
{
	if(a.l!=b.l)
	{
		return a.l<b.l;
	}
	return a.r<b.r;
}
LL cnt[N],add[N];
int main(int argc, char const *argv[])
{
	//freopen("Ain.txt","r",stdin);
	int n,m,k;
	while(cin>>n>>m>>k)
	{
		for(int i=1;i<=n;++i)
		{
			cin>>a[i];
		}
		for(int i=1;i<=m;++i)
		{
			cin>>CD[i].l>>CD[i].r>>CD[i].d;
		}
		for(int i=0;i<k;++i)
		{
			cin>>Q[i].l>>Q[i].r;
		}
		sort(Q,Q+k,cmp);
		memset(cnt,0,sizeof(cnt));
		memset(add,0,sizeof(add));
		for(int i=0;i<k;++i)
		{
			++add[ Q[i].l ];
			--add[ Q[i].r+1 ];
		}
		LL sum = 0;
		for(int i=1;i<=m;++i)
		{
			sum += add[i];
			cnt[i] += sum;
			CD[i].d *= cnt[i];
			//cout<<add[i]<<"  "<<cnt[i]<<" "<<CD[i].d<<endl;
		}
		sort(CD+1,CD+m+1,cmp2);
		memset(add,0,sizeof(add));
		for(int i=1;i<=m;++i)
		{
			add[ CD[i].l ]  +=CD[i].d;
			add[ CD[i].r+1 ]-=CD[i].d;
			//cout<<add[i]<<"  "<<" "<<CD[i].d<<endl;
		}
		sum = 0;
		for(int i=1;i<=n;++i)
		{
			sum += add[i];
			a[i] += sum;
			cout<<a[i]<<"  ";
		}
		cout<<endl;
	}
	return 0;
}