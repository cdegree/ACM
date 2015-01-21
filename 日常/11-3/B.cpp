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
typedef long long LL ;
template<typename T> void checkmin(T &x, T y) {x = min(x, y);}
template<typename T> void checkmax(T &x, T y) {x = max(x, y);}

LL n, m;
map<string, int> mp;
string trans[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov" , "Dec"};
struct Order {
    char s[7];
    string str;
    int d, y, H, R;
    int m;
    LL pos;
} Or[2555];
bool isrui(int y) {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}
LL sum[3333], msum[13];
void init() {
    mp.clear();
    for(int i = 0; i < 12; ++i) {
        mp[ trans[i] ] = i + 1;
    }
    sum[2000] = 0;
    for(int i = 2001; i < 2300; ++i) {
        sum[i] = sum[i-1] + 365 + (isrui(i - 1) ? 1 : 0);
    }
    msum[0] = 0;
    msum[1] = 31;
    msum[2] = 28;
    msum[3] = 31;
    msum[4] = 30;
    msum[5] = 31;
    msum[6] = 30;
    msum[7] = 31;
    msum[8] = 31;
    msum[9] = 30;
    msum[10] = 31;
    msum[11] = 30;
    msum[12] = 31;
    for(int i = 1; i <= 12; ++i) {
        msum[i] = msum[i-1] + msum[i];
    }
}

void gao(Order &a) {
    LL pos = 0;
    pos += sum[ a.y ];
    pos += msum[ a.m -1];

    if(isrui(a.y)) {
        if(a.m > 2)++pos;
        pos += a.d - 1;
        //printf("pos = %I64d\n", pos);
        pos *= 24;
        pos += a.H;
    }
    else {
        pos += a.d - 1;
        //printf("pos = %I64d\n", pos);
        pos *= 24;
        pos += a.H;
    }
    a.pos = pos + 1;
}

const int maxn = 100005;
LL dp_min[maxn][25];
void rmq_init(LL *c, int n) {
    for(int i = 1; i <= n; ++i)dp_min[i][0] = c[i];
    double limit = log(1.0 * n) / log(2.0);
    for(int j = 1; j <= (int)limit; ++j) {
        for(int i = 1; i + (1 << j) - 1 <= n; ++i) {
            dp_min[i][j] = min(dp_min[i][j-1], dp_min[i+(1<<(j-1))][j-1]);
        }
    }
}
LL get_min(int a, int b) {
    int k = (int)(log(b - a + 1.0) / log(2.0));
    //printf("%d -> %d\n",a,b);
    return min(dp_min[a][k], dp_min[b-(1<<k)+1][k]);
}

LL T, S;
LL cost[100000+5];
int main() {
    init();
    while(~scanf("%I64d %I64d", &n, &m)) {
        if(n == 0 && m == 0)break;
        for(int i = 0; i < n; ++i) {
            scanf("%s %d %d %d %d", Or[i].s, &Or[i].d, &Or[i].y, &Or[i].H, &Or[i].R);
            Or[i].str = Or[i].s;
            Or[i].m = mp[ Or[i].str ] ;
            gao(Or[i]);
            //printf("t = %I64d\n", Or[i].pos);
        }
        scanf("%I64d %I64d", &T, &S);
        for(int i = 1; i <= m; ++i) {
            scanf("%I64d", cost + i);
            cost[i] += (m - i) * S;
        }
        rmq_init(cost, m);
        LL res = 0;
        for(int i = 0; i < n; ++i) {
            LL from = max(1LL, Or[i].pos - T);
            LL to = Or[i].pos;
            LL mn = get_min(from, to) - (m - Or[i].pos) * S;
            //puts("FF");
            res += mn * Or[i].R;
            //printf("res = %I64d\n", res);
        }
        printf("%I64d\n", res);
    }
    return 0;
}
