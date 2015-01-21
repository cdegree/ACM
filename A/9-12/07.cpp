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


LL F(LL x) {
    LL e = 1;
    LL ret = 0;
    while(x > 0) {
        ret += (x % 10) * e;
        x /= 10;
        e <<= 1;
    }
    return ret;
}

int main() {
    freopen("07out.txt", "w", stdout);
    int n = 10000;
    for(int i = 0; i <= n; ++i) {
        printf("%5d : %9lld\n", i, F(i));
    }
    return 0;
}
