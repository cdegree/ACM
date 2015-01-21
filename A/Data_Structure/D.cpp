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
#include <stdlib.h>
#include <stdio.h>

using namespace std;

typedef long long LL ;

const int maxn = 20005;

#define lson L , mid , rt << 1
#define rson mid + 1 , R , rt << 1 | 1
#define lc rt<<1
#define rc rt<<1|1

struct Segment_Tree
{
	int cnt[maxn*4];
	int len[maxn*4];
	int num[maxn*4];
	bool Lcd[maxn*4],Rcd[maxn*4];
	int left[maxn*4],right[maxn*4];
	void Build(int L,int R,int rt)
	{
		num[rt] = cnt[rt] = 0;
		len[rt] = 0;
		left[rt]=L;
		right[rt]=R;
		Lcd[rt]=Rcd[rt]=false;
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
		if( cnt[rt] )
		{
			len[rt] = right[rt] - left[rt] + 1;
			Lcd[rt] = Rcd[rt] = true;
			num[rt] = 1;
		}
		else if(right[rt]==left[rt])
		{
			len[rt] = 0;
			Lcd[rt] = Rcd[rt] = false;
			num[rt] = 0;
		}
		else 
		{
			len[rt] = len[lc] + len[rc];
			num[rt] = num[lc] + num[rc];
			Lcd[rt] = Lcd[lc];
			Rcd[rt] = Rcd[rc];
			if(Rcd[lc]&&Lcd[rc])--num[rt];
		}
	}
	void Push_Down(int rt)
	{
	}
	void Update(int L,int R,int rt,int from,int to,int val)
	{
		//printf("from %d to %d\n",rt);
		if(from<=L&&R<=to)
		{
			cnt[rt] += val;
			Push_Up(rt);
		}
		else 
		{
			int mid = (L+R)>>1;
			//Push_Down(rt);
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
	void Query(int L,int R,int rt,int &_len,int &_num)
	{
		_len = len[1];
		_num = num[1];
	}

}Seg;

const int offset = 10000;
int len;
struct Segment
{
	int l,r,h,c;
}S[10005];
inline void add_segment(int l,int r,int h,int c)
{
	S[len].l=l+offset+1;
	S[len].r=r+offset;
	S[len].h=h;
	S[len++].c=c;
}
bool cmp(Segment a,Segment b)
{
	if(a.h==b.h)
	{
		return a.c>b.c;
	}
	return a.h<b.h;
}
int main(int argc, char const *argv[])
{
	int n;
	freopen("Din.txt","r",stdin);
	while(~scanf("%d",&n))
	{
		len=0;
		for(int i=0;i<n;++i)
		{
			int x0,y0,x1,y1;
			scanf("%d%d%d%d",&x0,&y0,&x1,&y1);
			add_segment(x0,x1,y0,1);
			add_segment(x0,x1,y1,-1);
		}
		sort(S,S+len,cmp);
		int m = offset*2-1;
		Seg.Build(1,m,1);
		Seg.Update(1,m,1,S[0].l,S[0].r,S[0].c);
		int preh = S[0].h;
		int prelen = 0;
		int num,lenth;
		int P = 0,Q=0;
		for(int i=1;i<len;++i)
		{
			Seg.Query(1,m,1,lenth,num);
			//printf("%d:  preh = %d, prelen = %d, lenth = %d, num = %d\n",i,preh,prelen,lenth,num);
			if(S[i].h!=preh)
			{
				P += num*2*(S[i].h-preh); 
			}
			Q += abs(prelen-lenth) ;
			Seg.Update(1,m,1,S[i].l,S[i].r,S[i].c);
			preh=S[i].h;
			prelen=lenth;
		}
		Q += prelen ;
		printf("%d\n",P+Q);
	}
	return 0;
}