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

const LL mod = 95041567;
const int N = 1005;
LL bell[N], C[N][N];
void init() {
    for(int i = 0; i < N; ++i) {
        C[i][i] = C[i][0] = 1;
    }
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < i; ++j) {
            C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
        }
    }
    bell[0] = 1;
    for(int i = 1; i < N; ++i) {
        bell[i] = 0;
        for(int j = 0; j < i; ++j) {
            bell[i] += C[i-1][j] * bell[j];
            bell[i] %= mod;
        }
    }
}
int main() {
    init();
    freopen("Iout.txt", "w", stdout);
    for(int n = 0; n <= 1000; ++n) {
        printf("%5d:%20lld\n", n, bell[n]);
    }
    return 0;
}
