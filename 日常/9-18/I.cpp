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

string dp[N][N], rdp[N][N];
string s;
int main() {
    int T;
    int n, k;
    scanf("%d", &T);
    for(int t = 1; t <= T; ++t) {
        scanf("%d%d", &n, &k);
        cin >> s;
        for(int i = 0; i <= n; ++i) {
            string tmp = s.substr(0, i);
            dp[i][0] = tmp;
            reverse(tmp.begin(), tmp.end());
            rdp[i][0] = tmp;
        }
        string res = s;
        for(int j = 1; j <= k; ++j) {
            for(int i = j; i <= n; ++i) {
                dp[i][j] = s[i-1] + rdp[i-1][j-1];

                if(i != j)dp[i][j] = min(dp[i][j], dp[i-1][j] + s[i-1]);

                rdp[i][j] =  dp[i-1][j-1] + s[i-1];

                if(i != j)rdp[i][j] = min(rdp[i][j], s[i-1] + rdp[i-1][j]);

                checkmin(res, dp[i][j] + s.substr(i, n - i));

            }
        }
        printf("Case %d: %s\n", t, res.c_str());
    }
    return 0;
}
