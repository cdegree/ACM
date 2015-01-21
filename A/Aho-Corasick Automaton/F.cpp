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
typedef unsigned long long uLL;
template<typename T> void checkmin(T &x, T y) {x = min(x, y);}
template<typename T> void checkmax(T &x, T y) {x = max(x, y);}

const int MAX_NODE = 26;
const int CHILD_NUM = 26;

class Matrix {
    public:
        uLL d[MAX_NODE][MAX_NODE];
        int m;
        Matrix() {}
        Matrix(int _m): m(_m) {};
        void Set_Zero() {
            memset(d, 0, sizeof(d));
        }
        void Set_One() {
            Set_Zero();
            for(int i = 0; i < m; ++i)d[i][i] = 1;
        }
        Matrix operator +(Matrix a) {
            Matrix ret(m);
            for(int i = 0; i < m; ++i)for(int j = 0; j < m; ++j)ret.d[i][j] = d[i][j] + a.d[i][j];
            return ret;
        }
        Matrix operator *(Matrix a) {
            Matrix ret(m);
            ret.Set_Zero();
            for(int i = 0; i < m; ++i) {
                for(int k = 0; k < m; ++k) {
                    if(d[i][k] == 0)continue;
                    for(int j = 0; j < m; ++j) {
                        ret.d[i][j] += d[i][k] * a.d[k][j];
                    }
                }
            }
            return ret;
        }
        Matrix Power(LL n) {
            Matrix a(m), b(m);
            a = *this;
            b.Set_One();
            while(n) {
                if(n & 1)b = b * a;
                a = a * a;
                n >>= 1;
            }
            return b;
        }
        Matrix Get_Power_Sum(LL n) {
            Matrix ret;
            if(n == 1)return *this;
            if(n & 1) {
                ret = Get_Power_Sum(n / 2);
                ret = ret + ret * Power(n / 2) + Power(n);
            }
            else {
                ret = Get_Power_Sum(n / 2);
                ret = ret + ret * Power(n / 2);
            }
            return ret;
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
        int val[MAX_NODE];
        int ID[126];
        int Q[MAX_NODE];
        int fail[MAX_NODE];
        int sz;
        void Initialize() {
            fail[0] = 0;
            for(int i = 0; i < 26; ++i) {
                ID['a'+i] = i;
            }
        }
        void Reset() {
            sz = 1;
            memset(chd[0], -1, sizeof(chd[0]));
        }
        void Insert(char *s) {
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
            val[q] = 1;
        }
        void Construct() {
            int *s = Q, *e = Q;
            for(int i = 0; i < CHILD_NUM; ++i) {
                if(~chd[0][i]) {
                    fail[ chd[0][i] ] = 0;
                    *s++ = chd[0][i];
                }
                else chd[0][i] = 0;
            }
            while(s != e) {
                int r = *e++;
                for(int i = 0; i < CHILD_NUM; ++i) {
                    int &u = chd[r][i];
                    int v = fail[r];
                    if(~u) {
                        *s++ = u;
                        fail[u] = chd[v][i];
                        val[u] |= val[ fail[u] ];
                    }
                    else u = chd[v][i];
                }
            }
        }
        Matrix Get_Matrix() {
            Matrix ret(sz);
            ret.Set_Zero();
            for(int i = 0; i < sz; ++i) {
                if(val[i])continue;
                for(int j = 0; j < CHILD_NUM; ++j) {
                    if(val[ chd[i][j] ])continue;
                    ++ret.d[i][ chd[i][j] ];
                }
            }
            return ret;
        }
} AC;
const uLL K = 26;

uLL Power(uLL x, LL n) {
    uLL a = x, b = 1;
    while(n) {
        if(n & 1)b *= a;
        a *= a;
        n >>= 1;
    }
    return b;
}

uLL Get_PS(LL n) {
    //cout<<n<<endl;
    if(n == 1)return K;
    uLL ret, a, b;
    if(n & 1) {
        ret = Get_PS(n / 2);
        ret = ret + ret * Power(K, n / 2) + Power(K, n);
    }
    else {
        ret = Get_PS(n / 2);
        ret = ret + ret * Power(K, n / 2);
    }
    return ret;
}

char s[7];
int main() {
    int n;
    uLL L;
    AC.Initialize();
    while(~scanf("%d%I64u", &n, &L)) {
        uLL sum = 0;
        uLL e = 1;
        AC.Reset();
        sum = Get_PS(L);
        //printf("%I64u\n",sum);
        for(uLL i = 0; i < n; ++i) {
            scanf("%s", s);
            AC.Insert(s);
        }
        AC.Construct();
        Matrix a = AC.Get_Matrix();
        //a.pf();
        Matrix b = a.Get_Power_Sum(L) ;
        uLL res = 0;
        for(int j = 0; j < b.m; ++j) {
            res += b.d[0][j];
        }
        res = sum - res;
        printf("%I64u\n", res);
    }
    return 0;
}
