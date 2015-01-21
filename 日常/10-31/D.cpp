#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <vector>
#include <bitset>
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
#pragma comment(linker,"/STACK:102400000,102400000")
using namespace std;
const double PI = acos(-1.0);
map<int, int>::iterator it;
typedef long long LL ;
template<typename T> void checkmin(T &x, T y) {x = min(x, y);}
template<typename T> void checkmax(T &x, T y) {x = max(x, y);}

struct point {
    double x, y;
} P[22];
double get_dis(point a, point b) {
    return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}
int main() {
    int n;
    while(~scanf("%d", &n)) {
        for(int i = 0; i < n; ++i) {
            scanf("%lf %lf", &P[i].x, &P[i].y);
        }
        n -= 2;
        double res = 2e8;
        if(n == 0) {
            res = 2 * get_dis(P[0], P[1]);
            printf("%.2f\n", res);
            continue;
        }
        else if(n < 0) {
            puts("0.00");
            continue;
        }
        for(int mask = 0; mask < (1 << n); ++mask) {
            deque<int> forw, back;
            forw.push_back(0);
            back.push_front(0);
            for(int i = 0; i < n; ++i) {
                if((mask >> i) & 1) {
                    forw.push_back(i + 1);
                }
                else back.push_front(i + 1);
            }
            back.push_front(n + 1);
            forw.push_back(n + 1);
            double tmp = 0;
            for(int i = 1; i < forw.size(); ++i) {
                tmp += get_dis(P[ forw[i] ],  P[  forw[i-1] ]);
            }
            for(int i = 1; i < back.size(); ++i) {
                tmp += get_dis(P[ back[i] ],  P[  back[i-1] ]);
            }
            checkmin(res, tmp);
        }
        printf("%.2f\n", res);
    }
    return 0;
}
