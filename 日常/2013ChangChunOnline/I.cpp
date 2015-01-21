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
using namespace std;
typedef long long LL ;

const int N = 55;
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
        ret.n = n;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                ret.d[i][j] = 0;
                for(int k = 0; k < n; ++k) {
                    ret.d[i][j] += d[i][k] * x.d[k][j] ;
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
        }
    }
}

Matrix Power(Matrix x, int n, int mod) {
    Matrix a(mod), b(mod);
    a.Set_One();
    b = x;
    while(n) {
        if(n & 1)a = a.Mul(b, mod);
        b = b.Mul(b, mod);
        n >>= 1;
    }
    return a;
}

int BellNumber(int x, int id) {
    int n = m[id];
    if(x < n) {
        return bell[x][id];
    }
    Matrix a(n), b(n), ret(n);
    a.Set_Zero();
    b.Set_Zero();
    for(int i = 0; i < n; ++i) {
        b.d[i][0] = bell[i][id];
    }
    for(int i = 0; i < n; ++i) {
        a.d[i][i] = a.d[i][(i+1)%n] = 1;
    }
    a.d[n - 1][1] = 1;
    int cnt = x / n;
    int pos = x % n;
    ret = Power(a, cnt, n);
    ret = ret.Mul(b, n);
    return ret.d[pos][0];
}

LL Ex_gcd(LL a, LL b, LL &x, LL &y) {
    if(b == 0) {x = 1; y = 0; return a;}
    LL d = Ex_gcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

LL CRT() {
    LL M = 1;
    for(int i = 0; i < 5; ++i)M *= m[i];
    LL res = 0;
    for(int i = 0; i < 5; ++i) {
        LL Mi = M / m[i];
        LL x, y;
        LL d = Ex_gcd(Mi, m[i], x, y);
        res = (res + x * Mi * r[i]) % M;
    }
    return res;
}

int main() {
    int n, T;
    Init();
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        for(int i = 0; i < 5; ++i) {
            r[i] = BellNumber(n, i);
        }
        int res = CRT();
        printf("%d\n", res);
    }
    return 0;
}
