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

int init_state[12][12], end_state[12][12];


void init() {
    for(int i = 0; i < 12; ++i) {
        for(int j = 0; j < 11; ++j) {
            init_state[i][j] = i;
        }
    }
}

void turn(int id, int k) {

}

void pf() {
    for(int i = 0; i < 12; ++i) {
        for(int j = 0; j < 11; ++j) {
            printf("%d%c", init_state[i][j], j == 10 ? '\n' : ' ');
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; ++t) {
        init();
        int n, p, k;
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) {
            scanf("%d%d", &p, &k);
        }
        pf();
    }
    return 0;
}
