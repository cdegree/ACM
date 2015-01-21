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
using namespace std;

typedef long long LL ;
const int N = 20005;
struct Point
{
    LL x,y;
} P[N],Q[N];
struct Square
{
    Point sw;
    LL d;
} S[4];
int n;
LL inf = 20000000000LL;
bool In(int id,int p,LL mid)
{
    return (
            S[id].sw.x<=P[p].x&&
            S[id].sw.y<=P[p].y&&
            S[id].sw.x+mid>=P[p].x&&
            S[id].sw.y+mid>=P[p].y
            );
}
bool OK;
void gao(vector<bool> _cover,int u,LL mid)
{
    if(OK)return ;
    if(u==3)
    {
        for(int i=0; i<n; ++i)
        {
            if(!_cover[i])
            {
                OK=false;
                return ;
                //printf("%d: %lld %lld\n",i,P[i].x,P[i].y);
            }
        }
        OK=true;
        return ;
    }
    else
    {
        vector<bool> cover;
        for(int i=0; i<n; ++i)
        {
            cover.push_back(false);
        }
        for(int i=0; i<n; ++i)
        {
            cover[i]=_cover[i];
        }
        LL lowy=inf,upy=-inf,leftx=inf,rightx=-inf;
        for(int i=0; i<n; ++i)
        {
            if(!cover[i])
            {
                //printf(":%d   %lld %lld\n",i,P[i].x,P[i].y);
                lowy=min(lowy,P[i].y);
                upy=max(upy,P[i].y);
                leftx=min(leftx,P[i].x);
                rightx=max(rightx,P[i].x);
            }
        }
        //if(mid==3)printf("lowy=%lld\tupy=%lld\tleftx=%lld\trightx=%lld\n",lowy,upy,leftx,rightx);
        S[u].sw.x=leftx;
        S[u].sw.y=lowy;
        for(int i=0; i<n; ++i)
        {
            if(!cover[i]&&In(u,i,mid))
            {
                cover[i]=true;
            }
        }
        gao(cover,u+1,mid);
        if(OK)return ;
        for(int i=0; i<n; ++i)
        {
            cover[i]=_cover[i];
        }
        S[u].sw.x=rightx-mid;
        S[u].sw.y=lowy;
        for(int i=0; i<n; ++i)
        {
            if(!cover[i]&&In(u,i,mid))
            {
                cover[i]=true;
            }
        }
        gao(cover,u+1,mid);
        if(OK)return;
        for(int i=0; i<n; ++i)
        {
            cover[i]=_cover[i];
        }
        S[u].sw.x=leftx;
        S[u].sw.y=upy-mid;
        for(int i=0; i<n; ++i)
        {
            if(!cover[i]&&In(u,i,mid))
            {
                cover[i]=true;
            }
        }
        gao(cover,u+1,mid);
        if(OK)return ;
        for(int i=0; i<n; ++i)
        {
            cover[i]=_cover[i];
        }
        S[u].sw.x=rightx-mid;
        S[u].sw.y=upy-mid;
        for(int i=0; i<n; ++i)
        {
            if(!cover[i]&&In(u,i,mid))
            {
                cover[i]=true;
            }
        }
        gao(cover,u+1,mid);
    }
}


bool judge(LL m)
{
    OK=false;
    //printf("len = %lld\n",m);
    vector<bool> cover;
    for(int i=0; i<n; ++i)
    {
        cover.push_back(false);
    }
    gao(cover,0,m);
    return OK;
}
int main()
{
    freopen("Din.txt","r",stdin);
    //freopen("Dout.txt","w",stdout);
    while(~scanf("%d",&n))
    {
        for(int i=0; i<n; ++i)
        {
            scanf("%I64d%I64d",&P[i].x,&P[i].y);
        }
        LL l=1,r=10000000000LL,mid,ans=-1;
        while(l<=r)
        {
            mid = (l+r)/2;
            if(judge(mid))
            {
                ans = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
