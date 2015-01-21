#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;
LL dp[105];

const LL mod = 1e9+7;
const double pi = acos(-1.0);
int main() {
    int T;
    scanf("%d",&T);
    for(int t=1; t<=T; ++t) {
        double R,H;
        scanf("%lf %lf",&R,&H);
        double x,y,r,h;
        int n;
        scanf("%d",&n);
        for(int i=0; i<n; ++i) {
            scanf("%lf %lf %lf %lf",&x,&y,&r,&h);
        }
        double res;
        if(n==0) {
            res =2*pi*R;
        } else {
            double d= sqrt(x*x+y*y);
            if(h*R<H*(R-d-r))
            {
                res=2*pi*R;
            }
            else
            {
                if(h*R>=H*(R-d))
                {
                    double al = asin(r/d);
                    printf("al = %f\n",al);
                    res = 2*pi*R-al*R;
                }
                else
                {

                }
            }
        }
        res = res/(2*pi*R);
        printf("Case %d: ",t);
        printf("%.6f\n",res);
    }
    return 0;
}
