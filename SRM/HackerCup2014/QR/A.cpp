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
int main() {
    int T;
    freopen("square_detector.txt","r",stdin);
    freopen("Aout.txt","w",stdout);
    scanf("%d", &T);
    for(int t = 1; t <= T; ++t) {
        int n;
        scanf("%d", &n);
        int cnt=0;
        for(int i = 0; i < n; ++i)scanf("%s", s[i]);
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                cnt += s[i][j] == '#';
            }
        }
        int len = 0;
        for(int i = 1; i <= 20; ++i) {
            if(i*i == cnt) {
                len = i;
                break;
            }
        }
        printf("Case #%d: ", t);
        if(len == 0) {
            puts("NO");
            continue;
        }
        bool hack = false;
        for(int i = 0; i + len <= n; ++i) {
            for(int j = 0; j + len <= n; ++j) {
                bool OK = true;
                for(int i1 = 0; i1 < len; ++i1) {
                    for(int j1 = 0; j1 < len; ++j1) {
                        if(s[i+i1][j+j1] != '#') {
                            OK = false;
                        }
                    }
                }
                if(OK)hack = true;
            }
        }
        if(hack)puts("YES");
        else puts("NO");
    }
    return 0;
}
