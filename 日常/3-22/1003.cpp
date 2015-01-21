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

using namespace std;

typedef long long LL ;
int len[202];
int a[202];
int va[202],vb[202];
int n;
int dp[202];
int gao(int l,int r,int val)
{
    int len1=0,len2=0;
    for(int i=1;i<l;++i)
    {
        va[++len1]=a[i];
    }
    for(int i=n;i>r;--i)
    {
        vb[++len2]=a[i];
    }
    memset(dp,-1,sizeof(dp));
    dp[0]=0;
    int idx=0;
    vb[0]=0;
    for(int i=1;i<=len1;i++)
    {
        int k = 0;
        for(int j=1;j<=len2;j++)
        {
            if(va[i]==vb[j])
            {
                if(dp[j]<dp[k]+1)
                {
                    dp[j]=dp[k]+1;
                }
            }
            if(va[i]>vb[j])
            {
                if(dp[j]>dp[k])
                {
                    k=j;
                }
            }
        }
    }
    int ret = r-l+1;
    for(int i=1;i<=len2;i++)
    {
        int add = 0;
        if(a[n-i+1]<a[l])add=r-l+1;
        ret = max(ret,dp[i]*2+add);
    }
    //printf("from %d to %d : idx = %d %d \n",l,r,idx,dp[idx]);
    return  ret;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",a+i);
        int res = 0;
        for(int i=1;i<=n;i++)
        {
            res = max(res,gao(i,i,a[i]));
            if(i+1<=n&&a[i]==a[i+1])res = max(res,gao(i,i+1,a[i]));
        }
        printf("%d\n",res);
    }
	return 0;
}
