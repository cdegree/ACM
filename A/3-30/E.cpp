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

int main()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        LL a,b,c;

        scanf("%lld%lld%lld",&a,&b,&c);
        printf("Case #%d: ",t);
        if(a==0)
        {
            puts("1");
        }
        else if(a==1&&b==0)
        {
            puts("2");
        }
        else if(a+2*b<3)
        {
            puts("3");
        }
        else if(a+2*b<4)
        {
            puts("4");
        }
        else
        {
            printf("%lld\n",a+b*2+c*5+1);
        }
    }
	return 0;
}
