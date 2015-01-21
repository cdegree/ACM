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
const int N = 100005;
int fa[N],lleft[N],rright[N],next[N],head[N],dirto[N],nedge;

struct Segment
{
	int cnt_zero;
	int cnt_one;
	int cnt_xor;
}Seg[N*4];

void push_up(int u,int l,int r)
{
	Seg[u].cnt_one = Seg[l].cnt_one + Seg[r].cnt_one ;
	Seg[u].cnt_zero = Seg[l].cnt_zero + Seg[r].cnt_zero ;
}

void init(int u,int L,int R)
{
	Seg[u].cnt_xor=0;
	if(L==R)
	{
		Seg[u].cnt_one=0,Seg[u].cnt_zero=1;
	}
	else 
	{
		int l=u*2,r=u*2+1;
		int mid=(L+R)>>1;
		init(l,L,mid);
		init(r,mid+1,R);
		push_up(u,l,r);
	}
}

void push_down(int u,int l,int r)
{
	Seg[u].cnt_xor=0;
	++Seg[l].cnt_xor;
	++Seg[r].cnt_xor;
	swap(Seg[l].cnt_one,Seg[l].cnt_zero);
	swap(Seg[r].cnt_one,Seg[r].cnt_zero);
}

void negat(int u,int from,int to,int L,int R)
{
	if(from==L&&to==R)
	{
		swap(Seg[u].cnt_zero,Seg[u].cnt_one);
		++Seg[u].cnt_xor;
	}
	else 
	{
		int l=u*2,r=u*2+1,mid=(L+R)>>1;
		Seg[u].cnt_xor%=2;
		if(Seg[u].cnt_xor)
		{
			push_down(u,l,r);
		}
		
		if(to<=mid)
		{
			negat(l,from,to,L,mid);
		}
		else if(from>mid)
		{
			negat(r,from,to,mid+1,R);
		}
		else 
		{
			negat(l,from,mid,L,mid);
			negat(r,mid+1,to,mid+1,R);
		}
		push_up(u,l,r);
	}
}

int query(int u,int from,int to,int L,int R)
{
	if(from==L&&to==R)
	{
		return Seg[u].cnt_one;
	}
	else 
	{
		int l=u*2,r=u*2+1,mid=(R+L)>>1;
		Seg[u].cnt_xor%=2;
		if(Seg[u].cnt_xor)
		{
			push_down(u,l,r);
		}
		if(to<=mid)
		{
			return query(l,from,to,L,mid);
		}
		else if(from>mid)
		{
			return query(r,from,to,mid+1,R);
		}
		else 
		{
			return query(l,from,mid,L,mid)+query(r,mid+1,to,mid+1,R);
		}
	}
}

void add_edge(int u,int v)
{
	dirto[nedge]=v;
	next[nedge]=head[u];
	head[u]=nedge++;
}

int go;
void dfs(int cur,int pre)
{
	lleft[cur]=++go;
	for(int e=head[cur];~e;e=next[e])
	{
		int v = dirto[e];
		dfs(v,cur);
	}
	rright[cur]=go;
}
int main(int argc, char const *argv[])
{
	int n,m;
	//freopen("Ain.txt","r",stdin);
	while(~scanf("%d%d",&n,&m))
	{
		nedge=0;
		memset(head,-1,sizeof(head));
		for(int i=2;i<=n;++i)
		{
			scanf("%d",fa+i);
			add_edge(fa[i],i);
		}
		go=0;
		dfs(1,1);
		//for(int i=1;i<=n;++i)printf("%d %d\n",lleft[i],rright[i] );
		
		char s[3];
		int idx;
		init(1,1,n);
		while(m--)
		{
			scanf("%s %d",s,&idx);
			if(s[0]=='o')
			{
				negat(1,lleft[idx],rright[idx],1,n);
			}
			else 
			{
				printf("%d\n",query(1,lleft[idx],rright[idx],1,n) );
			}
		}
		puts("");
	}
	return 0;
}