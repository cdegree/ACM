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

int d[55];
LL dp[55][2];
LL n, k;
void init() {
    //printf("%lld %lld\n",n,k);
    memset(d, 0, sizeof(d));
    for(int i = 0; i < 51; ++i) {
        d[i] = n % k;
        n /= k;
    }
    memset(dp, -1, sizeof(dp));
}


LL gao(int p, bool over) {
    if(p == -1) {
        return 1;
    }
    else {
        //printf("%d %d\n",p,over);
        LL &ret = dp[p][over];
        if(~ret)return ret;
        ret = 0;
        int up = over ? (k - 1) : d[p];
        if(p & 1) {
            ret += gao(p - 1, 0 < up || over);
        }
        else {
            for(int i = 0; i <= up; ++i) {
                ret += gao(p - 1, i < up || over);
            }
        }
        return ret;
    }
}

int main() {
    while(~scanf("%lld %lld", &n, &k)) {
        init();
        LL res = gao(50, 0);
        printf("%lld\n", res);
    }
    return 0;
}
