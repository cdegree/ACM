#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
#define rep(i,a,b) for (int i=a;i<=b;++i)
typedef long long ll;
const int N = 105;
inline ll sqr(ll x) {return x * x;}
struct node {
    int x, y; void read() {scanf("%d%d", &x, &y);}
    double dist(const node &A) {return sqrt(double(sqr(x - A.x) + sqr(y - A.y)));}
} a[N], b[N];
double f[N][N][N], F[N][N], ans; int n, head, g[N][N][N], G[N][N];
void prt(bool first, int h, int l, int r) {
    if(l == r) {
        if(!first) printf(" ");
        printf("%d+ %d-", r, r);
    }
    else {
        if(h == r) {
            if(!first) printf(" ");
            printf("%d+", r);
            prt(0, g[h][l][r], l, r - 1);
            printf(" %d-", r);
        }
        else prt(first, h, l, h), prt(0, g[h][l][r], h + 1, r);
    }
}
int main() {
    while(scanf("%d", &n) != EOF) {
        rep(i, 1, n) a[i].read(), b[i].read();
        ans = 1e20;
        rep(i, 1, n) rep(j, 1, n) {
            F[i][j] = 1e20;
            rep(k, j, n) f[i][j][k] = 1e20;
        }
        rep(i, 1, n) {
            f[i][i][i] = a[i].dist(b[i]), F[i][i] = f[i][i][i] + a[i].dist(b[i-1]), G[i][i] = i;
        }
        rep(l, 1, n) {
            rep(i, 1, n - l) {
                int j = i + l;
                rep(k, i, j) {
                    if(k < j) {
                        f[k][i][j] = f[k][i][k] + F[k+1][j], g[k][i][j] = G[k+1][j];
                    }
                    else {
                        rep(c, i, j - 1) {
                            if(f[c][i][j-1] + a[j].dist(a[c]) + b[j].dist(b[j-1]) < f[k][i][j]) {
                                f[k][i][j] = f[c][i][j-1] + a[j].dist(a[c]) + b[j].dist(b[j-1]), g[k][i][j] = c;
                            }
                        }
                    }
                    if(f[k][i][j] + a[k].dist(b[i-1]) < F[i][j]) {
                        F[i][j] = f[k][i][j] + a[k].dist(b[i-1]), G[i][j] = k;
                    }
                }
            }
        }
        rep(i, 1, n) if(f[i][1][n] < ans) ans = f[i][1][n], head = i;
        prt(1, head, 1, n), puts("");
    }
    return 0;
}
