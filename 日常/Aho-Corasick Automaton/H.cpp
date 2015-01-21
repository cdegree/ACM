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

const int MAX_NODE = 105;
const int CHILD_NUM = 26;
const int mod = 20090717;

int dp[2][MAX_NODE][1<<10];

class ACAutomaton {
    public:
        int chd[MAX_NODE][CHILD_NUM];
        int fail[MAX_NODE];
        int flag[MAX_NODE];
        int ID[256];
        int Q[MAX_NODE];
        int sz;
        void Initialize() {
            fail[0] = 0;
            for(int i = 0; i < 26; ++i) {
                ID[i+'a'] = i;
            }
        }
        void Reset() {
            memset(chd[0], 0, sizeof(chd[0]));
            sz = 1;
        }
        void Insert(char *s, int key) {
            int q = 0;
            for(; *s; ++s) {
                int c = ID[*s];
                if(!chd[q][c]) {
                    memset(chd[sz], 0, sizeof(chd[sz]));
                    flag[sz] = 0;
                    chd[q][c] = sz++;
                }
                q = chd[q][c];
            }
            flag[q] |= 1 << key;
        }
        void Construct() {
            int *s = Q, *e = Q;
            for(int i = 0; i < CHILD_NUM; ++i) {
                if(chd[0][i]) {
                    fail[ chd[0][i] ] = 0;
                    *e++ = chd[0][i];
                }
            }
            while(s != e) {
                int r = *s++;
                for(int i = 0; i < CHILD_NUM; ++i) {
                    int &u = chd[r][i];
                    int v = fail[r];
                    if(u) {
                        *e++ = u;
                        fail[u] = chd[v][i];
                        flag[u] |= flag[ fail[u] ];
                    }
                    else u = chd[v][i];
                }
            }
        }
        LL Get_dp(int n, int m, int K) {
            memset(dp, 0, sizeof(dp));
            int t1 = 0, t2 = 1;
            dp[0][0][0] = 1;
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < sz; ++j) {
                    for(int k = 0; k < (1 << m); ++k) {
                        if(dp[t1][j][k]) {
                            for(int p = 0; p < CHILD_NUM; ++p) {
                                int q = chd[j][p];
                                dp[t2][q][ k|flag[q] ] += dp[t1][j][k];
                                if(dp[t2][q][ k|flag[q] ] >= mod)dp[t2][q][ k|flag[q] ] %= mod;
                            }
                        }
                    }
                }
                memset(dp[t1], 0, sizeof(dp[t1]));
                t1 ^= 1, t2 ^= 1;
            }
            int res = 0;
            for(int j = 0; j < sz; ++j) {
                for(int k = 0; k < (1 << m); ++k) {
                    int cnt = 0;
                    for(int p = 0; p < m; ++p) {
                        cnt += (k >> p) & 1;
                    }
                    if(cnt >= K) {
                        //printf("cnt = %d dp[%d][%d][%d] = %d\n", cnt, t1, j, k, dp[t1][j][k]);
                        res += dp[t1][j][k];
                        if(res >= mod)res %= mod;
                    }
                }
            }

            return res;
        }
} AC;
char s[14];
int main() {
    int n, m, K;
    AC.Initialize();
    while(~scanf("%d%d%d", &n, &m, &K)) {
        if(n == 0 && m == 0 && K == 0)break;
        AC.Reset();
        for(int i = 0; i < m; ++i) {
            scanf("%s", s);
            AC.Insert(s, i);
        }
        AC.Construct();
        int res = AC.Get_dp(n, m, K);
        printf("%d\n", res);
    }
    return 0;
}
