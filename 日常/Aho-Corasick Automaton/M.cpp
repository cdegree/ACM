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

const int MAX_NODE = 60006;
const int CHILD_NUM = 2;
int dis[MAX_NODE];
bool vis[MAX_NODE];
int cost[56][56];
int src[56];
int dp[1<<11][56];
int len[56];
int loc[56];
class ACAutomaton {
    public:
        int chd[MAX_NODE][CHILD_NUM];
        int virus[MAX_NODE];
        int fail[MAX_NODE];
        int len[MAX_NODE];
        int Q[MAX_NODE];
        int resource[MAX_NODE];
        int ID[256];
        int sz;
        void Initialize() {
            fail[0] = 0;
            ID['0'] = 0;
            ID['1'] = 1;
        }
        void Reset() {
            memset(chd[0], 0, sizeof(chd[0]));
            sz = 1;
            resource[0] = 0;
        }
        int Insert(char *s, int tp) {
            int q = 0;
            for(; *s; ++s) {
                int c = ID[*s];
                if(!chd[q][c]) {
                    memset(chd[sz], 0, sizeof(chd[sz]));
                    resource[sz] = 0;
                    virus[sz] = 0;
                    chd[q][c] = sz++;
                }
                q = chd[q][c];
            }
            if(tp == -1) {
                virus[q] = 1;
            }
            else {
                resource[q] |= (1 << tp);
            }
            return q;
        }
        void Construct() {
            int *s = Q, *e = Q;
            for(int i = 0; i < CHILD_NUM; ++i) {
                if(chd[0][i]) {
                    *e++ = chd[0][i];
                    fail[ chd[0][i] ] = 0;
                }
            }
            while(s != e) {
                int r = *s++;
                for(int i = 0; i < CHILD_NUM; ++i) {
                    int &u = chd[r][i];
                    int v = fail[r];
                    if(u) {
                        len[u] = len[r] + 1;
                        *e++ = u;
                        fail[u] = chd[v][i];
                        virus[u] |= virus[ fail[u] ];
                        resource[u] |= resource[ fail[u] ];
                    }
                    else u = chd[v][i];
                }
            }
        }
        void BFS(int n) {
            const int inf = 2e8;
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < n; ++j) {
                    cost[i][j] = inf;
                }
            }
            for(int i = 0; i < n; ++i) {
                queue<int> Q;
                for(int j = 0; j < sz; ++j)dis[j] = 2e8;
                memset(vis, false, sizeof(vis));
                if(!virus[loc[i]])Q.push(loc[i]);
                vis[loc[i]] = 1;
                dis[loc[i]] = 0;
                while(!Q.empty()) {
                    int u = Q.front();
                    Q.pop();
                    vis[u] = 0;
                    for(int j = 0; j < CHILD_NUM; ++j) {
                        int v = chd[u][j];
                        if(!virus[v] && dis[v] > dis[u] + 1) {
                            dis[v] = dis[u] + 1;
                            if(!vis[v]) {
                                vis[v] = 1;
                                Q.push(v);
                            }
                        }
                    }
                }
                for(int j = 0; j < n; ++j) {
                    cost[i][j] = dis[loc[j]];
                }
            }
        }
        int Get_DP(int n, int endmask) {
            const int inf = 2e8;
            for(int i = 0; i < endmask; ++i) {
                for(int j = 0; j < n; ++j) {
                    dp[i][j] = inf;
                }
            }
            dp[0][0] = 0;
            for(int mask = 0; mask < endmask; ++mask) {
                for(int i = 0; i < n; ++i) {
                    if(dp[mask][i] < inf) {
                        for(int j = 0; j < n; ++j) {
                            if(cost[i][j] < inf) {
                                int nmask = mask | resource[ loc[j] ];
                                dp[nmask][j] = min(dp[mask][i] + cost[i][j], dp[nmask][j]);
                            }
                        }
                    }
                }
            }
            int res = inf;
            for(int i = 0; i < n; ++i) {
                if(~dp[endmask-1][i])checkmin(res, dp[endmask-1][i]);
            }
            return res;
        }
} AC;
char s[1005];
int main() {
    int n, m;
    AC.Initialize();
    while(1) {
        AC.Reset();
        scanf("%d%d", &n, &m);
        if(n == 0 && m == 0)break;
        for(int i = 0; i < n; ++i) {
            scanf("%s", s);
            AC.Insert(s, i);
        }
        for(int i = 0; i < m; ++i) {
            scanf("%s", s);
            AC.Insert(s, -1);
        }
        AC.Construct();
        int q = 0;
        loc[q++] = 0;
        for(int i = 0; i < AC.sz; ++i) {
            if(AC.resource[i])loc[q++] = i;
        }
        AC.BFS(q);
        int res = AC.Get_DP(q, 1 << n);
        printf("%d\n", res);
    }
    return 0;
}
