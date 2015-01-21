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

int a[11];
int idx[11];
double sum;
int n;
void gao(int u,int a1,int a2,int a3,int s1,int s2,int s3)
{
    if(u==n)
    {
        if(a1>=s1&&a2>=s2&&a3>=s3)
        {
            int b=a1-s1,c=a2-s2,d=a3-s3;
            if(b+c>=d&&b+d>=c&&c+d>=b)
            {
                double p = (b+c+d)/2.0;
                sum = min(sum,sqrt(p*(p-b)*(p-c)*(p-d)));
            }
        }
    }
    else
    {
        gao(u+1,a1+a[u],a2,a3,s1,s2,s3);
        gao(u+1,a1,a2+a[u],a3,s1,s2,s3);
        gao(u+1,a1,a2,a3+a[u],s1,s2,s3);
        gao(u+1,a1,a2,a3,s1+a[u],s2,s3);
        gao(u+1,a1,a2,a3,s1,s2+a[u],s3);
        gao(u+1,a1,a2,a3,s1,s2,s3+a[u]);
    }
}
int main()
{

    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;++i)
        {
            scanf("%d",a+i);
        }
        sum=999999999;
        gao(0,0,0,0,0,0,0);
        printf("%.6f\n",sum);
    }
	return 0;
}
