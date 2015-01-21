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


LL get_dsum(LL n)
{
    LL sum=0;
    while(n>0)
    {
        sum += n%10;
        n/=10;
    }
    return sum;
}

int main()
{
    LL n;
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld",&n);
        ++n;
        while((get_dsum(n)%10)!=0)++n;
        printf("%lld\n",n);
    }
	return 0;
}
