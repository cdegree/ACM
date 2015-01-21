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
typedef long long LL ;
template<typename T> void checkmin(T &x, T y) {x = min(x, y);}
template<typename T> void checkmax(T &x, T y) {x = max(x, y);}

const int N = 100005;
struct card {
    int h, w;
    int tp;
} C[N*2];

bool cmp(card a, card b) {
    if(a.h != b.h) {
        return a.h < b.h;
    }
    else if(a.w != b.w) {
        return a.w < b.w;
    }
    else {
        return a.tp > b.tp;
    }
}

multiset<int> ms;
multiset<int>::iterator it;

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) {
            scanf("%d%d", &C[i].h, &C[i].w);
            C[i].tp = 0;
        }
        for(int i = n; i < n * 2; ++i) {
            scanf("%d%d", &C[i].h, &C[i].w);
            C[i].tp = 1;
        }
        ms.clear();
        sort(C, C + 2 * n, cmp);
        int cnt = 0, res = 0;
        for(int i = 0; i < 2 * n; ++i) {
            if(C[i].tp == 0) {
                it = ms.upper_bound(C[i].w);
                if(it != ms.begin()) {
                    --it;
                    ms.erase(it);
                    ++res;
                }
            }
            else {
                ms.insert(C[i].w);
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
