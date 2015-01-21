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


LL Power(LL x, LL n) {
    LL a = 1, b = x;
    while(n) {
        if(n & 1)a *= b;
        b *= b;
        n >>= 1;
    }
    return a;
}

LL eqution(LL x, LL y, LL z) {
    return Power(x, z) + Power(y, z) + x * y * z;
}

LL gao(LL K) {
    LL ret = 0;
    for(LL z = 2; z < 32; ++z) {
        for(LL y = 2; Power(y, z) + z*y <= K; ++y) {

            LL l = 1, r = y - 1, ans = -1, x;
            while(l <= r) {
                x = (l + r) >> 1;
                if(Power(x, z) + Power(y, z) >= K) {
                    r = x - 1;
                    continue;
                }
                LL t = eqution(x, y, z);
                if(t > K) {
                    r = x - 1;
                }
                else if(t == K) {
                    ans = x;
                    break;
                }
                else {
                    l = x + 1;
                }
            }
            if(~ans) {
                ++ret;
            }
        }
    }
    return ret;
}

int main() {
    LL K;
    while(~scanf("%I64d", &K), K) {
        LL res = gao(K);
        printf("%I64d\n", res);
    }
    return 0;
}
