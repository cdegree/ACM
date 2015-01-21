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



int main() {
    LL n;
    while(~scanf("%I64d", &n)) {
        if(n & 1) {
            if(n == 5) {
                printf("0 0\n");
            }
            else {
                printf("%I64d 0\n", (n / 2 - 1)*n);
            }
            continue;
        }
        if(n == 4) {
            printf("%I64d %I64d\n", 0LL, 2LL);
        }
        else if(n == 6) {
            printf("%I64d %I64d\n", 6LL, 9LL);
        }
        else {
            printf("%I64d %I64d\n", n*(n - 3) / 2, n*(n - 3) / 2);
        }
    }
    return 0;
}
