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

struct song {
    int id;
    int len;
    double f;
} S[1<<16];
bool cmp(song a, song b) {
    return a.len * b.f < b.len * a.f;
}
int main() {
    int n;
    while(~scanf("%d", &n)) {
        for(int i = 1; i <= n; ++i) {
            scanf("%d %d %lf", &S[i].id, &S[i].len, &S[i].f);
        }
        int m;
        scanf("%d", &m);
        sort(S + 1, S + n + 1, cmp);
        printf("%d\n", S[m].id);
    }
    return 0;
}
