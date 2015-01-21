#include <cstdio>
#include <algorithm>
#include <map>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <set>
#include <queue>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

int main() {
    int T;
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    scanf("%d",&T);
    for(int t=1; t<=T; ++t) {
        double C,X,F;
        scanf("%lf%lf%lf",&C,&F,&X);
        double per=2;
        double res=0;
        double a,b;
        a = X/per;
        b = C/per + X/(per+F) ;
        while(a>=b) {
            res += C/per;
            per += F;
            a = X/per;
            b = C/per + X/(per+F) ;
            //printf("%lf %lf\n",a,b);
        }
        res += a;
        printf("Case #%d: %.7f\n",t,res);
    }
    return 0;
}
