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
struct point {
    double x,y,z;
} P[2];
point res;
const double eps=1e-6;
int main() {
    int T;
    scanf("%d",&T);
    for(int t=1; t<=T; ++t) {
        int n;
        scanf("%d",&n);
        for(int i=0; i<n; ++i) {
            scanf("%lf %lf %lf",&P[i].x,&P[i].y,&P[i].z);
        }
        if(P[0].x==0&&P[0].y==0&&P[0].z==0)
        {
            P[0]=P[1];
            n=1;
        }
        else if(P[1].x==0&&P[1].y==0&&P[1].z==0)
        {
            n=1;
        }
        double A,B,C;
        point v;
        v = P[0];
        printf("Case %d: ",t);
        if(fabs( P[0].x-P[1].x )<eps&&fabs( P[0].y-P[1].y )<eps&&fabs( P[0].z-P[1].z )<eps)
            n=1;
        if(n==2) {
            v.x=P[0].y*P[1].z-P[0].z*P[1].y;
            v.y=P[0].z*P[1].x-P[0].x*P[1].z;
            v.z=P[0].x*P[1].y-P[0].y*P[1].x;
            if(fabs(v.x)<eps&&fabs(v.y)<eps&&fabs(v.z)<eps) {
                res.x=1,res.y=0,res.z=0;
            } else {
                res.x=v.x,res.y=v.y,res.z=v.z;
                //printf("%.6f %.6f %.6f\n",v.x,v.y,v.z);
            }
        } else if(n==1) {
            if(P[0].x==0&&P[0].y==0&&P[0].z==0) {
                res.x=1,res.y=0,res.z=0;
            } else {
                P[1].x=P[0].x+1;
                P[1].y=P[0].y-2;
                P[1].z=P[0].z+3;
                v.x=P[0].y*P[1].z-P[0].z*P[1].y;
                v.y=P[0].z*P[1].x-P[0].x*P[1].z;
                v.z=P[0].x*P[1].y-P[0].y*P[1].x;
                if(fabs(v.x)<eps&&fabs(v.y)<eps&&fabs(v.z)<eps) {

                    res.x=1,res.y=0,res.z=0;
                } else {
                    res.x=v.x,res.y=v.y,res.z=v.z;
                    //printf("%.6f %.6f %.6f\n",v.x,v.y,v.z);
                }
            }
        } else {
            while(1);
        }
        bool ok=true;
        for(int i=0; i<n; ++i) {
                double cha = P[i].x*res.x+P[i].y*res.y+P[i].z*res.z ;
        //printf("char = %.6f\n",cha);
            if(fabs( P[i].x*res.x+P[i].y*res.y+P[i].z*res.z  )>eps) {
                ok=false;
            }
        }
        //printf("ok=%d\n",ok);
        printf("%.6f %.6f %.6f\n",res.x,res.y,res.z);
    }
    return 0;
}
