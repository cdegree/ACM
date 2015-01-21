/********************

Author:Cdegree

********************/
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

int a[22], b[22];

int dp[22][22][22][22][2];

int gao(int i1, int j1, int i2, int j2, int k) {
    int ret = dp[i1][j1][i2][j2][k];
    if(~ret) {
        return ret;
    }
    else {
        //int ret;
        //printf("%d -> %d  %d -> %d k = %d\n", i1, j1, i2, j2, k);
        if(k == 0) {
            int mx = 0;
            if(i1 < j1)checkmax(mx, gao(i1 + 1, j1, i2, j2, 1) + a[i1]);
            if(i1 < j1)checkmax(mx, gao(i1, j1 - 1, i2, j2, 1) + a[j1-1]);
            if(i2 < j2)checkmax(mx, gao(i1, j1, i2 + 1, j2, 1) + b[i2]);
            if(i2 < j2)checkmax(mx, gao(i1, j1, i2, j2 - 1, 1) + b[j2-1]);
            //printf("mx = %d\n", mx);
            ret = mx;
        }
        else {
            int mn = 1e9;
            if(i1 < j1)checkmin(mn, gao(i1 + 1, j1, i2, j2, 0));
            if(i1 < j1)checkmin(mn, gao(i1, j1 - 1, i2, j2, 0));
            if(i2 < j2)checkmin(mn, gao(i1, j1, i2 + 1, j2, 0));
            if(i2 < j2)checkmin(mn, gao(i1, j1, i2, j2 - 1, 0));
            //printf("mn = %d\n", mn);
            ret = mn;
        }
        //printf("ret = %d\n", ret);
        return dp[i1][j1][i2][j2][k]=ret;
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) {
            scanf("%d", a + i);
        }
        for(int i = 0; i < n; ++i) {
            scanf("%d", b + i);
        }
        memset(dp,-1,sizeof(dp));
        int res = gao(0, n, 0, n , 0);
        printf("%d\n", res);
    }
    return 0;
}
