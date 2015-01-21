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

const int N = 105;
const int inf = 1e9;
int dp[N][N];
int D[N], sum[N];
int main() {
    int T, n;
    scanf("%d", &T);
    for(int t = 1; t <= T; ++t) {
        scanf("%d", &n);
        sum[0] = 0;
        for(int i = 1; i <= n; ++i) {scanf("%d", D + i); sum[i] = sum[i-1] + D[i];}
        for(int i = 1; i <= n; ++i)for(int j = i; j <= n; ++j)dp[i][j] = inf;
        for(int i = 1; i <= n; ++i)dp[i][i] = 0;
        for(int l = 1; l < n; ++l) {
            for(int i = 1; i + l <= n; ++i) {
                int j = i + l;
                for(int k = 1; k <= j; ++k) {
                    dp[i][j] = min(dp[i][j], (k - 1) * D[i] + dp[i+1][i+k-1] + k * (sum[j] - sum[i+k-1]) + dp[i+k][j]);
                }
            }
        }
        printf("Case #%d: %d\n", t, dp[1][n]);
    }
    return 0;
}
