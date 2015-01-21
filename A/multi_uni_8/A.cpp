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

int a[20002];
LL presum[20002];
int main()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;++t)
    {
        int n,q;
        scanf("%d",&n);
        for(int i=1;i<=n;++i)scanf("%d",a+i);
        scanf("%d",&q);
        printf("Case #%d:\n",t);
        while(q--)
        {
           int l,r;
           scanf("%d%d",&l,&r);
           LL res=0;
           for(int i=l;i<=r;++i)for(int j=i+1;j<=r;++j)res+=__gcd(a[i],a[j]);
           printf("%I64d\n",res);
        }
    }
	return 0;
}
