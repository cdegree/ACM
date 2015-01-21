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
int a[N];
int main() {
    int n, k, p;
    while(~scanf("%d%d%d", &n, &k, &p)) {
        for(int i = 1; i <= n; ++i) {
            a[i] = 1;
        }
        for(int i = n; i >= n - k + 1; --i) {
            a[i] = 2;
        }
        int cntl = 0 , cnt = n - k - 1;
        int pre = 1;
        for(int i = n - k + 1; i <= n; ++i) {
            a[i] = a[i-1];
            ++cnt;
            if(p*cnt <= 100 * cntl) {
                continue;
            }
            else {
                a[i] = a[i-1] + 1;
                cntl = cnt;
            }
        }
        LL sum = 0;
        for(int i = 1; i <= n; ++i) {
            sum += a[i];
        }
        printf("%I64d\n", sum);
        for(int i = 1; i <= n; ++i) {
            printf("%d%c", a[i], i == n ? '\n' : ' ');
        }
    }
    return 0;
}
