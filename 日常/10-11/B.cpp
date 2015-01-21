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

typedef unsigned long long uLL;

uLL gaon(uLL n) {
    if(n == 0 || n == 1)return 0;
    uLL l = 0, r = 1e12, mid, ans;
    while(l <= r) {
        mid = (l + r) / 2;
        double tmp = mid;
        if(tmp * tmp > n + 2) {
            r = mid - 1;
        }
        else if(mid * mid > n) {
            r = mid - 1;
        }
        else {
            ans = mid;
            l = mid + 1;
        }
    }
    //printf("ans = %I64u\n",ans);
    int cnt = -1;
    if(ans & 1)++cnt;
    return n / 2 - 1 + cnt;
}
int main() {
    /*
    for(int n = 1; n <= 100; n+=2) {
        printf("%d : %d\n", n/2, gao(n));
    }
    */
    int T;
    for(int i=1;0&&i<=100;++i)
    {
        printf("%d : %I64u\n",i,gaon(i));
    }
    scanf("%d", &T);
    while(T--) {
        uLL a, b;
        scanf("%I64u%I64u", &a, &b);
        printf("%I64u\n", gaon(b) - gaon(a - 1));
    }
    return 0;
}
