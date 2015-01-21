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

LL get_cut(LL n)
{
    LL x=0;
    while( (1<<x)<n  )++x;
    return x;
}
int main()
{
    LL N,M,K;
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;++t)
    {
        scanf("%I64d%I64d%I64d",&N,&M,&K);
        LL res = 0 ;
        res = get_cut(N)+get_cut(M)+get_cut(K);
        printf("Case #%d: %I64d %I64d\n",t,N*M*K-1,res);
    }
	return 0;
}
