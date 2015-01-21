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

const int maxn = 3000005;

#define lson L , mid , rt << 1
#define rson mid + 1 , R , rt << 1 | 1
#define lc rt<<1
#define rc rt<<1|1

struct Segment_Tree
{
    int sum[maxn*4];
	int left[maxn*4],right[maxn*4];
	void Build(int L,int R,int rt)
	{
		left[rt]=L,right[rt]=R;
		if(L==R)
		{
			sum[rt]=1;
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
	    sum[rt] = sum[lc] + sum[rc];
	}
	void Push_Down(int rt)
	{
	}
	void Update(int L,int R,int rt,int pos)
	{
		if(pos==L&&R==pos)
		{
            sum[rt]=0;
		}
		else
		{
			int mid = (L+R)>>1;
			//Push_Down(rt);
			if(pos<=mid)
			{
				Update(lson,pos);
			}
			if(pos>mid)
			{
				Update(rson,pos);
			}
			Push_Up(rt);
		}
	}
	int Query(int L,int R,int rt,int from,int to)
	{
		if(from<=L&&R<=to)
		{
            return sum[rt];
		}
		else
		{
			int mid = (L+R)>>1;
			//Push_Down(rt);
			int ret =0;
			if(from<=mid)
			{
				ret += Query(lson,from,to);
			}
			if(to>mid)
			{
				ret += Query(rson,from,to);
			}
			return ret;
		}
	}
}Seg;

int order[maxn],back[maxn];
int n,k,q;
int Query(int st,int ccnt)
{
    int L=st,R=n,mid,ans=-1;
    while(L<=R)
    {
        mid = (L+R)>>1;
        //printf("%d  ==%d\n",mid,Seg.Query(1,n,1,L,R));
        if(Seg.Query(1,n,1,st,mid)>=ccnt)
        {
            ans = mid;
            R = mid - 1;
        }
        else
        {
            L = mid + 1;
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
	while(~scanf("%d%d%d",&n,&k,&q))
	{
	    Seg.Build(1,n,1);
	    int cnt=1;
	    while(Seg.Query(1,n,1,1,n)>0)
	    {
	        int pos = Query(1,1);
	        //printf("pos = %d\n",pos);
	        order[pos]=cnt++;
	        //printf("pos = %d,cnt = %d\n",pos,cnt-1);
	        Seg.Update(1,n,1,pos);
	        while(~(pos = Query(pos+1,k)))
	        {
	            order[pos]=cnt++;
	            //printf("pos = %d,cnt = %d\n",pos,cnt-1);
                Seg.Update(1,n,1,pos);
                //if(cnt>n)break;
                //printf("ined\n");
	        }
	        //if(cnt>n)break;
	    }

	    int val;
        for(int i=0;i<q;++i)
        {
            scanf("%d",&val);
            printf("%d\n",order[val]);
        }

	}
	return 0;
}
