#include<iostream>
#include<bitset>
#include<cstdio>
#include<string>
#include<cassert>
#include<cstdlib>
#include<cstring>
#include<queue>
using namespace std;
#define re(i,n) for(int i=0;i<n;i++)
#define re1(i,n) for(int i=1;i<=n;i++)
#define re2(i,n) for(int i=0;i<=n;i++)
#define re3(i,n) for(int i=1;i<n;i++)
#define clr(a,n) memset(a,n,sizeof(a))
#define debug(n) cout<<#n<<"="<<n<<end
inline bool _1(int mask , int i) {
    return mask & (1 << i);
}
template <typename T> inline void chkmin(T &a, const T b) {
    if(b < a) a = b;
}
template <typename T> inline void chkmax(T &a, const T b) {
    if(b > a) a = b;
}
const int N = 55;
const int inf = ~0u >> 2;
const int xinf = ~0u >> 1;
const int M = 8;
int num[N][N];
int dp[1 << M][1 << M][N];
int ft[N], T[N];
int G[N];
int Gtk[N];
int main() {
    int n, m, k, t;
    cin >> t;
    re(ooo, t) {
        scanf("%d%d%d", &n, &m, &k);
        int u, v, c;
        re(i, n) re(j, n) num[i][j] = i == j ? 0 : inf;
        re(i, m) {
            scanf("%d%d%d", &u, &v, &c);
            --u, --v;
            chkmin(num[u][v], c);
            chkmin(num[v][u], c);
        }
        re(p, n) re(i, n) re(j, n) chkmin(num[i][j] , num[i][p] + num[p][j]);
        //num[0][1] = 0;
        clr(Gtk, 0);
        clr(G, 0);
        int mask = 1 << k;
        re(i, k) {
            scanf("%d", &u);
            G[u-1] |= 1 << i;
            scanf("%d%d", &T[i], &ft[i]);
            int tm;
            scanf("%d", &tm);
            while(tm--) {
                scanf("%d", &v);
                Gtk[v-1] |= 1 << i;
            }
        }
        re(i, mask) re(j, mask) re(p, n) dp[i][j][p] = inf;
        dp[0][0][0] = 0;
        re(imsk, mask) re(jmsk, mask) if((imsk & jmsk) == imsk)
            re(u, n) if(dp[imsk][jmsk][u] < inf) {
                re(v, n) if(u != v) {
                    int isk = imsk , jsk = jmsk;
                    isk |= G[v];
                    jsk |= Gtk[v];
                    int val = dp[imsk][jmsk][u] + num[u][v];
                    chkmin(dp[imsk][jsk][v], val);
                    re(i, k) if(_1(imsk, i) == 0 && _1(isk, i)) {
                        val += _1(jsk, i) ? ft[i] : T[i];
                    }
                    jsk |= isk;
                    chkmin(dp[isk][jsk][v], val);
                }
            }
        int ans = dp[mask-1][mask-1][0];
        printf("Case #%d: %d\n", ooo + 1, ans);
    }
}
