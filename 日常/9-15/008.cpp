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
    freopen("08in.txt", "w", stdout);
    int T = 20;
    for(int t = 0; t < T; ++t) {
        int n = 1000;
        printf("%d\n", n);
        for(int i = 1; i <= n; ++i) {
            printf("%d ", i);
        }
    }
    puts("");
    return 0;
}
