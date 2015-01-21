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


double res;
double C[202][202];
void init() {
    for(int i = 0; i <= 200; ++i) {
        C[i][0] = C[i][i] = 1;
    }
    for(int i = 1; i <= 200; ++i) {
        for(int j = 1; j <= 200; ++j) {
            C[i][j] = C[i-1][j-1] + C[i-1][j];
            //printf("%.0f ",C[i][j]);
        }
        //puts("");
    }
}
double dp[202][22];
double gao(int n, int k) {
    double &ret = dp[n][k];

    if(ret > -1) {
        return ret;
    }
    ret = 0;
    //printf("%d %d \n", n, k);
    if(k == 0) {
        return n;
    }
    int m = n - k;
    if(m <= k) {
        return 0;
    }
    else {
        double mx = 0;
        for(int i = 1; i <= k; ++i) {
            double e = 0;
            for(int j = 0; j <= i; ++j) {
                double tp = C[k][j] * C[m-k][i-j]  ;
                e += gao(m - i, k - j)/C[m][i]*C[k][j] * C[m-k][i-j]  ;
            }
            //printf("%.6f %.6f\n",mx,tmp);
            checkmax(mx, e);
        }
        //printf("%.6f\n", mx);
        return ret = mx;
    }
}
int main() {
    int n, k;
    init();
    while(~scanf("%d%d", &n, &k)) {
        res = 0;
        for(int i = 0; i <= 200; ++i) {
            for(int j = 0; j <= 20; ++j) {
                dp[i][j] = -3;
            }
        }
        res = gao(n, k);
        printf("%.9f\n", res);
    }
    return 0;
}
