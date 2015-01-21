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
#pragma comment(linker,"/STACK:102400000,102400000")
using namespace std;
const double PI = acos(-1.0);
map<int, int>::iterator it;
typedef long long LL ;
template<typename T> void checkmin(T &x, T y) {x = min(x, y);}
template<typename T> void checkmax(T &x, T y) {x = max(x, y);}

struct point {
    LL x, y;
    LL d;
};


void gao(point st, point ed, LL &A, LL &B, LL &C) {
    A = st.y - ed.y;
    B = ed.x - st.x;
    C = (st.x - ed.x) * st.y - (st.y - ed.y) * st.x ;
}
point P[202];
int main() {
    int n;

    LL a, b, c;
    point l1, l2;
    l1.x = 0, l1.y = 1;
    l2.x = 1, l2.y = 3;
    gao(l1, l2, a, b, c);
    //printf("%lld %lld %lld\n", a, b, c);

    while(~scanf("%d", &n)) {
        if(n == 0)break;
        for(int i = 0; i < n; ++i) {
            scanf("%d %lld %lld", &P[i].d, &P[i].x, &P[i].y);
        }
        LL res = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                LL sum0 = 0, sum1 = 0;
                for(int k = 0; k < n; ++k) {
                    if(i == k || k == j)continue;
                    LL a, b, c;
                    gao(P[i], P[j], a, b, c);
                    if(a * P[k].x + b * P[k].y + c < 0) {
                        sum0 += P[k].d;
                    }
                    else {
                        sum1 += P[k].d;
                    }
                }
                checkmax(res, (sum0)*(sum1 + P[i].d + P[j].d));
                checkmax(res, (sum0 + P[i].d)*(sum1 + P[j].d));
                checkmax(res, (sum0 + P[j].d)*(sum1 + P[i].d));
                checkmax(res, (sum0 + P[i].d + P[j].d)*(sum1));
            }
        }
        printf("%lld\n", res);
    }
    return 0;
}
