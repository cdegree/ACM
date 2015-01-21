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


const int MAX_NODE = 1005;
const int CHILD_NUM = 4;
const int mod = 20090717;

int dp[2][MAX_NODE];

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
            ID['A'] = 0;
            ID['G'] = 1;
            ID['C'] = 2;
            ID['T'] = 3;
        }
        void Reset() {
            memset(chd[0], 0, sizeof(chd[0]));
            sz = 1;
        }
        void Insert(char *s) {
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
            flag[q] = 1;
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
        void update(int& a, int b) {
            a = a == -1 ? b : min(a, b);
        }
        int Get_res(char *s) {
            int n = strlen(s);
            memset(dp, -1, sizeof(dp));
            dp[0][0] = 0;
            int t1 = 0, t2 = 1;
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < sz; ++j) {
                    if(~dp[t1][j]) {
                        for(int k = 0; k < CHILD_NUM; ++k) {
                            int q = chd[j][k];
                            if(ID[ s[i] ] == k && !flag[q]) {
                                update(dp[t2][q],dp[t1][j]);
                            }
                            else if(!flag[q]) {
                                update(dp[t2][q],dp[t1][j]+1);
                            }
                        }
                    }
                }
                memset(dp[t1], -1, sizeof(dp[t1]));
                t1 ^= 1, t2 ^= 1;
            }
            int ret = 10000;
            for(int j = 0; j < sz; ++j) {
                if(~dp[t1][j] && !flag[j]) {
                    //printf("dp = %d\n", dp[t1][j]);
                    checkmin(ret, dp[t1][j]);
                }
            }
            return ret == 10000 ? -1 : ret;
        }
} AC;


char s[1005];

int main() {
    int T = 0, n;
    AC.Initialize();
    while(~scanf("%d", &n), n) {
        AC.Reset();
        for(int i = 0; i < n; ++i) {
            scanf("%s", s);
            AC.Insert(s);
        }
        AC.Construct();
        scanf("%s", s);
        int res;
        res = AC.Get_res(s);
        printf("Case %d: %d\n", ++T, res);
    }
    return 0;
}
