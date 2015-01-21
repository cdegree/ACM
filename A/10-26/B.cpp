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

const int N = 10005;
int a[N];
int main() {
    int n, k;
    while(~scanf("%d%d", &n, &k)) {
        for(int i = 0; i < n; ++i) {
            scanf("%d", a + i);
        }
        LL sum1 = 0, sum2 = 0;
        for(int i = 0; i < n; ++i) {
            if(a[i] >= k) {
                sum1 += a[i] - k;
            }
            else {
                sum2 += k - a[i];
            }
        }
        printf("%I64d %I64d\n", sum1, sum2);
    }
    return 0;
}
