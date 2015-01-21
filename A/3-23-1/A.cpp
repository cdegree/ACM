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

const int N = 10005;
int n,k;
int a[N];
bool judge(int sc)
{
    int sum = 0 ;
    int cnt = 1 ;
    for(int i=0;i<n;i++)
    {
        if(sum+a[i]<=sc)
        {
            sum += a[i];
        }
        else
        {
            cnt++;
            sum = a[i] ;
        }
    }
    return cnt<=k;
}
int main()
{
    while(true)
    {
        scanf("%d %d",&n,&k);
        if(n==0&&k==0)break;
        int mx = -1;
        for(int i=0;i<n;i++){scanf("%d",a+i);mx=max(mx,a[i]);}


        int l = mx,r = 1e9,mid,res;
        while(l<=r)
        {
            mid = (l+r)/2;
            //printf("%d \n",mid);
            if(judge(mid))
            {
                res = mid ;
                r = mid - 1;
            }
            else
            {
                l = mid + 1 ;
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
