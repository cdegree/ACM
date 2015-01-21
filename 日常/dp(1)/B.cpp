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
const int N = 100005;
int dp[N],pre[N],id[N];
struct person
{
    int s,b,id;
}P[N];
bool cmp(person a,person b)
{
    if(a.s!=b.s)return a.s<b.s;
    return a.b>b.b;
}
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int s,b;
        P[0].s=P[0].b=0;
        for(int i=1; i<=n; i++)
        {
            scanf("%d%d",&P[i].s,&P[i].b);
            P[i].id=i;
        }
        sort(P+1,P+n+1,cmp);
        memset(dp,0,sizeof(dp));
        memset(pre,-1,sizeof(pre));
        int m=0,l,r,mid,ans;
        id[0]=-1;
        for(int i=1; i<=n; i++)
        {
            if(dp[m]<P[i].b)
            {
                pre[i] = id[m] ;
                dp[++m] = P[i].b;
                id[m] = i ;
            }
            else
            {
                l=0,r=m;
                while(l<=r)
                {
                    mid = (l+r)>>1;
                    if(dp[mid]<P[i].b)
                    {
                        ans = mid ;
                        l = mid + 1;
                    }
                    else
                    {
                        r = mid - 1 ;
                    }
                }
                pre[i] = id[ans];
                dp[ans+1] = P[i].b;
                id[ans+1] = i;
            }

        }
        printf("%d\n",m);
        //for(int i=0; i<m; i++)printf("d %d\n",dp[i]);
        int cur = id[m] ;
        while(~cur)
        {
            printf("%d ",P[cur].id);
            cur = pre[cur];
        }
        puts("");
    }
    return 0;
}
