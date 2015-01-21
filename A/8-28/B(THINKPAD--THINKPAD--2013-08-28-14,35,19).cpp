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
    int n;
    int T=1;
    double p;
    while(~scanf("%d %lf",&n,&p))
    {
        printf("Case %d: ",T++);
        double res=0;
        double C = n+2;
        double pn = pow(p,n+1.0);
        res = pn;
        double pv = 1-p;
        //printf("pn = %.6f\n",pn);
        for(int k=1;k<=n;++k)
        {
            res+= C*pn*pv*(n-k);
            C=C*(n+k+1.0)/k;
            pv*=(1-p);
        }
        printf("C = %.6f\n",C);
        C=n+2;
        pn = pow(1-p,n+1.0);
        res+=pn;
        pv = p;
        for(int k=1;k<=n;++k)
        {
            res+=C*pn*pv*(n-k);
            C*=(n+k+1.0)/k;
            pv*=p;
        }
        printf("%.6f\n",res);
    }
	return 0;
}
