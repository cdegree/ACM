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
int a[N];

int up[N],down[N];
int dp[N];

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
        {
            scanf("%d",a+i);
        }
        int len=0;
        dp[0]=-1;
        dp[++len]=a[n];
        up[n]=1;
        for(int i=n-1;i>=1;--i)
        {
            int b = a[i];
            int l=0,r=len,mid,ans;
            while(l<=r)
            {
                mid = (l+r)/2;
                if(dp[mid]<=b)
                {
                    ans = mid;
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
            //printf("ans = %d\n",ans);
            ++ans;
            dp[ans]=b;
            if(ans-1==len)++len;
            l=1,r=len,mid,ans=-1;
            while(l<=r)
            {
                mid = (l+r)/2;
                //printf("%d -> %d  mid = %d\n",l,r,mid);
                if(dp[mid]==b)
                {
                    //puts("ok");
                    ans = mid;
                    r = mid - 1;
                }
                else if(dp[mid]<b)
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
            //printf("b = %d up[%d]=%d  dp = %d\n",b,i,mid,dp[mid]);
            if(~ans)up[i]=ans;
            else while(1);
        }
        len=0;
        dp[0]=1e9+9;
        down[n]=1;
        dp[++len]=a[n];
        for(int i=n-1;i>=1;--i)
        {
            int b = a[i];
            int l=0,r=len,mid,ans;
            while(l<=r)
            {
                mid = (l+r)/2;
                if(dp[mid]>=b)
                {
                    ans = mid;
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
            //printf("ans = %d\n",ans);
            ++ans;
            dp[ans]=b;
            if(ans-1==len)++len;
            down[i]=ans;
        }
//        for(int i=1;i<=n;++i)
//        {
//            printf("%d ",up [i]);
//        }
//        puts("");
//        for(int i=1;i<=n;++i)
//        {
//            printf("%d ",down[i]);
//        }
//        puts("");
        int res=1;
        for(int i=1;i<=n;++i)
        {
            res = max(res,up[i]+down[i]-1);
        }
        printf("%d\n",res);
    }
	return 0;
}
