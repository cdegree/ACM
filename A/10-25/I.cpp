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

const int N = 5005;
const LL mod = 1e9 + 7;
LL dp[N];

int main() {
    int n;
    //freopen("Iin.txt","r",stdin);
    //freopen("Iout.txt","w",stdout);
    while(~scanf("%d", &n)) {
        dp[1] = 1;
        for(int i = 2; i <= n; ++i) {
            LL ii = i;
            dp[i] = 0;
            for(int j = i - 1; j >= 1; --j) {
                dp[i] = (dp[i] - dp[j] * ii + mod*ii) % mod;
                ii = ii * i % mod;
            }
            dp[i] = (dp[i] + ii) % mod;
        }
        printf("%I64d\n", dp[n]);
        //fflush(stdout);
    }
    return 0;
}
