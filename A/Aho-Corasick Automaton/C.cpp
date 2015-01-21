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
#pragma comment(linker,"/STACK:102400000,102400000")
using namespace std;
const double PI = acos(-1.0);
map<int, int>::iterator it;
typedef long long LL ;
template<typename T> void checkmin(T &x, T y) {x = min(x, y);}
template<typename T> void checkmax(T &x, T y) {x = max(x, y);}

const int MAX_NODE = 50005;
const int CHILD_NUM = 26;
int cnt[1005];

class ACAutomaton {
    private:
        int chd[MAX_NODE][CHILD_NUM];
        int fail[MAX_NODE];
        int val[MAX_NODE];
        int Q[MAX_NODE];
        int ID[128];
        int sz;
    public:
        void Initialize() {
            fail[0] = 0;
            memset(ID, -1, sizeof(ID));
            for(int i = 0; i < CHILD_NUM; ++i) {
                ID[i+'A'] = i;
            }
        }
        void Reset() {
            memset(chd[0], -1, sizeof(chd[0]));
            sz = 1;
        }
        void Insert(char *s, int key) {
            int q = 0;
            for(; *s; ++s) {
                int c = ID[*s];
                if(chd[q][c] == -1) {
                    memset(chd[sz], -1, sizeof(chd[sz]));
                    val[sz] = 0;
                    chd[q][c] = sz++;
                }
                q = chd[q][c];
            }
            val[q] = key;
        }
        void Construct() {
            int *s = Q, *e = Q;
            for(int i = 0; i < CHILD_NUM; ++i) {
                if(~chd[0][i]) {
                    fail[ chd[0][i] ] = 0;
                    *e++ = chd[0][i];
                }
            }
            while(s != e) {
                int r = *s++;
                for(int i = 0; i < CHILD_NUM; ++i) {
                    int u = chd[r][i];
                    if(~u) {
                        *e++ = u;
                        int v = fail[r];
                        while(chd[v][i] == -1 && v)v = fail[v];
                        fail[u] = chd[v][i] == -1 ? 0 : chd[v][i];
                    }
                }
            }
        }
        void Query(char *s) {
            int q = 0;
            for(; *s; ++s) {
                int c = ID[*s];
                if(c == -1) {
                    q = 0;
                    continue;
                }
                while(chd[q][c] == -1 && q)q = fail[q];
                q = chd[q][c];
                if(q == -1)q = 0;
                int p = q;
                while(p) {
                    if(val[p]) {
                        ++cnt[ val[p] ];
                    }
                    p = fail[p];
                }
            }
        }
} AC;
char s[2000005], pat[1005][55];
int main() {
    int n;
    AC.Initialize();
    while(~scanf("%d", &n)) {
        AC.Reset();
        for(int i = 0; i < n; ++i) {
            scanf("%s", pat[i]);
            AC.Insert(pat[i], i + 1);
        }
        AC.Construct();
        scanf("%s", s);
        memset(cnt, 0, sizeof(cnt));
        AC.Query(s);
        for(int i = 0; i < n; ++i) {
            if(cnt[i+1]) {
                printf("%s: %d\n", pat[i], cnt[i+1]);
            }
        }
    }
    return 0;
}
