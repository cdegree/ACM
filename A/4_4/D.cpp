#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#include <iostream>
#include <cmath>

using namespace std;
struct Point
{
    int t,s;
}p[100010];
bool cmp(const Point &A,const Point &B)
{
    return A.s*B.t>B.s*A.t;
}
int main()
{

    freopen("Din.txt","r",stdin);
    int n,T;
    while(scanf("%d%d",&n,&T)!=EOF)
    {
        for(int i=1;i<=n;i++)
            scanf("%d%d",&p[i].t,&p[i].s);
        sort(p+1,p+1+n,cmp);
        long long ans=0;
        for(int i=1;i<=n;i++)
        {
            if(T>=p[i].t)
            {
                ans+=p[i].s*T;
                T-=p[i].t;
            }
        }
        printf("%lld\n",ans);
    }

}