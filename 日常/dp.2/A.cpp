/********************

LightOJ 1050

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

const int N = 505;
double dp[N][N];
const double eps = 1e-7;

void init() {
    memset(dp, 0, sizeof(dp));
    int n = 500;
    for(int i = 0; i <= n; ++i)dp[0][i] = 1;
    for(int i = 1; i <= n; ++i) {
        for(int j = i + 1; j <= n; ++j) {
            if((i + j) % 2 == 0)continue;
            dp[i][j] = dp[i-1][j-1] * i / (i + j) + dp[i][j-2] * j / (i + j);
        }
    }
}


int main() {
    int T, R, B;
    init();
    scanf("%d", &T);
    for(int t = 1; t <= T; ++t) {
        scanf("%d %d", &R, &B);
        printf("Case %d: %.12f\n", t, dp[R][B]);
    }
    return 0;
}
