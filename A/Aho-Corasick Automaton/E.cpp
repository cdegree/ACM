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
const int CHILD_NUM = 4;
const LL mod = 100000;

struct Matrix {
    LL d[MAX_NODE][MAX_NODE];
    int m;
    void Set_Zero() {
        memset(d, 0, sizeof(d));
    }
    void Set_One() {
        memset(d, 0, sizeof(d));
        for(int i = 0; i < m; ++i)d[i][i] = 1;
    }
    Matrix operator *(Matrix x) {
        Matrix ret(m);
        ret.Set_Zero();
        for(int i = 0; i < m; ++i) {
            for(int k = 0; k < m; ++k) {
                if(!d[i][k])continue;
                for(int j = 0; j < m; ++j) {
                    ret.d[i][j] += d[i][k] * x.d[k][j];
                    ret.d[i][j] %= mod;
                }
            }
        }
        return ret;
    }
    Matrix() {}
    Matrix(int _n): m(_n) {}
    Matrix Power(LL n) {
        Matrix a(m), b(m);
        b.Set_One();
        a = *this;
        while(n) {
            if(n & 1)b = a * b;
            a = a * a;
            n >>= 1;
        }
        return b;
    }
    void pf() {
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < m; ++j) {
                printf("%3d", d[i][j]);
            } puts("");
        }
    }
};

class ACAutomaton {
    public:
        int chd[MAX_NODE][CHILD_NUM];
        int flag[MAX_NODE];
        int fail[MAX_NODE];
        int Q[MAX_NODE];
        int ID[MAX_NODE];
        int sz;
        void Initialize() {
            fail[0] = 0;
            ID['A'] = 0;
            ID['C'] = 1;
            ID['G'] = 2;
            ID['T'] = 3;
        }
        void Reset() {
            sz = 1;
            memset(chd[0], -1, sizeof(chd[0]));
            flag[0]=0;
        }
        void Insert(char *s) {
            int q = 0;
            for(; *s; ++s) {
                int c = ID[*s];
                if(chd[q][c] == -1) {
                    memset(chd[sz], -1, sizeof(chd[sz]));
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
                if(~chd[0][i]) {
                    fail[ chd[0][i] ] = 0;
                    *e++ = chd[0][i];
                }
                else chd[0][i] = 0;
            }
            while(s != e) {
                int r = *s++;
                for(int i = 0; i < CHILD_NUM; ++i) {
                    int &u = chd[r][i];
                    int v = fail[r];
                    if(~u) {
                        *e++ = u;
                        fail[u] = chd[v][i];
                        flag[u] |= flag[ fail[u] ];
                    }
                    else u = chd[v][i];
                }
            }
        }
        Matrix Get_Matrix() {
            Matrix ret(sz);
            ret.Set_Zero();
            for(int i = 0; i < sz; ++i) {
                if(flag[i])continue;
                for(int j = 0; j < CHILD_NUM; ++j) {
                    if(flag[ chd[i][j] ])continue;
                    ++ret.d[i][ chd[i][j] ] ;
                }
            }
            return ret;
        }
} AC;
char s[13];
int main() {
    int m;
    LL n;
    AC.Initialize();
    while(~scanf("%d%I64d", &m, &n)) {
        AC.Reset();
        for(int i = 0; i < m; ++i) {
            scanf("%s", s);
            AC.Insert(s);
        }
        AC.Construct();
        Matrix mt = AC.Get_Matrix();
        //mt.pf();
        mt = mt.Power(n);
        //mt.pf();
        LL res = 0;
        for(int i = 0; i < AC.sz; ++i) {
            if(!AC.flag[i])res += mt.d[0][i];
            res %= mod;
        }
        printf("%I64d\n", res);
    }
    return 0;
}
