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
const int maxn = 50005;

#define lson L , mid , rt << 1
#define rson mid + 1 , R , rt << 1 | 1
#define lc rt<<1
#define rc rt<<1|1


struct Segment_Tree
{
	int mxempty[maxn*4],Lempty[maxn*4],Rempty[maxn*4];
	bool occupied[maxn*4];
	bool npd[maxn*4];
	int len[maxn*4];
	int left[maxn*4],right[maxn*4];
	inline void init(int N)
	{
		Build(1,N,1);
	}
	void Build(int L,int R,int rt)
	{
		Lempty[rt] = Rempty[rt] = mxempty[rt]=R-L+1;
		len[rt]=R-L+1;
		left[rt]=L,right[rt]=R;
		occupied[rt]=false;
		npd[rt]=false;
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
		Lempty[rt] = Lempty[lc];
		if(Lempty[lc]==len[lc])
		{
			Lempty[rt] += Lempty[rc];
		}

		Rempty[rt] = Rempty[rc];
		if(Rempty[rc]==len[rc])
		{
			Rempty[rt] += Rempty[lc];
		}

		mxempty[rt] = max(mxempty[lc],mxempty[rc]);
		mxempty[rt] = max(mxempty[rt],Rempty[lc]+Lempty[rc]);
	}
	void Push_Down(int rt)
	{
		if(npd[rt])
		{
			occupied[lc] = occupied[rc] = occupied[rt];
			Lempty[lc] = Rempty[lc] = mxempty[lc] = (occupied[lc]^1)*len[lc];
			Lempty[rc] = Rempty[rc] = mxempty[rc] = (occupied[rc]^1)*len[rc];

			npd[lc] = npd[rc] = true;
			npd[rt] = false;
		}
	}
	void Update(int L,int R,int rt,int from,int to,int check_in)
	{
	    if(from<=L&&R<=to)
		{
			occupied[rt] = check_in;
			Lempty[rt] = Rempty[rt] = mxempty[rt] = (check_in^1)*len[rt];
			npd[rt]=true;
			//printf("from %d to %d\n rt.L = %d rt.R = %d \n",L,R,Lempty[rt], Rempty[rt]);
			//printf("lc.L = %d lc.R = %d\t rc.L = %d rc.R = %d\n",Lempty[lc],Rempty[lc],Lempty[rc],Rempty[rc]);
		}
		else
		{
			int mid = (L+R)>>1;
			Push_Down(rt);
			if(from<=mid)
			{
				Update(lson,from,to,check_in);
			}
			if(to>mid)
			{
				Update(rson,from,to,check_in);
			}
			Push_Up(rt);
			//printf("from %d to %d\n rt.L = %d ,rt.R = %d \n",L,R,Lempty[rt], Rempty[rt]);
			//printf("lc.L = %d lc.R = %d\t rc.L = %d rc.R = %d\n",Lempty[lc],Rempty[lc],Lempty[rc],Rempty[rc]);
		}
	}
	int Query(int L,int R,int rt,int len)
	{
		if(mxempty[rt]<len)
		{
			return 0;
		}
		else
		{
			//printf("len  = %d, from %d to %d\n rt.L = %d rt.M = %d,rt.R = %d \n",len,L,R,Lempty[rt],Midempty[rt], Rempty[rt]);
			//printf("lc.L = %d lc.R = %d\t rc.L = %d rc.R = %d\n",Lempty[lc],Rempty[lc],Lempty[rc],Rempty[rc]);
			int mid = (L+R)>>1;
			Push_Down(rt);
			int ans;
			if(Lempty[rt]>=len)
			{
				ans = L;
			}
			else if(mxempty[lc] >= len)
			{
				ans = Query( lson, len );
			}
			else if( Rempty[lc]+Lempty[rc] >= len 
				//&& Rempty[lc]>0    
				//加这句在CDOJ会WA,在POJ上AC
				)
			{
				ans = right[lc] - Rempty[lc] + 1;
			}
			else
			{
				ans = Query( rson, len);
			}
			return ans;
		}
	}
}Seg;

int main(int argc, char const *argv[])
{
	int n,m;
	//freopen("Ain.txt","r",stdin);
	while(~scanf("%d%d",&n,&m))
	{
		Seg.Build(1,n,1);
		while(m--)
		{
			int D,X,t;
			scanf("%d",&t);
			if(t==1)
			{
				scanf("%d",&D);
				//printf("ask for %d\n",D );
				int pos = Seg.Query(1,n,1,D);
				printf("%d\n",pos );
				if(pos!=0)
				{
					Seg.Update(1,n,1,pos,min(n,pos+D-1),1);
				}
			}
			else
			{
				scanf("%d%d",&X,&D);
				//printf("out %d from %d to %d\n",1,X,min(X+D-1,n));
				Seg.Update(1,n,1,X,min(X+D-1,n),0);

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
