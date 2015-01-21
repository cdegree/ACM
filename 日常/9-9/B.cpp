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

int f[1005], ans[1005];

double inf = 0x7FFFFFFFFFFFFFFFLL;
LL gao(LL x) {
    int sub = 0;
    if(x == 1 || x == 0)return 0;

    LL l=0,r=0x7FFFFFFFFFFFFFFFLL,mid,ans;

    while(l<=r)
    {
        mid = (l+r)>>1;
        if( sqr((double)mid)>inf)
        {
            r = mid - 1;
        }
        else if( sqr(mid) >x )
        {
            r = mid - 1;
            ans = mid;
        }
        else
        {
            l = mid + 1;
        }
    }

    return x / 2 - (ans&1) - 1;
}

int main() {
    /*
    freopen("Bin.txt", "r", stdin);
    freopen("Bout.txt","w",stdout);
    int x, fx;
    int len = 1;
    while(~scanf("%d %d", &x, f + len)) {
        ++len;
    }
    int cnt = 0;
    for(int i = 1; i <= 1000; ++i) {
        if(f[i] & 1)++cnt;
        ans[i] = cnt;
        printf("ans[%d]= %d -> %d  %d\n", i,i/2, ans[i], ans[i] - i/2 );
    }
    */
    LL n;
    int T;
    scanf("%d", &T);
    while(T--) {
        LL x, y;
        scanf("%I64d %I64d", &x, &y);
        printf("%I64d\n", gao(y) - gao(x - 1));
    }
    return 0;
}
