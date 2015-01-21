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

#define lson L , mid , rt << 1
#define rson mid + 1 , R , rt << 1 | 1
#define lc rt<<1
#define rc rt<<1|1

const int maxn = 30005;
int n,m;
struct Segment
{
	LL S[maxn*4];
	int cnt[maxn*4];
	LL len[maxn*4];
	LL left[maxn*4],right[maxn*4];
	void Build(int L,int R,int rt)
	{
		S[rt]=0;
		cnt[rt]=0;
		left[rt]=L,right[rt]=R;
		if(L==R)
		{
			;
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
		if(cnt[rt])
		{
			len[rt] = right[rt] - left[rt] + 1;
		}
		else if(left[rt] == right[rt])
		{
			len[rt] = 0;
		}
		else 
		{
			len[rt] = len[lc] + len[rc];
		}
	}
	void Push_Down(int rt)
	{
	}
	void Update(int L,int R,int rt,int from,int to,int val)
	{
		if(from<=L&&R<=to)
		{
			cnt[rt] += val;
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
			return len[rt];
		}
		else 
		{
			int mid = (L+R)>>1;
			Push_Down(rt);
			LL ret = 0 ;
			if(from<=mid)
			{
				ret += Query(lson,from,to);
			}
			if(to>mid)
			{
				ret += Query(rson,from,to);
			}
			Push_Up(rt);
			return ret;
		}
	}
}Seg;

struct rectagle
{
	LL x0,y0,x1,y1;
	int belongto;
}Rec[N];

struct SegLine
{
	LL x0,x1,y;
}SL[N*2];

int kind[3];
int main(int argc, char const *argv[])
{
	freopen("Bin.txt","r",stdin);
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;++t)
	{
		scanf("%d %d",&n,&m);
		for(int i=0;i<m;i++)
		{
			scanf("%d",kind+i);
		}
		for(int j=0;j<n;++j)
		{
			scanf("%I64d%I64d%I64d%I64d%d",&Rec[i].x0,&Rec[i].y0,&Rec[i].x1,&Rec[i].y1,&Rec[i].belongto);
		}
		
	}
	return 0;
}