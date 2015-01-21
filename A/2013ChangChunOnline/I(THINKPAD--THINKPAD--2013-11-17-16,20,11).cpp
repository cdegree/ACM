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

const int N = 55;
LL n;
int m[5] = {31, 37, 41, 43, 47};
int r[5];
int bell[N][5], C[N][N][5];
struct Matrix {
    int d[N][N];
    int n;
    Matrix() {}
    Matrix(int _n): n(_n) {}
    void Set_Zero() {
        memset(d, 0, sizeof(d));
    }
    void Set_One() {
        Set_Zero();
        for(int i = 0; i < n; ++i) {
            d[i][i] = 1;
        }
    }
    Matrix Mul(Matrix x, int mod) {
        Matrix ret;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                ret.d[i][j] = 0;
                for(int k = 0; k < n; ++k) {
                    ret.d[i][j] += d[i][k] * d[k][j] ;
                    ret.d[i][j] %= mod;
                }
            }
        }
        return ret;
    }
};
void Init() {
    for(int k = 0; k < 5; ++k) {
        for(int i = 0; i < N; ++i) {
            C[i][i][k] = C[i][0][k] = 1;
        }
        for(int i = 1; i < N; ++i) {
            for(int j = 1; j < i; ++j) {
                C[i][j][k] = (C[i-1][j-1][k] + C[i-1][j][k]) % m[k];
            }
        }
    }
    for(int k = 0; k < 5; ++k) {
        bell[0][k] = 1;
        for(int i = 1; i < N; ++i) {
            bell[i][k] = 0;
            for(int j = 0; j < i; ++j) {
                bell[i][k] = (bell[i][k] +  C[i-1][j][k] * bell[j][k]) % m[k];
            }
            //printf("bell[%d]%%%d=%d\n",i,m[k],bell[i][k]);
        }
    }
}

Matrix Power(Matrix x, int n, int id) {
    Matrix ret(m[id]);
    ret.Set_One();
    if(n == 0)return ret;
    if(n & 1) {
        ret = Power(x, n - 1, id);
        ret = ret.Mul(x, m[id]);
    }
    else {
        ret = Power(x, n / 2, id);
        ret = ret.Mul(ret, m[id]);
    }
    return ret;
}


int BellNumber(int n, int id) {
    if(n < N) {
        return bell[n][id];
    }
    Matrix a(m[id]), b(m[id]), ret(m[id]);
    a.Set_Zero();
    b.Set_Zero();
    for(int i = 0; i < m[id]; ++i) {
        b.d[i][0] = bell[i][id];
    }
    for(int i = 0; i < m[id]; ++i) {
        a.d[i][i] = a.d[i][(i+1)%m[id]] = 1;
    }
    a.d[m[id] - 1][1] = 1;
    int cnt = n / m[id];
    int pos = n % m[id];
    a = Power(a, cnt, id);
    ret = a.Mul(b, m[id]);
    return ret.d[pos][0];
}

int Ex_gcd(int a, int b, int &x, int &y) {
    if(b == 0) {x = 1; y = 0; return a;}
    int d = Ex_gcd(b, a % b, y, x);
    x = y;
    y -= a / b * x;
    return d;
}

int CRT() {
    int M = 1;
    for(int i = 0; i < 5; ++i)M *= m[i];
    int res = 0;
    for(int i = 0; i < 5; ++i) {
        int Mi = M / m[i];
        int x, y;
        Ex_gcd(Mi, m[i], x, y);
        res = (res + x * M[i] * r[i]) % M;
    }
    return res;
}


int main() {
    int T;
    Init();
    scanf("%d", &T);
    while(T--) {
        scanf("%I64d", &n);
        //printf("%d\n", BellNumber(n, 0));
        for(int i = 0; i < 5; ++i) {
            r[i] = BellNumber(n, i);
        }
        int res = CRT();
        printf("%d\n",res);
    }
    return 0;
}
