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
LL m,d,y;
LL year;
LL syear[13];
LL f(LL x)
{
    return (x%12)+1;
}
LL yue[13];
void init()
{
    year=0;
    memset(syear,0,sizeof(syear));
    for(int i=0; i<12; i++)
    {
        for(int j=1; j<=i+1; j++)
        {
            year+=j*j*j;
            syear[i]+=j*j*j;
        }
    }
}
LL ret=0;
LL gao()
{
    ret=0;
    if(y>0)ret +=  y/12 * year;

    if(y>0)ret += y/12;
    y%=12;
    //ggao(1,1,0);
    if(y>=0)
    {
        for(int j=0;j<y;j++)
        ret += syear[j];
    }
    for(int j=1;j<m;j++)
    {
        ret += j*j*j;
    }
    ret += d;
    if(y==11&&m>1)ret++;

    return ret;

}
int main()
{
    init();
    while(~scanf("%lld-%lld-%lld",&m,&d,&y))
    {
        LL st = gao();
        //printf("cnt = %lld\n",st);
        scanf("%lld-%lld-%lld",&m,&d,&y);
        LL ed = gao();
        printf("%lld\n",abs(ed-st)+1);
    }
    return 0;
}
