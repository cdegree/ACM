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

int dp[17][1<<15];
const int N = 105;
const int inf = 1e9;
int dis[105][105];
int choose[17], C[17], D[17];
int main() {
    int T;
    int n, m, mo;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d%d", &n, &m, &mo);
        int u, v, w;
        for(int i = 0; i < N; ++i)for(int j = 0; j < N; ++j)dis[i][j] = inf;
        for(int i = 0; i < N; ++i)dis[i][i] = 0;
        for(int i = 0; i < m; ++i) {
            scanf("%d%d%d", &u, &v, &w);
            dis[u][v] = dis[v][u] = min(dis[u][v], w);
        }
        for(int k = 1; k <= n; ++k) {
            for(int i = 1; i <= n; ++i) {
                for(int j = 1; j <= n; ++j) {
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }
        int H;
        scanf("%d", &H);
        for(int i = 0; i < H; ++i)scanf("%d %d %d", choose + i, C + i, D + i);
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < H; ++i) {
            int u = choose[i];
            if(mo >= dis[1][u])dp[ i ][0] =  mo - dis[1][u];
        }
        int mask = 1 << H;
        for(int maskI = 0; maskI < mask; ++maskI) {
            for(int i = 0; i < H; ++i) {
                int u = choose[i];
                for(int j = 0; j < H; ++j) {
                    if(!((maskI >> j) & 1)) {
                        int v = choose[j];
                        if(dp[i][maskI] >= dis[u][v] + D[j]) {
                            dp[j][maskI|(1<<j)] = max(dp[j][maskI|(1<<j)], dp[i][maskI] - dis[u][v] - D[j] + C[j]);
                        }
                    }
                }
            }
        }
        int res = 0;
        for(int i = 0; i < H; ++i) {
            int u = choose[i];
            res = max(res, dp[i][mask-1] - dis[ u ][1]);
        }
        printf("%s\n", res > 0 ? "YES" : "NO");
    }
    return 0;
}
