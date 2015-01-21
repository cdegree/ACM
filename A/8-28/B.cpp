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

double P[200005];
double Q[200005];
double inf = 1e308;
double mn = 1e-308;
int main()
{
    int n;
    int T=1;
    double p;
    while(~scanf("%d %lf",&n,&p))
    {
        printf("Case %d: ",T++);
        double res=0;
        double q = 1-p;
        P[0]=Q[0]=log(1.0);
        for(int i=1; i<=n+1; ++i)
        {
            P[i]=P[i-1]+log(p);
            Q[i]=Q[i-1]+log(q);
        }
        double F1=P[n+1]+log(0.0+n),F2=Q[n+1]+log(0.0+n);
        res=0;
        double sum = exp(F1)+exp(F2);
        res = sum;
        double logq = log(q);
        double logp = log(p);
        double lgk,lgp;
        for(int k=1; k<n; ++k)
        {
            lgk = log(double(n+k)/k);
            lgp = log(double(n-k)/(n-k+1));
            F1 = F1+lgk+lgp+logq;
            F2 = F2+lgk+lgp+logp;
            sum = exp(F1)+exp(F2);
            res += sum;
        }
        printf("%.6f\n",res);
    }
    return 0;
}
