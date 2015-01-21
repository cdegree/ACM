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


int id[1000];
int get_dis(int x1,int y1,int x2,int y2)
{
    return abs(x1-x2)+abs(y1-y2);
}
int cnt1[100],cnt2[100];
const LL mod = 1000000007LL;
const LL MOD = 9*1000000007LL ;
LL P(LL x,int n)
{
    LL ret = 1;
    for(int i=0;i<n;i++)
    {
        ret *= x;
        ret %= MOD;
    }
    return ret;
}


int main()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        LL n;
        scanf("%lld",&n);
        int m = n * n ;
        int sum = 0;
        memset(cnt1,0,sizeof(cnt1));
        memset(cnt2,0,sizeof(cnt2));
        m = n*2;
//        for(int i=0;i<n;i++)
//        {
//            for(int j=0;j<n;j++)
//            {
//                sum += 4*(i+j)*(i+j)*(n-i)*(n-j);
//                printf("%d  %d = %d\n",i,j,(i+j)*(i+j)*(2*n-i*2)*(2*n-j*2));
//            }
//            puts("");
//        }
//        for(int i=0;i<n;i++)
//        {
//            sum -= 4*i*i*n*(n-i) ;
//        }
        printf("Case #%d: ",t);
        if(n%3==0)printf("not integer\n");
        else
        {
            LL res ;

            res =  ( 5*P(n,3) - 2*P(n,2) - 8 * n + 5 + MOD)%MOD ;

            res = ((( n+1 ) * res) % MOD ) / 9;




            printf("%d\n",res);
            //printf("%f\n",(1.0/9 *pow(n,2) *(1+n) *(2-5*n- 2*pow(n,2)+5*pow(n,3))-(1.0/3*(-1+n)* pow(n,3) *(1+n)) )/n/n );

        }
        //printf("%d\n",1.0/9 *pow(n,2) *(1+n) *(2-5*n- 2*pow(n,2)+5*pow(n,3))-(1.0/3*(-1+n)* pow(n,3) *(1+n)));

    }
	return 0;
}
