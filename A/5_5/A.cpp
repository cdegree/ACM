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

const int maxn = 100005;

#define lson L , mid , rt << 1
#define rson mid + 1 , R , rt << 1 | 1
#define lc rt<<1
#define rc rt<<1|1

struct Segment_Tree
{
	int mx[maxn*4];
	int add[maxn*4];
	int len[maxn*4];
	int left[maxn*4],right[maxn*4];
	void Build(int L,int R,int rt)
	{
		add[rt]=mx[rt]=0;
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
		mx[rt] = max(mx[lc],mx[rc]);
	}
	void Push_Down(int rt)
	{
		if(add[rt])
		{
			mx[lc] += add[rt];
			mx[rc] += add[rt];
			add[lc] += add[rt];
			add[rc] += add[rt];
			add[rt]=0;
		}
	}
	void Update(int L,int R,int rt,int from,int to,int val)
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
	int Query(int L,int R,int rt,int pos)
	{
		return mx[1];
	}

}Seg;

int main(int argc, char const *argv[])
{
	int T;
	freopen("Ain.txt","r",stdin);
	int N = maxn;
	scanf("%d",&T);
	while(T--)
	{
		Seg.Build(1,N-3,1);
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;++i)
		{
			int s,e,val;
			scanf("%d%d%d",&s,&e,&val);
			Seg.Update(1,N-3,1,s+1,e+1,val);
		}
		printf("%d\n",Seg.Query(1,N-3,1,1));

	}
	return 0;
}