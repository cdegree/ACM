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
const int maxn = 1000005;

#define lson L , mid , rt << 1
#define rson mid + 1 , R , rt << 1 | 1
#define lc rt<<1
#define rc rt<<1|1

LL a[maxn];
struct Segment_Tree
{
	LL mx[maxn*4];
	LL add[maxn*4];
	int left[maxn*4],right[maxn*4];
	void Build(int L,int R,int rt)
	{
		add[rt]=0;
		mx[rt]=0;
		left[rt]=L,right[rt]=R;
		if(L==R)
		{
			mx[rt] = a[L];
		}
		else
		{
			int mid = (L+R)>>1;
			Build(lson);
			Build(rson);
			Push_Up(rt);
		}
	}
	void Push_Up(int rt)
	{
		mx[rt] = max( mx[lc] , mx[rc] );
	}
	void Push_Down(int rt)
	{
		if(add[rt]>0)
		{
			mx[lc] += add[rt];
			mx[rc] += add[rt];
			add[lc] += add[rt];
			add[rc] += add[rt];
			add[rt] = 0;
		}
	}
	void Update(int L,int R,int rt,int from,int to,LL val)
	{
	    if(from<=L&&R<=to)
		{
			mx[rt] += val;
			add[rt] += val;
		}
		else
		{
			int mid = (L+R)>>1;
			Push_Down(rt);
			if(from<=mid)
			{
				Update(lson,from,to,val);
			}
			if(to>mid)
			{
				Update(rson,from,to,val);
			}
			Push_Up(rt);
		}
	}
	LL Query(int L,int R,int rt,int from,int to)
	{
		if(from<=L&&R<=to)
		{
			return mx[rt];
		}
		else
		{
			int mid = (L+R)>>1;
			LL big = 0;
			Push_Down(rt);
			if(from<=mid)
			{
				big = max(big,Query(lson,from,to));
			}
			if(to>mid)
			{
				big = max(big,Query(rson,from,to));
			}
			//Push_Up(rt);
			return big;
		}
	}
}Seg;

int main(int argc, char const *argv[])
{
	int n;
	freopen("Kin.txt","r",stdin);
	while(~scanf("%d",&n))
	{
		for(int i=1;i<=n;++i)
		{
			scanf("%d",a+i);
		}
		Seg.Build(1,n,1);
		int q;
		scanf("%d",&q);
		while(q--)
		{
			int t,l,r;
			LL x;
			scanf("%d",&t);
			if(t==0)
			{
				scanf("%d %d %lld",&l,&r,&x);
				Seg.Update(1,n,1,l,r,x);
			}
			else
			{
				scanf("%d%d",&l,&r);
				printf("%lld\n",Seg.Query(1,n,1,l,r));
			}
/*
			puts("*****");
			for(int i=1;i<=20;++i)
			{
			    printf("%d: %d->%d : mx = %lld add = %d\n",i,Seg.left[i],Seg.right[i],Seg.mx[i],Seg.add[i]);
			}
			puts("*****");
*/
		}
	}
	return 0;
}
