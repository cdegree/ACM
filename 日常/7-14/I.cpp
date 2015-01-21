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

const int N = 3003;
int n,t;
double p[N];
double preproduct[N];

double gaoP(int from,int to)
{
    double prod=1;
    for(int i=from;i<to;++i)
    {
        prod*=(1-p[i]);
    }
    prod*=p[to];
    return prod;
}
double ret;
void xgao(int T,double Pro,int u)
{
    if(T!=0&&T*Pro<1e-8)return ;
    if(u==n+1)
    {
        printf("T = %d, Pro = %.6f, u = %d\n",T,Pro,u);
        printf("%.9f\n",(T+t)*Pro);
        ret += (T+t)*Pro;
        return ;
    }
        xgao(T+1,Pro*(1-p[u]),u+1);
        //printf("ret = %.10f\n",ret);
        xgao(T+2*(n-u+1)+t,Pro*p[u],u);
        //printf("ret = %.10f\n",ret);

}
double gao()
{
    double expT=(n+t)*gaoP(1,n+1);
    for(int i=1;i<=n;++i)
    {
        double one = gaoP(1,i)*gaoP(i,n+1)*(n+t+n-i+1+t);
        expT += one ;
    }
    printf("%.f\n",expT);
}
int main()
{
    while(~scanf("%d%d",&n,&t))
    {
        preproduct[0]=1;
        for(int i=1;i<=n;++i)
        {
            scanf("%lf",p+i);
            //printf("%f\n",p[i]);
            preproduct[i]=preproduct[i-1]*(1-p[i]);
        }
        p[n+1]=1;
        //gao();
        ret=0;
        xgao(0,1,1);
        printf("%.10f\n",ret);
    }
	return 0;
}
