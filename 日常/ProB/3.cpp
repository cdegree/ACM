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

const int N = 100005;
int x[N],y[N];

int T;
int n;
double judge(double p) {
    double res=0;
    for(int i=0; i<n; ++i) {
        res += sqrt( (x[i]-p)*(x[i]-p) + y[i]*y[i]  );
    }
    return res;
}
int main() {

    scanf("%d",&T);
    for(int t=1; t<=T; ++t) {
        scanf("%d",&n);
        for(int i=0; i<n; ++i) {
            scanf("%d %d",x+i,y+i);
        }
        double res,Lmid,Rmid,L=-N,R=N,Lans,Rans;
        for(int j=0; j<500; ++j) {
            Lmid = L+(R-L)/3;
            Rmid = L+(R-L)/3*2;
            Lans = judge(Lmid);
            Rans = judge(Rmid);
            if(Lans<Rans) {
                R = Rmid;
            } else {
                L = Lmid;
            }
        }
        res = Lmid;
        printf("Case %d: %.6f\n",t,res);
    }
    return 0;
}
