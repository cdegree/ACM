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
const int CHILD_NUM = 26;

int dp[55][MAX_NODE];
vector<int> pre[55][MAX_NODE], ch[55][MAX_NODE];
class ACAutomaton {
    public:
        int chd[MAX_NODE][CHILD_NUM];
        int fail[MAX_NODE];
        int val[MAX_NODE];
        int ID[256];
        int Q[MAX_NODE];
        int sz;
        string res, mn;
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
                    val[sz] = 0;
                    chd[q][c] = sz++;
                }
                q = chd[q][c];
            }
            val[q] += key;
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
                        val[u] += val[ fail[u] ];
                    }
                    else u = chd[v][i];
                }
            }
        }
        string Get_dp(int n) {
            memset(dp, -1, sizeof(dp));
            for(int i = 0; i <= n; ++i) {
                for(int j = 0; j < sz; ++j) {
                    pre[i][j].clear();
                    ch[i][j].clear();
                }
            }
            dp[0][0] = 0;
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < sz; ++j) {
                    if(dp[i][j] >= 0) {
                        for(int k = 0; k < CHILD_NUM; ++k) {
                            int q =  chd[j][k];
                            if(dp[i+1][q] == -1) {
                                dp[i+1][q] = dp[i][j] + val[q];
                                pre[i+1][q].clear();
                                ch[i+1][q].clear();
                                pre[i+1][q].push_back(j);
                                ch[i+1][q].push_back(k);
                            }
                            else if(dp[i+1][q] < dp[i][j] + val[q]) {
                                dp[i+1][q] = dp[i][j] + val[q];
                                pre[i+1][q].clear();
                                ch[i+1][q].clear();
                                pre[i+1][q].push_back(j);
                                ch[i+1][q].push_back(k);
                            }
                            else if(dp[i+1][q] == dp[i][j] + val[q]) {
                                pre[i+1][q].push_back(j);
                                ch[i+1][q].push_back(k);
                            }
                        }
                    }
                }
            }
            int mx = -1, m = 0 ;
            queue<int> Q;
            for(int i = 0; i <= n; ++i) {
                for(int j = 0; j < sz; ++j) {
                    //printf("ch[%d][%d]=%c dp = %d\n", i, j, ch[i][j] + 'a', dp[i][j]);
                    if(dp[i][j] > mx) {
                        mx = dp[i][j];
                        m = i;
                        //printf("mx = %d m=%d  q = %d c = %d \n", mx, m, q, c);
                    }
                }
            }
            for(int j = 0; j < sz; ++j) {
                if(dp[m][j] == mx) {
                    Q.push(j);
                }
            }

            res = "";
            mn = "";
            for(int i = 0; i < m; ++i)mn += 'z';
            while(!Q.empty()) {
                int cur = Q.front(); Q.pop();
                Output(m, cur);
            }
            res = mn;
            return res;
        }
        void Output(int n, int q) {
            if(n == 0) {
                checkmin(mn, res);
            }
            else {
                for(int i = 0; i < pre[n][q].size(); ++i) {
                    res += ch[n][q][i] + 'a';
                    Output(n - 1, pre[n][q][i]);
                    res.erase(res.begin() + res.size() - 1);
                }
            }
        }
} AC;


char s[105][13];
int main() {
    int T;
    scanf("%d", &T);
    AC.Initialize();
    while(T--) {
        AC.Reset();
        int n, m;
        scanf("%d%d", &n, &m);
        for(int i = 0; i < m; ++i) {
            scanf("%s", s[i]);
            reverse(s[i], s[i] + strlen(s[i]));
        }
        int val;
        for(int i = 0; i < m; ++i) {
            scanf("%d", &val);
            AC.Insert(s[i], val);
        }
        AC.Construct();
        string res = AC.Get_dp(n);
        printf("%s\n", res.c_str());
    }
    return 0;
}
