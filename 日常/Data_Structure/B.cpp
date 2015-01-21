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
const int maxn = 100005;
const int E = maxn*2;
#define lson L , mid , rt << 1
#define rson mid + 1 , R , rt << 1 | 1
#define lc rt<<1
#define rc rt<<1|1


struct Segment_Tree
{
	LL val[maxn*4];
	LL add[maxn*4];
	int left[maxn*4],right[maxn*4];
	inline void init(int N)
	{
		Build(1,N,1);
	}
	void Build(int L,int R,int rt)
	{
		add[rt]=0;
		val[rt]=0;
		if(L==R)
		{
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
	}
	void Push_Down(int rt)
	{
		if(add[rt])
		{
			val[lc] += add[rt];
			val[rc] += add[rt];
			add[lc] += add[rt];
			add[rc] += add[rt];
			add[rt] = 0;
		}
	}
	void Update(int L,int R,int rt,int from,int to,LL _add)
	{
	    if(from<=L&&R<=to)
		{
			val[rt] += _add;
			add[rt] += _add;
		}
		else
		{
			int mid = (L+R)>>1;
			Push_Down(rt);
			if(from<=mid)
			{
				Update(lson,from,to,_add);
			}
			if(to>mid)
			{
				Update(rson,from,to,_add);
			}
			Push_Up(rt);
		}
	}
	LL Query(int L,int R,int rt,int pos)
	{
		if(L==pos&&pos==R)
		{
			return val[rt];
		}
		else
		{
			int mid = (L+R)>>1;
			Push_Down(rt);
			if(pos<=mid)
			{
				return Query(lson,pos);
			}
			else
			{
				return Query(rson,pos);
			}
		}
	}
}Seg_Depth,Seg_Small;

int depth[maxn],id_on_seg[maxn],top[maxn],buttom[maxn];

int dirto[E],next[E],head[maxn],nedge;

void init()
{
	nedge=0;
	memset(head,-1,sizeof(head));
}

void add_edge(int u,int v)
{
	dirto[nedge]=v;
	next[nedge]=head[u];
	head[u]=nedge++;
}

int time_stamp,depiest;
void dfs(int rt,int pre,int dep)
{
	//printf("rt = %d\n",rt);
	id_on_seg[rt] = ++time_stamp;
	depth[rt] = dep;
	depiest=max(dep,depiest);
	int v;
	top[rt] = id_on_seg[rt];
	if(pre!=1)top[rt] = top[pre];
	buttom[rt] = id_on_seg[rt];
	for(int e=head[rt];~e;e=next[e])
	{
		v = dirto[e];
		if(v!=pre)
		{
			dfs(v,rt,dep+1);
			buttom[rt] = max(buttom[rt],buttom[v]);
		}
	}
	//printf("rt = %d, here_low = %d\n",rt,here_low);
}
void gao(int n)
{
	time_stamp=0;
	depiest=1;
	dfs(1,1,1);
	//printf("t = %d,d = %d\n",time_stamp,depiest);
	//for(int i=1;i<=n;++i){printf("%d:\ndepth = %d,  id_on_seg = %d,   top = %d,   buttom = %d\n",i,depth[i],id_on_seg[i],top[i],buttom[i]);}
	Seg_Depth.Build(1,depiest,1);
	Seg_Small.Build(1,time_stamp,1);
}
int main(int argc, char const *argv[])
{
	int n,q;
	freopen("Bin.txt","r",stdin);
	while(~scanf("%d%d",&n,&q))
	{
	    init();
		for(int i=1;i<n;++i)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			add_edge(u,v);
			add_edge(v,u);
		}
		gao(n);
		while(q--)
		{
			int t,v,d;
			LL x;
			scanf("%d",&t);
			if(t==0)
			{
				scanf("%d %lld %d",&v,&x,&d);
				if(v==1)
				{
					Seg_Depth.Update(1,depiest,1,1,d+1,x);
				}
				else
				{
					int depth_len = d - depth[v] + 2;
					//printf("len = %d\n",depth_len);
					if(depth_len>0)
					{
						Seg_Depth.Update(1,depiest,1,1,depth_len,x);
						int L = min( max(top[v] + depth_len - 1,top[v]) ,buttom[v]+1);
						int R = (id_on_seg[v] + d > buttom[v])?buttom[v]:(id_on_seg[v]+d);
						//printf("%d -> %d\n",L,R);
						if(L<=R)
						{
							Seg_Small.Update(1,time_stamp,1,L,R,x);
						}
					}
					else
					{
						int L = id_on_seg[v] - d;
						int R = ( id_on_seg[v] + d > buttom[v])?buttom[v]:(id_on_seg[v]+d);
						Seg_Small.Update(1,time_stamp,1,L,R,x);
					}
				}
			}
			else
			{
				scanf("%d",&v);
				LL res = Seg_Depth.Query(1,depiest,1,depth[v]) + Seg_Small.Query(1,time_stamp,1,id_on_seg[v]);
				printf("%lld\n",res);
			}
/*
			puts("*****");
			for(int i=1;i<=20;++i)
			{
			    printf("%d: %d->%d : empty = %d npd = %d occupied = %d\n",i,Seg.left[i],Seg.right[i],Seg.mxempty[i],Seg.npd[i],Seg.occupied[i]);
			}
			puts("*****");
*/
		}
	}
	return 0;
}
