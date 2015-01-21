/********************

LightOJ 1031

Author:Cdegree

********************/
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
int a[N], dp[N][N], sum[N];
int main() {
    int T, n;
    scanf("%d", &T);
    for(int t = 1; t <= T; ++t) {
        scanf("%d", &n);
        memset(dp, 0, sizeof(dp));
        sum[0] = 0;
        for(int i = 1; i <= n; ++i) {
            scanf("%d", a + i);
            dp[i][i] = a[i];
            sum[i] = sum[i-1] + a[i];
        }
        for(int L = 1; L < n; ++L) {
            for(int i = 0; i + L <= n; ++i) {
                dp[i][i+L] = sum[i+L] - sum[i-1];
                for(int j = i; j < i + L; ++j) {
                    dp[i][i+L] = max(dp[i][i+L] , sum[j] - sum[i-1] - dp[j+1][i+L]);
                    dp[i][i+L] = max(dp[i][i+L] , sum[i+L] - sum[j] - dp[i][j]);
                }
            }
        }
        printf("Case %d: %d\n", t, dp[1][n]);
    }
    return 0;
}
