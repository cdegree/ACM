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
    int p[3][maxn*4];
    int cnt[maxn*4];
    bool npchange[maxn*4],npop[maxn*4];
    int change[maxn*4];
    int add[maxn*4],mul[maxn*4];
    void Build(int L,int R,int rt)
    {
        add[rt]=0;
        mul[rt]=1;
        cnt[rt]=R-L+1;
        left[rt]=L,right[rt]=R;
        npchange[rt]=false;
        npop[rt]=false;
        change[rt]=0;
        p[0][rt]=p[1][rt]=p[2][rt]=0;
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
        for(int i=0; i<3; ++i)p[i][rt] = (p[i][lc]+p[i][rc])%mod;
    }
    void Push_Down(int rt)
    {
        if(npchange[rt])
        {
            npchange[rt]=0;
            int c = change[rt];

            npchange[lc]=1;
            npop[lc]=0;
            add[lc]=0;
            mul[lc]=1;
            change[lc]=c;
            p[0][lc] = cnt[lc]*c%mod;
            p[1][lc] = c*c%mod*cnt[lc]%mod;
            p[2][lc] = c*c%mod*cnt[lc]*c%mod;
            p[0][lc] %= mod;
            p[1][lc] %= mod;
            p[2][lc] %= mod;

            npchange[rc]=1;
            npop[rc]=0;
            add[rc]=0;
            mul[rc]=1;
            change[rc]=change[rt];
            p[0][rc] = cnt[rc]*change[rc]%mod;
            p[1][rc] = c*c%mod*cnt[rc]%mod;
            p[2][rc] = c*c%mod*cnt[rc]*c%mod;
            p[0][rc] %= mod;
            p[1][rc] %= mod;
            p[2][rc] %= mod;
        }
        if(npop[rt])
        {
            npop[rt]=0;
            npop[lc]=1;
            npop[rc]=1;
            int c = add[rt];
            int b = mul[rt];
            add[rt]=0;
            mul[rt]=1;

            add[lc] *= b;
            mul[lc] *= b;
            add[lc] += c;

            add[lc] %= mod;
            mul[lc] %= mod;

            p[2][lc] = (b*b%mod*b*p[2][lc]%mod + 3*b*b%mod*c*p[1][lc]%mod + 3*b*c%mod*c*p[0][lc]%mod + c*c%mod*c*cnt[lc]%mod)%mod;
            p[1][lc] = (b*b%mod*p[1][lc]%mod + 2*b*c%mod*p[0][lc]%mod + c*c%mod*cnt[lc]%mod)%mod;
            p[0][lc] = (p[0][lc]*b%mod + c*cnt[lc]%mod)%mod;

            p[0][lc] %= mod;
            p[1][lc] %= mod;
            p[2][lc] %= mod;


            add[rc] *= b;
            mul[rc] *= b;
            add[rc] += c;

            add[rc] %= mod;
            mul[rc] %= mod;

            p[2][rc] = (b*b%mod*b*p[2][rc]%mod + 3*b*b%mod*c*p[1][rc]%mod + 3*b*c%mod*c*p[0][rc]%mod + c*c%mod*c*cnt[rc]%mod)%mod;
            p[1][rc] = (b*b%mod*p[1][rc]%mod + 2*b*c%mod*p[0][rc]%mod + c*c%mod*cnt[rc]%mod)%mod;
            p[0][rc] = (p[0][rc]*b%mod + c*cnt[rc]%mod)%mod;

            p[0][rc] %= mod;
            p[1][rc] %= mod;
            p[2][rc] %= mod;

        }
    }
    void Update_op(int L,int R,int rt,int from,int to,int _val,int k)
    {
        if(from<=L&&R<=to)
        {
            npop[rt]=1;
            if(k==0)
            {
                add[rt] += _val;
                add[rt] %= mod;
                p[2][rt] = p[2][rt] + 3*_val*p[1][rt]%mod + 3*_val*_val*p[0][rt] + _val*_val%mod*_val*cnt[rt]%mod;
                p[1][rt] = p[1][rt] + 2*_val*p[0][rt]%mod +_val*_val%mod*cnt[rt]%mod;
                p[0][rt] = p[0][rt] + _val*cnt[rt]%mod;
            }
            else
            {
                mul[rt] *= _val;
                add[rt] *= _val;
                add[rt] %= mod;
                mul[rt] %= mod;
                p[0][rt] = p[0][rt]*_val%mod;
                p[1][rt] = p[1][rt]*_val%mod*_val%mod;
                p[2][rt] = p[2][rt]*_val%mod*_val*_val%mod;
            }


            p[0][rt] %= mod;
            p[1][rt] %= mod;
            p[2][rt] %= mod;
        }
        else
        {
            int mid = (L+R)>>1;
            Push_Down(rt);
            if(from<=mid)
            {
                Update_op(lson,from,to,_val,k);
            }
            if(to>mid)
            {
                Update_op(rson,from,to,_val,k);
            }
            Push_Up(rt);
        }
    }

    void Update_change(int L,int R,int rt,int from,int to,int _val)
    {
        if(from<=L&&R<=to)
        {
            npchange[rt]=1;
            npop[rt]=0;
            add[rt]=0;
            mul[rt]=1;
            change[rt]=_val;
            p[0][rt] = cnt[rt]*_val%mod;
            p[1][rt] = _val*_val%mod*cnt[rt]%mod;
            p[2][rt] = _val*_val%mod*cnt[rt]*_val%mod;
            p[0][rt] %= mod;
            p[1][rt] %= mod;
            p[2][rt] %= mod;
        }
        else
        {
            int mid = (L+R)>>1;
            Push_Down(rt);
            if(from<=mid)
            {
                Update_change(lson,from,to,_val);
            }
            if(to>mid)
            {
                Update_change(rson,from,to,_val);
            }
            Push_Up(rt);
        }
    }
    int Query(int L,int R,int rt,int from,int to,int _p)
    {
        if(from<=L&&R<=to)
        {
            return p[_p][rt];
        }
        else
        {
            int mid = (L+R)>>1;
            Push_Down(rt);
            int ret = 0 ;
            if(from<=mid)
            {
                ret += Query(lson,from,to,_p);
            }
            if(to>mid)
            {
                ret += Query(rson,from,to,_p);
            }
            Push_Up(rt);
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
                Seg.Update_op(1,n,1,x,y,c,0);
            }
            else if(q==2)
            {
                Seg.Update_op(1,n,1,x,y,c,1);
            }
            else if(q==3)
            {
                Seg.Update_change(1,n,1,x,y,c);
            }
            else
            {
                int res = Seg.Query(1,n,1,x,y,c-1);
                printf("%d\n",res);
            }
        }
    }
    return 0;
}
