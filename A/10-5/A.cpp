#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <queue>
#include <vector>
#include <functional>
#include <map>
#include <cctype>
#include <stack>
#define eps 1e-11
#define pi acos(-1.0)
using namespace std;
double a, b, c, d;
int n, m;
double th1, th2;
int main() {
    int i, j, ans;
    double t1, t2, r1, r2;
    //freopen("in.txt","r",stdin);
    while(~scanf("%lf%lf%d", &a, &b, &n)) {
        ans = 0;
        scanf("%lf%lf%d", &c, &d, &m);
        r1 = m * log(a * a + b * b);
        r2 = n * log(c * c + d * d);
        if(r1 - eps > r2 || r1 + eps < r2) {
            printf("0\n");
            continue;
        }
        a += eps;
        c += eps;
        th1 = atan(b / a);
        th2 = atan(d / c);
        if(a < -eps)th1 += pi;
        if(c < -eps)th2 += pi;
        if(th1 < -eps)th1 += pi * 2;
        if(th2 < -eps)th2 += pi * 2;
        for(i = 0; i < n ; i++) {
            for(j = 0; j < m; j++) {
                t1 = (th1 + 2 * i * pi) / n;
                t2 = (th2 + 2 * j * pi) / m;
                while(t1 > 2 * pi - eps)t1 -= 2 * pi;
                while(t2 > 2 * pi - eps)t2 -= 2 * pi;
                if(fabs(t1-t2)<eps)ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
