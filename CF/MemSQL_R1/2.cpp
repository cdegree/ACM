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
LL get_res(LL m)
{
    LL ret=0;
    while(m%2==0)
    {
        ret += m/2;
        m/=2;
    }
    ret += m*(m-1)/2;
    return ret;
}
int main()
{
    LL n,m;
    freopen("out.txt","w",stdout);
    m=1000;
    for(LL i = 1;i<=m;++i)
    {
        printf("%10lld : %10lld\n",i,get_res(i));
    }
	return 0;
}
