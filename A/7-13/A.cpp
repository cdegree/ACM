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
typedef unsigned long long uLL;
uLL sumP,P[55];
int n,a,b,p,l1,l2,l3;
int x,y;
int ba,bb;
uLL C[55][55];
void init_xy()
{
    l3=n-l1-l2;
    x=l1;
    y=l3+l1;

    ba=0,bb=n;
    for(int i=0;i<=n;++i)
    {
        C[i][0]=1;
        C[i][i]=1;
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=i;++j)
        {
            C[i][j]=C[i-1][j-1]+C[i-1][j];
            //printf(" %lld",C[i][j]);
        }
        //puts("");
    }
}
bool isgreater(int a,int b)
{
    int mn=max(a,x);
    int mx=min(b,y);
    uLL nowP=0;
    for(int i=mn;i<=mx;++i)
    {
        nowP+=P[i];
    }
    nowP*=100;
    return nowP>=sumP;
}
LL get_P(int m)
{
    //printf("%lld * %lld = %lld\n",C[m][l1],C[n-m][l2],C[m][l1]*C[n-m][l2]);
    return C[m][l1]*C[n-m][l2];
}
void gao()
{
    for(int i=0;i<=n;++i)
    {
        for(int j=i;j<=n;++j)
        {
            if(isgreater(i,j))
            {
                if(j-i<bb-ba)
                {
                    bb=j;
                    ba=i;
                }
                else if(j-i==bb-ba&&i<ba)
                {
                    bb=j;
                    ba=i;
                }
            }
        }
    }
}
void gaoP()
{
    sumP=0;
    for(int i=x;i<=y;++i)
    {
        P[i]=get_P(i);
        sumP+=P[i];
        //printf("%d .= %lld\n",i,P[i]);
    }
    sumP*=p;
    //cout<<sumP<<endl;
}
int main()
{
    while(~scanf("%d%d%d%d",&n,&l1,&l2,&p))
    {
        init_xy();
        gaoP();
        gao();
        printf("%d %d\n",ba,bb);
    }
	return 0;
}
