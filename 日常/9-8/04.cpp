#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;
#define ll long long
#pragma comment(linker,"/STACK:102400000,102400000")
#define FOR( i, a, b ) for(int i = a; i <= b; ++i )
const int fa = 1e+3 + 1;
const double ma = 1e+9;
const double eps = 1e-5;
const double pi = acos(-1.0);
int n, m, t;
struct wgh {
    double x, y;
} a[fa];
double la, lb, lc;
double dis(wgh a, wgh b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
//double area(double a,double b,double c)
//{
//    if(a + b > c && b + c > a && a + c > b)
//    {
//        double p=(a+b+c)/2.0;
//        return sqrt(p*(p-a)*(p-b)*(p-c));
//    }
//    else
//    {
//        return 0;
//    }
//}
//S£½1/2 * absinC;
double area(double a, double b, double st) {
    return 0.5 * a * b * sin(st);
}
int main() {
    //freopen("out.txt","w",stdout);
    //freopen("in.txt","r",stdin);
    int i, j, k;
    double x1, x2, y1, y2;
    double st;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(i = 1; i <= n; i++) {
            scanf("%lf%lf", &a[i].x, &a[i].y);
        }
        double ans = ma, maxx = ma;
        for(i = 1; i <= n; i++) {
            for(j = 1; j < i; j++) {
                for(k = 1; k < j; k++) {
                    la = dis(a[i], a[j]);
                    lb = dis(a[i], a[k]);
                    x1 = a[j].x - a[i].x;
                    x2 = a[k].x - a[i].x;
                    y1 = a[j].y - a[i].y;
                    y2 = a[k].y - a[i].y;
                    st = acos((x1 * x2 + y1 * y2) / (sqrt(x1 * x1 + y1 * y1) * sqrt(x2 * x2 + y2 * y2)));
                    maxx = area(la, lb, st);
                    if(fabs(maxx) < eps)
                        maxx = ma;
                    ans = min(maxx, ans);
                }
            }
        }
        if(fabs(ans - ma) > eps)
            printf("%.2f\n", ans);
        else
            printf("Impossible\n", ans);
    }
    return 0;
}
