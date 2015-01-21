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
#define rc rt<<1
#define rc rt<<1|1

struct Segment_Tree
{
    int left[maxn*4],right[maxn*4];
    int p[3][maxn*4];
    int cnt[maxn*4];
    bool npchange[maxn*4],npop[maxn*4];
    int change[maxn*4];
    vector<int> op[maxn*4],val[maxn*4];
    void Build(int L,int R,int rt)
    {
        op[rt].clear();
        val[rt].clear();
        cnt[rt]=R-L+1;
        left[rt]=L,right[rt]=R;
        npchange[rt]=false;
        npop[rt]=false;
        change[rt]=0;
        p[0][rt]=p[1][rt]=p[2][rt]==0;
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
            npchange[lc]=1;
            op[lc].clear();
            val[lc].clear();
            npop[lc]=0;
            change[lc]=change[rt];
            p[0][lc] = cnt[lc]*change[lc]%mod;
            p[1][lc] = change[lc]*change[lc]%mod*cnt[lc]%mod;
            p[2][lc] = change[lc]*change[lc]%mod*cnt[lc]*change[lc]%mod;

            npchange[rc]=1;
            op[rc].clear();
            val[rc].clear();
            npop[rc]=0;
            change[rc]=change[rt];
            p[0][rc] = cnt[rc]*change[rc]%mod;
            p[1][rc] = change[rc]*change[rc]%mod*cnt[rc]%mod;
            p[2][rc] = change[rc]*change[rc]%mod*cnt[rc]*change[rc]%mod;
        }
        if(npop[rt])
        {
            for(int i=0; i<op[rt].size(); ++i)
            {
                int k=op[rt][i];
                int _val=val[rt][i];
                npop[lc]=1;
                op[lc].push_back(k);
                val[lc].push_back(_val);
                if(k==0)
                {
                    p[2][lc] = p[2][lc] + 3*_val*p[1][lc] + 3*_val*_val*p[0][lc] + _val*_val*_val*cnt[lc];
                    p[1][lc] = p[1][lc] + 2*_val*p[0][lc] +_val*_val*cnt[lc];
                    p[0][lc] = p[0][lc] + _val*cnt[lc];
                }
                else
                {
                    p[0][lc] = p[0][lc]*_val%mod;
                    p[1][lc] = p[1][lc]*_val%mod*_val%mod;
                    p[2][lc] = p[2][lc]*_val%mod*_val*_val%mod;
                }

                npop[rc]=1;
                op[rc].push_back(k);
                val[rc].push_back(_val);
                if(k==0)
                {
                    p[2][rc] = p[2][rc] + 3*_val*p[1][rc] + 3*_val*_val*p[0][rc] + _val*_val*_val*cnt[rc];
                    p[1][rc] = p[1][rc] + 2*_val*p[0][rc] +_val*_val*cnt[rc];
                    p[0][rc] = p[0][rc] + _val*cnt[rc];
                }
                else
                {
                    p[0][rc] = p[0][rc]*_val%mod;
                    p[1][rc] = p[1][rc]*_val%mod*_val%mod;
                    p[2][rc] = p[2][rc]*_val%mod*_val*_val%mod;
                }
            }
        }
    }
    void Update_op(int L,int R,int rt,int from,int to,int _val,int k)
    {
        if(from<=L&&R<=to)
        {
            npop[rt]=1;
            op[rt].push_back(k);
            val[rt].push_back(_val);
            if(k==0)
            {
                p[2][rt] = p[2][rt] + 3*_val*p[1][rt] + 3*_val*_val*p[0][rt] + _val*_val*_val*cnt[rt];
                p[1][rt] = p[1][rt] + 2*_val*p[0][rt] +_val*_val*cnt[rt];
                p[0][rt] = p[0][rt] + _val*cnt[rt];
            }
            else
            {
                p[0][rt] = p[0][rt]*_val%mod;
                p[1][rt] = p[1][rt]*_val%mod*_val%mod;
                p[2][rt] = p[2][rt]*_val%mod*_val*_val%mod;
            }
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
            op[rt].clear();
            val[rt].clear();
            npop[rt]=0;
            change[rt]=_val;
            p[0][rt] = cnt[rt]*_val%mod;
            p[1][rt] = _val*_val%mod*cnt[rt]%mod;
            p[2][rt] = _val*_val%mod*cnt[rt]*_val%mod;
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
        }
    }

} Seg;

int main()
{
    return 0;
}
