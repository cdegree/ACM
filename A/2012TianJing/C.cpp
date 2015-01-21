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

const int N = 1005;
char s1[N], s2[N];

int dp[N][10][10];

void update(int &a, int b) {
    if(a == -1)a = b;
    else a = min(a, b);
}
int main() {
    while(~scanf("%s %s", s1, s2)) {
        int n = strlen(s1);
        memset(dp, -1, sizeof(dp));
        dp[0][0][0] = 0;
        for(int i = 1; i <= n; ++i) {
            for(int j = 0; j < 10; ++j) {
                for(int k = 0; k < 10; ++k) {
                    if(~dp[i-1][j][k]) {
                        int t = (s2[i-1] - s1[i-1] + 10) % 10;
                        t = (t - j + 10) % 10;
                        for(int j2 = 0; j2 <= t; ++j2) {
                            for(int k2 = 0; k2 <= j2; ++k2) {
                                update(dp[i][(k+j2)%10][k2], dp[i-1][j][k] + t);
                            }
                        }
                        t = (10 - t) % 10;
                        for(int j2 = 0; j2 <= t; ++j2) {
                            for(int k2 = 0; k2 <= j2; ++k2) {
                                update(dp[i][(k-j2+10)%10][(-k2+10)%10], dp[i-1][j][k] + t);
                            }
                        }
                    }
                }
            }
        }
        int res = dp[n][0][0];
        printf("%d\n", res);
    }
    return 0;
}
