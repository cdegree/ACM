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
    LL x, y;
} P[707];

inline LL Get_area(point a, point b, point c) {
    return abs((a.x - b.x) * (c.y - b.y) - (a.y - b.y) * (c.x - b.x));
}
const LL mod = 1000003;
int main() {
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; ++t) {
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) {
            scanf("%lld %lld", &P[i].x, &P[i].y);
        }
        LL sum = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                int cnt1 = j - i - 1;
                int cnt2 = n + i - j - 1;
                LL sum1 = 0, sum2 = 0;
                for(int k = i + 1; k < j; ++k) {
                    sum1 += Get_area(P[i], P[j], P[k]);
                }
                for(int k = j + 1; k < n + i; ++k) {
                    sum2 += Get_area(P[i], P[j], P[k%n]);
                }
                sum += sum1 * cnt2 + sum2 * cnt1;
                if(sum>mod)sum %= mod;
            }
        }
        printf("Case %d: %lld\n", t, sum / 2);

    }
    return 0;
}
