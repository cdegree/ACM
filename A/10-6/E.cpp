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

const int N = 1005;
const LL mod = 1000000007LL;
char s[N], t[N];
LL dp[N][N], presum[N][N];

int main() {
    while(~scanf("%s", s)) {
        int n = strlen(s);
        memset(dp, 0, sizeof(dp));
        memset(presum, 0, sizeof(presum));
        presum[0][1] = 1;
        dp[0][1] = 1;
        for(int i = 1; i <= n; ++i) {

            for(int j = 1; j <= i + 1; ++j) {
                dp[i][j] = 0;
                if(s[i-1] == 'I') {
                    //for(int k = 1; k < j; ++k) {dp[i][j] += dp[i-1][k];}
                    dp[i][j] += presum[i-1][j-1];
                }
                else if(s[i-1] == 'D') {
                    //for(int k = j ; k <= i + 1; ++k) {dp[i][j] += dp[i-1][k];}
                    dp[i][j] += (presum[i-1][i] - presum[i-1][j-1] + mod) % mod;
                }
                else {
                    //for(int k = 1; k <= i + 1; ++k) {dp[i][j] += dp[i-1][k];}
                    dp[i][j] += presum[i-1][i] ;
                }
                dp[i][j] %= mod;
            }
            presum[i][0] = 0;
            for(int j = 1; j <= i + 1; ++j) {
                presum[i][j] = presum[i][j-1] + dp[i][j];
                presum[i][j] %= mod;
            }
        }
        LL res = 0;
        for(int i = 1; i <= n + 1; ++i) {
            res += dp[n][i];
            res %= mod;
        }
        printf("%lld\n", res);
    }
    return 0;
}
