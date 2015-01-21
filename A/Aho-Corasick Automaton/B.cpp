/*
3
aba
bab
abc
2
aaabbbccc
ababc
*/
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

const int MAX_NODE = 100002;
const int CHILD_NUM = 128;

class ACAutomaton {
    private:
        int chd[MAX_NODE][CHILD_NUM];
        int val[MAX_NODE];
        int fail[MAX_NODE];
        int Q[MAX_NODE];
        int sz;
    public:
        void Initialize() {
            fail[0] = 0;
        }
        void Reset() {
            sz = 1;
            memset(chd[0], -1, sizeof(chd[0]));
        }
        void Insert(char *s, int key) {
            int q = 0;
            for(; *s; ++s) {
                int c = *s;
                if(chd[q][c] == -1) {
                    memset(chd[sz], -1, sizeof(chd[sz]));
                    val[q] = 0;
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
                        while(chd[v][i] == -1 && v) {
                            v = fail[v];
                        }
                        fail[u] = chd[v][i] == -1 ? 0 : chd[v][i];
                    }
                }
            }
        }
        vector<int> Query(char *s) {
            vector<int> ret;
            int q = 0;
            for(; *s; ++s) {
                int c = *s;
                while(chd[q][c] == -1 && q)q = fail[q];
                q = chd[q][c];
                if(q == -1)q = 0;
                int p = q;
                while(p) {
                    if(val[p]) {
                        ret.push_back(val[p]);
                    }
                    p = fail[p];
                }
            }
            sort(ret.begin(), ret.end());
            int len = unique(ret.begin(), ret.end()) - ret.begin();
            ret.resize(len);
            return ret;
        }
} AC;

char s[10005], pat[202];
int main() {
    int n, m;
    AC.Initialize();
    while(~scanf("%d", &n)) {
        AC.Reset();
        for(int i = 0; i < n; ++i) {
            scanf("%s", pat);
            AC.Insert(pat, i + 1);
        }
        AC.Construct();
        scanf("%d", &m);
        int total = 0;
        for(int i = 0; i < m; ++i) {
            scanf("%s", s);
            vector<int> res = AC.Query(s);
            if(!res.empty()) {
                printf("web %d:", i + 1);
                for(int j = 0; j < res.size(); ++j) {
                    printf(" %d", res[j]);
                } puts("");
                ++total;
            }
        }
        printf("total: %d\n", total);
    }
    return 0;
}
