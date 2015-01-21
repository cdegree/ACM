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

char s[22][22];
int n;

int dp[22][22][2];
int gao(int x, int y, int k) {
    int &ret = dp[x][y][k];
    if(ret != 12345)return ret;
    ret = 0;
    if(x == n - 1 && y == n - 1) {
        return ret = 0;
    }
    else {
        int c = 0;
        bool rv = 0;
        if(x < n - 1 && y < n - 1 && s[x+1][y] == s[x][y+1]) {
            rv = 1;
        }
        int t1, t2;
        if(k) {
            int mn = 555;

            if(x < n - 1) {
                if(s[x+1][y] == 'a')c = 1;
                else if(s[x+1][y] == 'b')c = -1;
                else c = 0;
                t1 = gao(x + 1, y, k ^ 1) + c;
                checkmin(mn, t1);
            }
            if(y < n - 1) {
                if(s[x][y+1] == 'a')c = 1;
                else if(s[x][y+1] == 'b')c = -1;
                else c = 0;
                t2 = gao(x, y + 1, k ^ 1) + c;
                checkmin(mn, t2);
            }
            if(rv) {
                mn = max(t1, t2);
            }
            //printf("%d %d mn= %d\n", x, y, mn);
            ret = mn;
        }
        else {
            int mx = -555;
            if(x < n - 1) {
                if(s[x+1][y] == 'a')c = 1;
                else if(s[x+1][y] == 'b')c = -1;
                else c = 0;
                t1 = gao(x + 1, y, k ^ 1) + c;
                checkmax(mx, t1);
            }
            if(y < n - 1) {
                if(s[x][y+1] == 'a')c = 1;
                else if(s[x][y+1] == 'b')c = -1;
                else c = 0;
                t2 = gao(x, y + 1, k ^ 1) + c;
                checkmax(mx, t2);
            }
            if(rv) {
                mx = min(t1, t2);
            }
            //printf("%d %d mx= %d\n", x, y, mx);
            ret = mx;
        }
        return ret;
    }
}

/*
int dp[33][33];
void pf() {
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            printf("%8d", dp[i][j]);
        } puts("");
    }
}
*/

int main() {

    while(~scanf("%d", &n)) {
        for(int i = 0; i < n; ++i)for(int j = 0; j < n; ++j)dp[i][j][0] = dp[i][j][1] = 12345;
        for(int i = 0; i < n; ++i) {
            scanf("%s", s[i]);
        }
        int c = 0;
        if(s[0][0] == 'a')c = 1;
        else if(s[0][0] == 'b')c = -1;
        int res = gao(0, 0, 1) + c;
        //int res = c;
        /*
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if((i + j) & 1) dp[i][j] = -55555;
                else dp[i][j] = 55555;
            }
        }
        dp[n-1][n-1]=0;
        for(int i = n - 1; i >= 0; --i) {
            for(int j = n - 1; j >= 0; --j) {
                if(i==n-1&&j==n-1)continue;
                if((i + j) & 1) {
                    if(i < n - 1) {
                        if(s[i+1][j] == 'a')c = 1;
                        else if(s[i+1][j] == 'b')c = -1;
                        else c = 0;
                        checkmax(dp[i][j], dp[i+1][j] + c);
                    } if(j < n - 1) {
                        if(s[i][j+1] == 'a')c = 1;
                        else if(s[i][j+1] == 'b')c = -1;
                        else c = 0;
                        checkmax(dp[i][j], dp[i][j+1] + c);
                    }
                }
                else{
                    if(i < n - 1) {
                        if(s[i+1][j] == 'a')c = 1;
                        else if(s[i+1][j] == 'b')c = -1;
                        else c = 0;
                        checkmin(dp[i][j], dp[i+1][j] + c);
                    } if(j < n - 1) {
                        if(s[i][j+1] == 'a')c = 1;
                        else if(s[i][j+1] == 'b')c = -1;
                        else c = 0;
                        checkmin(dp[i][j], dp[i][j+1] + c);
                    }
                }
            }
        }
        res += dp[0][0];
        //pf();
        //printf("%d\n", res);
        */
        if(res > 0) {
            puts("FIRST");
        }
        else if(res == 0) {
            puts("DRAW");
        }
        else {
            puts("SECOND");
        }
    }
    return 0;
}
