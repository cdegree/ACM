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
using namespace std;
const double PI = acos(-1.0);
map<int, int>::iterator it;
typedef long long LL ;
#pragma comment(linker,"/STACK:102400000,102400000")

const int N = 55;
const int K = 8;
int dp[1<<K][1<<K][N];

int T, n, m, k;
int BT[N], FT[N];
int ticket[N], attr[N];
int W[55][55];
const int inf = 1e9;
void init() {
    for(int i = 0; i < (1 << K); ++i)for(int j = 0; j < (1 << K); ++j)for(int k = 0; k < N; ++k)dp[i][j][k] = inf;
    for(int i = 0; i < N; ++i)for(int j = 0; j < N; ++j)W[i][j] = inf;
    memset(ticket, 0, sizeof(ticket));
    memset(attr, 0, sizeof(attr));
}
inline bool test_bit(int mask, int pos) {
    return ((1 << pos)&mask) != 0;
}
inline bool all(int mask) {
    return mask == ((1 << k) - 1);
}

bool vis[55];
int Q[55];

void checkmin(int &x, int y) {
    x = min(x, y);
}

int main() {
    scanf("%d", &T);
    for(int t = 1; t <= T; ++t) {
        scanf("%d%d%d", &n, &m, &k);
        int u, v, w;
        init();
        for(int i = 0; i < m; ++i) {
            scanf("%d%d%d", &u, &v, &w);
            --u, --v;
            W[u][v] = W[v][u] = w;
        }
        for(int i = 0; i < n; ++i)W[i][i] = 0;
        for(int u = 0; u < n; ++u) {
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < n; ++j) {
                    W[i][j] = min(W[i][u] + W[u][j], W[i][j]);
                }
            }
        }
        int f, fn;
        for(int i = 0; i < k; ++i) {
            scanf("%d%d%d%d", &f, BT + i, FT + i, &fn);
            attr[f-1] |= 1 << i;
            for(int j = 0; j < fn; ++j) {
                int fi;
                scanf("%d", &fi);
                ticket[fi-1] |= 1 << i;
            }
        }
        printf("Case #%d: ", t);
        int mask = (1 << k);
        dp[0][0][0] = 0;

        for(int Imask = 0; Imask < mask; ++Imask) {
            for(int Jmask = 0; Jmask < mask; ++Jmask) {
                if( !(Imask & Jmask)) {
                    /*
                    int *dist = dp[Imask][Jmask], tail = 0, front = 0;
                    for(int i=0; i<n; ++i) {
                        vis[i]=true;
                        Q[tail++]=i;
                    }
                    while(front != tail) {
                        int i = Q[front++];
                        if(front == N) {
                            front = 0;
                        }
                        vis[i]=false;
                        for(int j=0; j<n; ++j) {
                            if(dist[i] + W[i][j] < dist[j]) {
                                dist[j] = dist[i] + W[i][j];
                                if(!vis[j]) {
                                    vis[j] = true;
                                    Q[tail ++] = j;
                                    if(tail == N) {
                                        tail = 0;
                                    }
                                }
                            }
                        }
                    }
                    for(int i=0; i<n; ++i) {
                        int tmp = dp[ Imask ][ Jmask ][i];
                        checkmin( dp[ Imask ][ (Jmask|ticket[i]) & (~Imask) ][i] , tmp);
                        for(int p=0; p<k; ++p) {
                            if( !((Imask >> p) & 1) && ((attraction[i] >> p) & 1)  ) {
                                tmp += (  ((Jmask) >> p) & 1  )? FT[p]: BT[p];
                            }
                        }
                        checkmin(dp[Imask | attraction[i]][(Jmask | ticket[i]) & (~(Imask | attraction[i]))][i] ,tmp);
                    }
                    */

                    for(int u = 0; u < n; ++u) {
                        if(dp[Imask][Jmask][u] < inf) {
                            for(int v = 0; v < n; ++v) {
                                int tmp = dp[ Imask ][ Jmask ][u] + W[u][v];
                                checkmin( dp[ Imask ][ (Jmask|ticket[v]) & ~Imask][v] , tmp);
                                for(int p = 0; p < k; ++p) {
                                    if( ( ((Imask >> p) & 1) == 0) && ((attr[v] >> p) & 1)  ) {
                                        tmp += ((Jmask >> p) & 1) ? FT[p] : BT[p];
                                    }
                                }
                                checkmin(dp[Imask | attr[v]][(Jmask | ticket[v]) & ~(Imask | attr[v])][v], tmp);
                            }
                        }
                    }
                }
            }
        }
        int res = 1e8;
        res = dp[ mask-1 ][ 0 ][0];
        printf("%d\n", res);
    }
    return 0;
}
