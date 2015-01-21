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

const int N = 55;
const int M = 8;
int dp[N][1<<8][1<<8];

int dis[N][N];
int fast[N], slow[N], loc[N], pass[N];
const int inf = 1e9;
int main() {
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; ++t) {
        int n, m, K;
        scanf("%d%d%d", &n, &m, &K);
        for(int i = 0; i < N; ++i)for(int j = 0; j < N; ++j)dis[i][j] = inf;
        for(int i = 0; i < N; ++i)for(int j = 0; j < (1 << M); ++j)for(int k = 0; k < (1 << M); ++k)dp[i][j][k] = inf;
        memset(loc, 0, sizeof(loc));
        memset(pass, 0, sizeof(pass));
        for(int i = 0; i < N; ++i)dis[i][i] = 0;
        for(int i = 0; i < m; ++i) {
            int a, b, d;
            scanf("%d %d %d", &a, &b, &d);
            --a, --b;
            dis[a][b] = dis[b][a] = d;
        }
        for(int i = 0; i < K; ++i) {
            int p, np;
            scanf("%d %d %d %d", &p, slow + i, fast + i, &np);
            loc[p-1] |= 1 << i;
            while(np--) {
                int q;
                scanf("%d", &q);
                pass[q-1] |= 1 << i;
            }
        }
        for(int k = 0; k < n; ++k) {
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < n; ++j) {
                    dis[i][j] = min(dis[i][k] + dis[k][j], dis[i][j]);
                }
            }
        }

        dp[0][0][0] = 0;

        for(int maskAttr = 0; maskAttr < (1 << K); ++maskAttr) {
            for(int maskPass = 0; maskPass < (1 << K); ++maskPass) {
                if(!(maskAttr & maskPass)) {
                    for(int u = 0; u < n; ++u) {
                        if(dp[u][maskAttr][maskPass] < inf) {
                            for(int v = 0; v < n; ++v) {
                                int NewPassMask = maskPass | pass[v];
                                int NewAttrMask = maskAttr | loc[v];
                                int sum = dp[u][maskAttr][maskPass] + dis[u][v];
                                checkmin(dp[v][maskAttr][NewPassMask & ~maskAttr], sum);
                                for(int i = 0; i < K; ++i) {
                                    if((((maskAttr >> i) & 1) == 0) && ((loc[v] >> i) & 1)) {
                                        sum += ((maskPass >> i) & 1)  ? fast[i] : slow[i];
                                    }
                                }
                                checkmin(dp[v][NewAttrMask][~NewAttrMask&NewPassMask], sum);
                            }
                        }
                    }
                }
            }
        }
        int res = dp[0][(1<<K)-1][0];
        printf("Case #%d: %d\n", t, res);
    }
    return 0;
}
