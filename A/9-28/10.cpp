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

int n;
const int N = 20005;
LL a[N], b[N], c[N];
bool judge(LL m) {
    LL sum = 0;
    for(int i = 0; i < n; ++i) {
        if(a[i] > m)continue;
        LL mn = min(b[i], m);
        sum += (mn - a[i]) / c[i] + 1;
    }
    //printf("m = %lld sum = %lld\n",m,sum);
    return sum & 1;
}
int main() {
    while(~scanf("%d", &n)) {
        for(int i = 0; i < n; ++i) {
            scanf("%I64d%I64d%I64d", a + i, b + i, c + i);
        }
        LL l = 0, r = 1LL << 32, ans = -1, mid;
        while(l <= r) {
            mid = (l + r) >> 1;
            if(judge(mid)) {
                r = mid - 1;
                ans = mid;
            }
            else l = mid + 1;
        }
        if(~ans) {
            int cnt = 0;
            for(int i = 0; i < n; ++i) {
                if(ans >= a[i] && ans <= b[i] && (ans - a[i]) % c[i] == 0)++cnt;
            }
            printf("%I64d %d\n", ans, cnt);
        }
        else {
            puts("DC Qiang is unhappy.");
        }
    }
    return 0;
}
