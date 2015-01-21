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

const int N = 100005;
int dp[N][33];

bool judge(int from, int to, int m) {
    int d[33] = {0};
    for(int i = 0; i < 30; ++i) {
        d[i] = dp[to][i] - dp[from][i];
    }
    int x = 0 ;
    for(int i = 30; i >= 0; --i) {
        if(d[i]) {
            x |= (1 << i);
        }
    }
    return x < m;
}

int main() {
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; ++t) {
        int n, m, a;
        scanf("%d%d", &n, &m);
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &a);
            int j = 0;
            for(int j = 0; j < 30; ++j) {
                dp[i][j] += dp[i-1][j];
                if((a >> j) & 1)++dp[i][j];
            }
        }
        LL res = 0;
        for(int i = 1; i <= n; ++i) {
            int l = 0, r = i - 1, mid, ans = -1;
            while(l <= r) {
                mid = (l + r) >> 1;
                if(judge(mid, i, m)) {
                    ans = mid;
                    r = mid - 1;
                }
                else l = mid + 1;
            }
            if(~ans) {
                res += i - ans;
            }
        }
        printf("Case #%d: %I64d\n", t, res);
    }
    return 0;
}
