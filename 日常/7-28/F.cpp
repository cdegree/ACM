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


int main()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;++t)
    {
        LL n;
        scanf("%lld",&n);
        printf("Case %d: ",t);
        LL res = n*(n-1)/2;
        if(res%2==0)
        {
            printf("%lld\n",res/2);
        }
        else
        {
            printf("%lld/%d\n",res,2);
        }
    }

	return 0;
}
