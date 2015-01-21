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
int dp[N];
struct doll
{
    int w,h;
} D[N];
bool cmp(doll a,doll b)
{
    if(a.w!=b.w)return a.w>b.w;
    return a.h<b.h;
}
int add[N];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
        {
            scanf("%d %d",&D[i].w,&D[i].h);
        }
        D[0].h=0;
        sort(D+1,D+1+n,cmp);
        memset(add,0,sizeof(add));
        int l,r,mid,m=0,ans;
        dp[0]=0;
        int res=1;
        for(int i=1; i<=n; i++)
        {
            l=0,r=m;
            while(l<=r)
            {
                mid = (l+r)>>1;
                if(dp[mid]<=D[i].h)
                {
                    ans = mid ;
                    l = mid + 1 ;
                }
                else
                {
                    r = mid - 1 ;
                }
            }
            dp[ans+1]=D[i].h;
            if(ans==m) ++m;
        }
        printf("%d\n",m);
    }
    return 0;
}
