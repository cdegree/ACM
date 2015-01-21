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
const int N  = 10005;
int n,x;
bool dp[N];
int a[202];
bool Can(int y)
{
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for(int i=0;i<n;++i)
    {
        int c=a[i];
        if(i==y)
        {
            continue;
        }
        for(int j=x;j>=c;--j)
        {
            if(dp[j-c])
            {
                dp[j]=1;
            }
        }
    }
    return dp[x];
}
vector<int> gao()
{
    vector<int> ret;
    ret.clear();
    for(int i=0;i<n;++i)
    {
        if(!Can(i))
        {
            ret.push_back(a[i]);
        }
    }
    return ret;
}
int main()
{
    while(~scanf("%d%d",&n,&x))
    {
        for(int i=0;i<n;++i)
        {
            scanf("%d",a+i);
        }
        vector<int> res = gao();
        int len = res.size();
        printf("%d\n",len);
        for(int i=0;i<len;++i)
        {
            printf("%d%c",res[i],i==len-1?'\n':' ');
        }
    }
	return 0;
}
