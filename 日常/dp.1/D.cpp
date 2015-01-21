/********************

LightOJ 1032

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

LL dp[33][2][2][33];
int d[33];
void init(LL n) {
    for(int i = 0; i < 33; ++i) {
        d[i] = (n >> i) & 1;
    }
    //reverse(d, d + 33);
    for(int i = 0; i < 33; ++i) {
        //printf("%d", d[i]);
    } //puts("");
}
LL gao(int pos, int pre, int pred, LL cnt) {

    if(pos == -1) {
        return cnt;
    }
    else {
        LL &ret = dp[pos][pre][pred][cnt];
        if(~ret)return ret;
        ret = 0;
        int up = pre ? 1 : d[pos];
        //printf("pos = %d pre = %d pred = %d cnt = %lld\n", pos, pre, pred, cnt);
        for(int i = 0; i <= up; ++i) {
            //printf("i=%d ", i);
            int add = pred && i;
            ret += gao(pos - 1, pre || i < d[pos], i, cnt + add);
        } //puts("");
        //printf("ret = %lld\n", ret);
        return ret;
    }
}

LL get_res(LL n) {
    init(n);
    memset(dp, -1, sizeof(dp));
    LL ret = gao(32, 0, 0, 0);
    return ret;
}
int main() {
    int T;
    LL n;
    scanf("%d", &T);
    for(int t = 1; t <= T; ++t) {
        scanf("%I64d", &n);
        LL res = get_res(n);
        printf("Case %d: %lld\n", t, res);
    }
    return 0;
}
