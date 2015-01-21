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
LL b[N];
const LL mx = 200000000000LL;
bool ok(LL n)
{
    if(n==2)return true;
    for(LL i=2;i*i<=n;i++)
    {
        if(n%i==0)
        return false;
    }
    return true;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)scanf("%lld",b+i);

        sort(b,b+n);
        printf("Case #%d: ",t);
        if(n==1)
        {
            printf("Good Function\n");
            continue;
        }
        LL sum =1;
        LL mmx = 1;
        for(int i=0;i<n;i++)
        {
            sum *=b[i];
            mmx = max(mmx,b[i]);
            sum = min(sum,mx);
        }
        if(b[n-2]==1)
        {
            printf("Good Function\n");
            continue;
        }
        LL res = mmx+1;
        while(!ok(res))
        {
            res++;
        }
        if(res>sum)
        {
            printf("Good Function\n");
            continue;
        }
        printf("%lld\n",res);
    }
	return 0;
}
