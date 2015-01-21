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


int main() {
    int T, n;
    scanf("%d", &T);
    for(int t = 1; t <= T; ++t) {
        scanf("%d", &n);
        int n1 = 0, sum = 0;
        for(int i = 0; i < n; ++i) {
            int a;
            scanf("%d", &a);
            if(a > 0)++n1;
            sum += abs(a);
        }
        printf("Case %d: ", t);
        if(n1 == 0) {
            puts("inf");
        }
        else {
            int g = __gcd(sum, n1);
            printf("%d/%d\n", sum / g, n1 / g);
        }
    }
    return 0;
}
