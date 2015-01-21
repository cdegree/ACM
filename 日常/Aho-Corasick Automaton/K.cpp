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

const int N = 100005;
const int MAX_NODE = 600005;
const int CHILD_NUM = 26;

int cnt[N][2], pre[N], length[N];
int scnt;
class ACAutomaton {
    public:
        int chd[MAX_NODE][CHILD_NUM];
        int fail[MAX_NODE];
        bool flag[MAX_NODE];
        int id[MAX_NODE];
        int ID[256];
        int Q[MAX_NODE];
        int sz;
        void Initialize() {
            fail[0] = 0;
            for(int i = 0; i < CHILD_NUM; ++i) {
                ID[i+'a'] = i;
            }
        }
        void Reset() {
            memset(chd[0], 0, sizeof(chd[0]));
            sz = 1;
            id[0] = 0;
            scnt = 0;
        }
        int Insert(char *s, int key) {
            int q = 0;
            for(; *s; ++s) {
                int c = ID[*s];
                if(!chd[q][c]) {
                    memset(chd[sz], 0, sizeof(chd[sz]));
                    flag[sz] = 0;
                    id[sz] = 0;
                    chd[q][c] = sz++;
                }
                q = chd[q][c];
            }
            flag[q] = 1;
            if(!id[q]) {
                return id[q] = ++scnt;
            }
            else {
                return id[q];
            }
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
        void Query(char *s) {
            memset(pre, -1, sizeof(pre));
            memset(cnt, 0, sizeof(cnt));
            int q = 0;
            int n = strlen(s);
            for(int i = 0; i < n; ++i) {
                int c = ID[ s[i] ];
                q = chd[q][c];
                int p = q;
                while(p && flag[p]) {
                    if(id[p]) {
                        int r = id[p];
                        ++cnt[r][0];
                        if(i - pre[r] >= length[r]) {
                            ++cnt[r][1];
                            pre[r] = i;
                        }
                    }
                    p = fail[p];
                }
            }
        }
} AC;
char s[N], t[9];
int tp[N];
int belong[N];
int main() {
    int T = 0;
    AC.Initialize();
    while(~scanf("%s", s)) {
        AC.Reset();
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) {
            scanf("%d %s", tp + i, t);
            belong[i] = AC.Insert(t, i);
            length[ belong[i] ] = strlen(t);
        }
        AC.Construct();
        AC.Query(s);
        printf("Case %d\n", ++T);
        for(int i = 0; i < n; ++i) {
            printf("%d\n", tp[i] == 0 ? cnt[ belong[i] ][0] : cnt[ belong[i] ][1]);
        }
        puts("");
    }
    return 0;
}
