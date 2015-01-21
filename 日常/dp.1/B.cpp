/********************

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
double a[N], dp[N];

int main() {
    int T, n;
    scanf("%d", &T);
    for(int t = 1; t <= T; ++t) {
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) {
            scanf("%lf", a + i);
        }
        dp[n-1]=0;
        for(int i = n - 2; i >= 0; --i) {
            int j = min(n - 1 - i, 6);
            dp[i]=0;
            for(int k = 1; k <= j; ++k) {
                dp[i] += dp[i+k] + a[i+k];
            }
            dp[i] /= j;
        }
        dp[0] += a[0];
        printf("Case %d: %.6f\n", t, dp[0]);
    }
    return 0;
}
