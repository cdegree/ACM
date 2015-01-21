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

const int N = 102;
const int K = 15;
int dis[N][N];
int dp[K][1<<K];
const int inf = 2e8;
int sp[K], C[K], D[K];
int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n, m, mo;
        scanf("%d%d%d", &n, &m, &mo);
        int u, v, w;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                dis[i][j] = inf;
            }
        }
        for(int i = 0; i < m; ++i) {
            scanf("%d%d%d", &u, &v, &w);
            --v, --u;
            dis[u][v] = dis[v][u] = min(dis[u][v], w) ;
        }
        for(int i = 0; i < n; ++i)dis[i][i] = 0;
        for(int k = 0; k < n; ++k) {
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < n; ++j) {
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }
        int H;
        scanf("%d", &H);
        bool alr = 0;
        for(int i = 0; i < H; ++i) {
            scanf("%d%d%d", sp + i, C + i, D + i);
            --sp[i];
        }
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < H; ++i) {
            if(mo - dis[0][ sp[i] ] >= 0) dp[i][0] = mo - dis[0][ sp[i] ] ;
        }
        for(int mask = 0; mask < (1 << H) ; ++mask) {
            for(int i = 0; i < H; ++i) {
                for(int j = 0; j < H; ++j) {
                    if(!(mask&(1 << j)) && dp[i][mask] - dis[ sp[i] ][ sp[j] ] >= 0) {
                        if(dp[i][mask] - dis[ sp[i] ][ sp[j] ] - D[j] >= 0)
                            dp[j][mask|(1<<j)] = max(dp[j][mask|(1<<j)], dp[i][mask] - dis[ sp[i] ][ sp[j] ] - D[j] + C[ j ]);
                        //dp[j][mask] = max(dp[j][mask], dp[i][mask] - dis[ sp[i] ][ sp[j] ]);
                    }
                }
            }
        }
        int res = 0;
        for(int i = 0; i < H; ++i) {
            if(dp[i][(1<<H)-1] - dis[ sp[i] ][0] >= 0)checkmax(res,dp[i][(1<<H)-1] - dis[ sp[i] ][0]);
        }
        //printf("res = %d\n",res);
        if(res)puts("YES");
        else puts("NO");
    }
    return 0;
}
