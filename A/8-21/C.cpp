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
    LL A,B,C;
    while(~scanf("%I64d%I64d%I64d",&A,&B,&C))
    {
        LL x = 1;
        int id=0;
        while(id+1<2000000)
        {
            ++id;
           x = (x*A+x%B)%C;
            //if(id<20)printf("x[%d]=%lld\n",id,x);
        }
        int pid=id;
        LL f = x;
       //printf("%lld\n",f);
        x = 1;
        id=0;
        LL len = -1 ;
        while(id+1<1999999&&x!=f)
        {
            ++id;
            x = (x*A+x%B)%C;
        }
        if(x==f)
        {
            //printf("id=%d\n",id);
            len = pid-id;
            //printf("len = %lld\n",len);
            int yid=0;
            LL y = 1;
            x=1;
            id=0;
            while(len--)
            {
                y = (y*A+y%B)%C;
            }
            //printf("y=%lld\n",y);
            while(x!=y)
            {
                ++id;
                x = (x*A+x%B)%C;y = (y*A+y%B)%C;
            }
            pid=id;
            //printf("pid=%d\n",pid);
            x = (x*A+x%B)%C;
            ++id;
            while(x!=y)
            {
                ++id;
                x = (x*A+x%B)%C;
            }
            printf("%d\n",id);
        }
        else
        {
            puts("-1");
        }
    }
	return 0;
}
