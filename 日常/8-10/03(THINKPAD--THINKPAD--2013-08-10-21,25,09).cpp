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

const int maxn = 100005;
const int mod = 10007;

#define lson L , mid , rt << 1
#define rson mid + 1 , R , rt << 1 | 1
#define lc rt<<1
#define rc rt<<1|1

struct Segment_Tree
{
    int left[maxn*4],right[maxn*4];
    int val[maxn*4],cnt[maxn*4];
    bool npd[maxn*4];
    void Build(int L,int R,int rt)
    {
        val[rt]=-1;
        cnt[rt]=R-L+1;
        left[rt]=L,right[rt]=R;
        //npd[rt]=0;
        if(L==R)
        {
            //npd[rt]=1;
        }
        else
        {
            int mid = (L+R)>>1;
            Build(lson);
            Build(rson);
            //Push_Up(rt);
        }
    }
    void Push_Up(int rt)
    {

    }
    inline void Push_Down(int rt)
    {
        if(~val[rt])
        {
            val[lc]=val[rc]=val[rt];
            val[rt]=-1;
            //npd[lc]=npd[rc]=1;
        }
    }
    void Update_op1(int rt,int from,int to,int b,int c)
    {
        if(from<=left[rt]&&right[rt]<=to&&val[rt]!=-1)
        {
            val[rt] = (val[rt]+c)%mod;
        }
        else
        {
            int mid = (left[rt]+right[rt])>>1;
            Push_Down(rt);
            if(from<=mid)
            {
                Update_op1(lc,from,to,b,c);
            }
            if(to>mid)
            {
                Update_op1(rc,from,to,b,c);
            }
            //Push_Up(rt);
        }
    }
    void Update_op2(int rt,int from,int to,int b,int c)
    {
        if(from<=left[rt]&&right[rt]<=to&&val[rt]!=-1)
        {
            val[rt] = (val[rt]*b)%mod;
        }
        else
        {
            int mid = (left[rt]+right[rt])>>1;
            Push_Down(rt);
            if(from<=mid)
            {
                Update_op2(lc,from,to,b,c);
            }
            if(to>mid)
            {
                Update_op2(rc,from,to,b,c);
            }
            //Push_Up(rt);
        }
    }
    void Update_op3(int rt,int from,int to,int b,int c)
    {
        if(from<=left[rt]&&right[rt]<=to)
        {
            val[rt] = c;
        }
        else
        {
            int mid = (left[rt]+right[rt])>>1;
            Push_Down(rt);
            if(from<=mid)
            {
                Update_op3(lc,from,to,b,c);
            }
            if(to>mid)
            {
                Update_op3(rc,from,to,b,c);
            }
            //Push_Up(rt);
        }
    }
    int Query(int rt,int from,int to,int _p)
    {
        //printf("rt=%d %d\n",rt,val[rt]);
        if(~val[rt])
        {
            LL ret = 1;
            for(int i=0; i<_p; ++i)ret*=val[rt];
            return (int)ret*cnt[rt]%mod;
        }
        else
        {
            int mid = (left[rt]+right[rt])>>1;
            //Push_Down(rt);
            //printf("%d -> %d  mid = %d\n",L,R,mid);
            if(from>mid)
            {
                return Query(rc,from,to,_p);
            }
            else if(to<=mid)
            {
                return Query(lc,from,to,_p);
            }
            else
            {
                return Query(lc,from,mid,_p)+Query(rc,mid+1,to,_p);
            }
        }
    }
} Seg;

int main()
{
    int n,m;
    while(1)
    {
        scanf("%d%d",&n,&m);
        if(n==0&&m==0)break;
        Seg.Build(1,n,1);
        int q,x,y,c;
        while(m--)
        {
            scanf("%d %d %d %d",&q,&x,&y,&c);
            if(q==1)
            {
                Seg.Update_op1(1,x,y,1,c);
            }
            else if(q==2)
            {
                Seg.Update_op2(1,x,y,c,0);
            }
            else if(q==3)
            {
                Seg.Update_op3(1,x,y,0,c);
            }
            else
            {
                int res = Seg.Query(1,x,y,c)%mod;
                printf("%d\n",res);
            }
        }
    }
    return 0;
}
