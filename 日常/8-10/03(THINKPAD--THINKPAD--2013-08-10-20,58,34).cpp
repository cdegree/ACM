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
        val[rt]=0;
        cnt[rt]=R-L+1;
        left[rt]=L,right[rt]=R;
        npd[rt]=0;
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

    }
    void Push_Down(int rt)
    {
        if(npd[rt])
        {
            val[lc]=val[rc]=val[rt];
            val[rt]=npd[rt]=0;
            npd[lc]=npd[rc]=1;
        }
    }
    void Update_op(int L,int R,int rt,int from,int to,int b,int c)
    {
        if((from<=L&&R<=to&&npd[rt])||L==R )
        {
            val[rt] = (val[rt]*b+c)%mod;
            npd[rt]=1;
        }
        else
        {
            int mid = (L+R)>>1;
            Push_Down(rt);
            if(from<=mid)
            {
                Update_op(lson,from,to,b,c);
            }
            if(to>mid)
            {
                Update_op(rson,from,to,b,c);
            }
            Push_Up(rt);
        }
    }
    int Query(int L,int R,int rt,int from,int to,int _p)
    {
        printf("rt=%d %d\n",rt,val[rt]);
        if(npd[rt]||L==R)
        {
            int ret = 1;
            for(int i=0;i<_p;++i){ret*=val[rt];ret%=mod;}
            return ret*cnt[rt]%mod;
        }
        else
        {
            int mid = (L+R)>>1;
            //Push_Down(rt);
            int ret = 0 ;
            printf("%d -> %d  mid = %d\n",L,R,mid);
            if(from<=mid)
            {
                ret += Query(lson,from,to,_p);
            }
            if(to>mid)
            {
                ret += Query(rson,from,to,_p);
            }
            ret %= mod;
            return ret;
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
                Seg.Update_op(1,n,1,x,y,1,c);
            }
            else if(q==2)
            {
                Seg.Update_op(1,n,1,x,y,c,0);
            }
            else if(q==3)
            {
                Seg.Update_op(1,n,1,x,y,0,c);
            }
            else
            {
                int res = Seg.Query(1,n,1,x,y,c);
                printf("%d\n",res);
            }
            for(int i=1;i<4*n;++i)
            {
                printf("%3d:%3d -> %3d\t",i,Seg.left[i],Seg.right[i]);
                printf("npd=%d, val = %d\n",Seg.npd[i],Seg.val[i]);
            }
        }
    }
    return 0;
}
