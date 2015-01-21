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

LL a[22],b[555];
LL inf = 1000000000000000000LL;
LL dfs(int u,int n,LL g,LL m,LL *r)
{
    LL ret=0;
    for(int i=u; i<n; ++i)
    {
        LL gcd = __gcd(g,r[i]);
        LL lcm ;
        if(g/gcd*r[i]>inf/r[i])
        {
            lcm=m+1;
        }
        else lcm=g/gcd*r[i];
        ret += m/lcm - dfs(i+1,n,lcm,m,r);
    }
    return ret;
}
LL get_ans(int n,LL m,LL *r)
{
    if(m==0)return 0;
    LL ret=0;
    for(int i=0; i<n; ++i)
    {
        ret += m/r[i] - dfs(i+1,n,r[i],m,r);
    }
    return ret;
}
int main()
{
    while(1)
    {
        LL n1,n2,l,r;
        scanf("%lld%lld%lld%lld",&n1,&n2,&l,&r);
        if(n1==0&&n2==0&&l==0&&r==0)break;
        for(int i=0; i<n1; ++i)scanf("%lld",a+i);
        LL g = 1;
        for(int i=0; i<n2; ++i)
        {
            scanf("%lld",b+i);
            LL gcd = __gcd(g,b[i]);
            if(g/gcd>inf/b[i])
            {
                g=r+1;
                //puts("f");
            }
            else g = g/gcd*b[i];
        }
        LL res = get_ans(n1,r,a) - get_ans(n1,l-1,a);
        //printf("res = %lld\n",res);
        for(int i=0; i<n1; ++i)
        {
            LL gcd = __gcd(a[i],g);
            if(a[i]/gcd > inf/g)
            {
                a[i]=r+1;
                //puts("f");
            }
            else a[i]=a[i]/gcd*g;
            //printf("a[%d]=%d\n",i,a[i]);
        }
        //printf("p = %lld\n",g);
        res =res - get_ans(n1,r,a) + get_ans(n1,l-1,a);
        printf("%lld\n",res);
    }
    return 0;
}
