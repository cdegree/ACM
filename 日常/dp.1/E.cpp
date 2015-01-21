/********************

LightOJ 1033

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

const int N = 105;
int dp[N][N];

char s[N];
int main() {
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; ++t) {
        scanf("%s", s);
        int n = strlen(s);
        for(int i = 0; i < n; ++i)dp[i][i] = 1;
        for(int l = 1; l < n; ++l) {
            for(int i = 0; i + l < n; ++i) {
                if(s[i] == s[i+l]) {
                    dp[i][i+l] = 2;
                    if(i + 1 <= i + l - 1)dp[i][i+l] += dp[i+1][i+l-1];
                }
                else {
                    dp[i][i+l] = max(dp[i+1][i+l], dp[i][i+l-1]);
                }
            }
        }
        printf("Case %d: %d\n", t, n - dp[0][n-1]);
    }
    return 0;
}
