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

const int N  =100005;

struct Segment
{
	int l,r;
	int px;
	bool pp;
	bool npd;
}Seg[N*4];


void init(int u,int L,int R)
{
	Seg[u].px=0;
	Seg[u].pp=false;
	Seg[u].npd=false;
	if(L==R)
	{
		Seg[u].px=0;
	}
	else 
	{
		int l=u*2,r=u*2+1,mid=(L+R)/2;
		init(l,L,mid);
		init(r,mid+1,R);
	}
}
inline void push_down(int u,int l,int r)
{
	Seg[r].px=Seg[l].px=Seg[u].px;
	Seg[r].pp=Seg[l].pp=Seg[u].pp;
	Seg[r].npd=Seg[l].npd=Seg[u].npd;
	Seg[u].npd=0;
}
void push_up(int u,int l,int r)
{

}
void update(int u,int L,int R,int from,int to,int px)
{
	if(L==from&&R==to)
	{
		Seg[u].px=px;
		Seg[u].pp=1;
		Seg[u].npd=1;
	}
	else 
	{
		int l=u*2,r=u*2+1,mid=(L+R)/2;
		if(Seg[u].npd)
		{
			push_down(u,l,r);
		}
		if(to<=mid)
		{
			update(l,L,mid,from,to,px);
		}
		else if(from>mid)
		{
			update(r,mid+1,R,from,to,px);
		}
		else 
		{
			update(l,L,mid,from,mid,px);
			update(r,mid+1,R,mid+1,to,px);
		}
		push_up(u,l,r);
	}
}
const int inf = 1000000;
int query(int u,int L,int R,int pos)
{
	if(pos==L&&pos==R)
	{
		if(Seg[u].pp)return Seg[u].px;
		else return inf;
	}
	else 
	{
		int l=u*2,r=u*2+1,mid=(L+R)/2;
		if(Seg[u].npd)
		{
			push_down(u,l,r);
		}
		if(pos<=mid)
		{
			return query(l,L,mid,pos);
		}
		else 
		{
			return query(r,mid+1,R,pos);
		}
		push_up(u,l,r);
	}
}
int a[N],b[N];
int main(int argc, char const *argv[])
{
	//freopen("Cin.txt","r",stdin);
	int n,m;
	while(cin>>n>>m)
	{
		for(int i=1;i<=n;++i)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;++i)
		{
			cin>>b[i];
		}
		while(m--)
		{
			int t;
			cin>>t;
			if(t==1)
			{
				int x,y,k;
				cin>>x>>y>>k;
				update(1,1,n,y,y+k-1,x-y);
			}
			else 
			{
				int val;
				cin>>val;
				int q = query(1,1,n,val);
				if(q!=inf)
				{
					printf("%d\n",a[val+q]);
				}
				else 
				{
					printf("%d\n",b[val]);
				}
			}
		}
	}
	return 0;
}