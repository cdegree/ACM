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

const int N = 100005;
LL sum[N];
LL a[N], f[N];
int main() {
    LL n, m, k;
    while(~scanf("%I64d %I64d %I64d", &n, &m, &k)) {
        sum[0] = 0;
        for(int i = 1; i <= n; ++i) {
            scanf("%I64d", a + i);
            sum[i] = sum[i-1] + a[i];
        }

        for(int i = 0; i < m; ++i) {
            scanf("%I64d", f + i);
        }
        LL cur = 0;
        LL T = 0;
        for(int i = 0; i < m; ++i) {
            if(cur + f[i] - T > n) {
                T += n - cur;
                cur = n;
                break;
            }
            else {
                cur = cur + f[i] - T - 1;
                T += f[i] - T;
                int l = 0, r = cur, mid, ans = 0;
                while(l <= r) {
                    mid = (l + r) / 2;
                    if(sum[cur] - sum[mid] > k) {
                        ans = mid;
                        l = mid + 1;
                    }
                    else {
                        r = mid - 1;
                    }
                }
                cur = ans;
            }
            //printf("cur = %I64d T = %I64d\n",cur,T);
        }
        if(cur < n) {
            T += n - cur;
        }
        printf("%I64d\n", T);
    }
    return 0;
}
