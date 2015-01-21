/********************
CF_203_1
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
int a[N], b[N];
int main() {
    int n, m;
    while(cin >> n >> m) {
        int mn = 1e7, mnw = 1e7,mx=0;
        for(int i = 1; i <= n; ++i) {cin >> a[i]; checkmin(mn, a[i]); checkmax(mx,a[i]); }
        for(int i = 1; i <= m; ++i) {cin >> b[i]; checkmin(mnw, b[i]);}
        int res = -1;
        for(int i = mx; i < mnw; ++i) {
            if(2*mn<= i  ) {
                res = i;
                break;
            }
        }
        cout << res << endl;
    }
    return 0;
}
