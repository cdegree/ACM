/*
hdu 4057
*/
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
const int inf = 1e6;
int dp[2][MAX_NODE][1<<10];
int n, L;
int w[11];
class ACAutomaton {
    public:
        int chd[MAX_NODE][CHILD_NUM];
        int fail[MAX_NODE];
        int Q[MAX_NODE];
        int val[MAX_NODE];
        int ID[256];
        int sz;
        void Init() {
            ID['A'] = 0;
            ID['G'] = 1;
            ID['T'] = 2;
            ID['C'] = 3;
        }
        void Reset() {
            fail[0] = 0;
            memset(chd[0], 0, sizeof(chd[0]));
            sz = 1;
        }
        void Insert(char *s, int k) {
            int q = 0;
            for(; *s; ++s) {
                int c = ID[*s];
                if(!chd[q][c]) {
                    memset(chd[sz], 0, sizeof(chd[sz]));
                    val[sz] = 0;
                    chd[q][c] = sz++;
                }
                q = chd[q][c];
            }
            val[q] |= 1 << k;
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
                        *e++ = u;
                        fail[u] = chd[v][i];
                        val[u] |= val[ fail[u] ];
                    }
                    else u = chd[v][i];
                }
            }
        }
        int Get_dp() {
            int st = 0, ed = 1;
            for(int i = 0; i < sz; ++i)for(int j = 0; j < (1 << n); ++j)dp[st][i][j]=dp[ed][i][j] = -inf;
            dp[0][0][0] = 0;
            for(int i = 0; i < L; ++i) {
                for(int j = 0; j < sz; ++j) {
                    for(int mask = 0; mask < (1 << n); ++mask) {
                        if(dp[st][j][mask] > -inf) {
                            for(int k = 0; k < CHILD_NUM; ++k) {
                                int q = chd[j][k];
                                int qmask = val[q];
                                int pmask = (qmask ^ mask)&qmask;
                                int add = 0;
                                for(int p = 0; p < n; ++p) {
                                    if((pmask >> p) & 1) {
                                        add += w[p];
                                    }
                                }
                                checkmax(dp[ed][q][pmask|mask], dp[st][j][mask] + add);
                            }
                        }
                    }
                }
                for(int j = 0; j < sz; ++j)for(int k = 0; k < (1 << n); ++k)dp[st][j][k] = -inf;
                st ^= 1, ed ^= 1;
            }
            int res = -inf;
            for(int i = 0; i < sz; ++i) {
                for(int j = 0; j < (1 << n); ++j) {
                    res = max(res, dp[st][i][j]);
                }
            }
            return res;
        }
} AC;

char s[105];
int main() {
    AC.Init();
    while(~scanf("%d%d", &n, &L)) {
        AC.Reset();
        for(int i = 0; i < n; ++i) {
            scanf("%s %d", s, w + i);
            AC.Insert(s, i);
        }
        AC.Construct();
        int res = AC.Get_dp();
        if(res < 0) {
            puts("No Rabbit after 2012!");
        }
        else {
            printf("%d\n", res);
        }
    }
    return 0;
}
