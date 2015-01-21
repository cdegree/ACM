/********************

LightOJ 1057

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

const int K = 17, N = 22;
int dp[K][1<<K];
char s[N][N];

vector<pair<int, int> > pi;

int dis[K][K];
void pf(int mask, int n) {
    for(int i = 0; i < n; ++i) {
        if((mask >> i) & 1)putchar('1');
        else putchar('0');
    } puts("");
}
int main() {
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; ++t) {
        int n, m;
        scanf("%d %d", &n, &m);
        for(int i = 0; i < n; ++i)scanf("%s", s[i]);
        pi.clear();
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(s[i][j] == 'x') {
                    pi.push_back(make_pair(i, j));
                }
            }
        }
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(s[i][j] == 'g') {
                    pi.push_back(make_pair(i, j));
                }
            }
        }
        n = pi.size();
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                dis[i][j] = max(abs(pi[i].X - pi[j].X) , abs(pi[i].Y - pi[j].Y));
            }
        }
        memset(dp, -1, sizeof(dp));
        dp[0][0] = 0;
        for(int mask = 0; mask < (1 << n); ++mask) {
            for(int i = 0; i < n; ++i) {
                if(~dp[i][mask]) {
                    //pf(mask,n);
                    for(int j = 0; j < n; ++j) {
                        if(!((mask >> j) & 1)) {
                            if(~dp[j][mask|(1<<j)])checkmin(dp[j][mask|(1<<j)], dp[i][mask] + dis[i][j]);
                            else dp[j][mask|(1<<j)] = dp[i][mask] + dis[i][j];
                        }
                    }
                }
            }
        }
        printf("Case %d: %d\n", t, dp[0][(1<<n)-1]);
    }
    return 0;
}
