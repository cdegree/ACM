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
#define sqr(x) (x)*(x)
using namespace std;
const double PI = acos(-1.0);
map<int,int>::iterator it;
typedef long long LL ;
#pragma comment(linker,"/STACK:102400000,102400000")

int n,m;
const int maxn = 131074;

#define lson L , mid , rt << 1
#define rson mid + 1 , R , rt << 1 | 1
#define lc rt<<1
#define rc rt<<1|1

int a[maxn];
struct Segment_Tree
{
	int left[maxn*4],right[maxn*4];
	int val[maxn*4];
	int dep[maxn*4];
	void Build(int L,int R,int rt)
	{
		left[rt]=L,right[rt]=R;
		if(L==R)
		{
		    dep[rt]=1;
			val[rt]=a[L];
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
	    dep[rt]=dep[lc]+1;
	    if(dep[rt]&1)
	    {
	        val[rt]=val[lc]^val[rc];
	    }
	    else
	    {
	        val[rt]=val[lc]|val[rc];
	    }
	}
	void Update(int L,int R,int rt,int pos,int b)
	{
		if(pos==L&&pos==R)
		{
		    val[rt]=b;
		}
		else
		{
			int mid = (L+R)>>1;
			//Push_Down(rt);
			if(pos<=mid)
			{
				Update(lson,pos,b);
			}
			else if(pos>mid)
			{
				Update(rson,pos,b);
			}
			Push_Up(rt);
		}
	}
	int Query()
	{
		return val[1];
	}

}Seg;

int main()
{
    while(cin>>n>>m)
    {
        int p,b,q;
        q = 1<<n;
        for(int i=1;i<=q;++i)cin>>a[i];
        Seg.Build(1,q,1);
        //printf("%d\n",Seg.Query());
        while(m--)
        {
            scanf("%d%d",&p,&b);
            Seg.Update(1,q,1,p,b);
            printf("%d\n",Seg.Query());
        }
    }
	return 0;
}
