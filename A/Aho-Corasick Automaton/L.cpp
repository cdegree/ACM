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

const int MAX_NODE = 505;
const int CHILD_NUM = 4;
int cnt[CHILD_NUM];
int num[CHILD_NUM];
int dp[11*11*11*12][MAX_NODE];
class ACAutomaton {
    public:
        int chd[MAX_NODE][CHILD_NUM];
        int fail[MAX_NODE];
        int val[MAX_NODE];
        int Q[MAX_NODE];
        int ID[256];
        int sz;
        void Initialize() {
            fail[0] = 0;
            ID['A'] = 0;
            ID['C'] = 1;
            ID['T'] = 2;
            ID['G'] = 3;
        }
        void Reset() {
            sz = 1;
            memset(chd[0], 0, sizeof(chd[0]));
            val[0] = 0;
        }
        void Insert(char *s) {
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
            ++val[q];
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
                        val[u] += val[fail[u]];
                    }
                    else u = chd[v][i];
                }
            }
        }
        int Get_dp() {
            memset(dp, -1, sizeof(dp));
            dp[0][0] = 0;
            int sum = 1;
            int hash[4];
            hash[0] = 1;
            hash[1] = (cnt[0] + 1) * hash[0];
            hash[2] = (cnt[1] + 1) * hash[1];
            hash[3] = (cnt[2] + 1) * hash[2];
            sum = cnt[0] * hash[0] + cnt[1] * hash[1] + cnt[2] * hash[2] + cnt[3] * hash[3];
            for(int i = 0; i <= sum; ++i) {
                int ACTG[4] = {0};
                int e = i;
                ACTG[3] = e / hash[3];
                e %= hash[3];
                ACTG[2] = e / hash[2];
                e %= hash[2];
                ACTG[1] = e / hash[1];
                e %= hash[1];
                ACTG[0] = e;
                if(ACTG[0] > cnt[0] || ACTG[1] > cnt[1] || ACTG[2] > cnt[2] || ACTG[3] > cnt[3])continue;
                for(int j = 0; j < sz; ++j) {
                    if(~dp[i][j]) {
                        //printf("%d,%d,%d,%d mask = %d q = %d dp = %d->\n", ACTG[0], ACTG[1], ACTG[2], ACTG[3], i, j, dp[i][j]);
                        for(int k = 0; k < CHILD_NUM; ++k) {
                            int v = chd[j][k];
                            if(ACTG[k] + 1 > cnt[k])continue;
                            ++ACTG[k];
                            int mask = ACTG[0] * hash[0] + ACTG[1] * hash[1] + ACTG[2] * hash[2] + ACTG[3] * hash[3];
                            dp[mask][v] = max(dp[mask][v], dp[i][j] + val[v]);
                            //printf("%d,%d,%d,%d mask = %d q = %d dp = %d\n", ACTG[0], ACTG[1], ACTG[2], ACTG[3], mask, v, dp[mask][v]);
                            --ACTG[k];
                        }
                    }
                }
            }
            int res = 0;
            for(int i = 0; i < sz; ++i) {
                checkmax(res, dp[sum][i]);
                //printf("dp[%d][%d]=%d\n", sum, i, dp[sum][i]);
            }
            return res;
        }
} AC;


char s[55];

int main() {
    int n;
    AC.Initialize();
    int T = 0;
    //freopen("Lout.txt", "w", stdout);
    while(~scanf("%d", &n)) {
        if(n==0)break;
        AC.Reset();
        for(int i = 0; i < n; ++i) {
            scanf("%s", s);
            AC.Insert(s);
        }
        AC.Construct();
        scanf("%s", s);
        int m = strlen(s);
        memset(cnt, 0, sizeof(cnt));
        for(int i = 0; i < m; ++i) {
            ++cnt[ AC.ID[s[i]] ];
        }
        int res = AC.Get_dp();
        printf("Case %d: %d\n", ++T, res);
    }
    return 0;
}
