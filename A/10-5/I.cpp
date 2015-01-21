/********************Cdegree********************/
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

const int N = 100005;

map<int,int> mp;

int a[N], b[N];
int cnt[N];




int main() {
    int n, m;
    while(~scanf("%d", &n)) {
        int where = 0;
        sp.clear();
        for(int i = 0; i < n; ++i) {
            scanf("%d", a + i);
            if(a[i] == 0)where = 1;
        }
        scanf("%d", &m);
        for(int i = 0; i < m; ++i) {
            scanf("%d", b + i);
            if(b[i] == 0)where = 2;
        }
        memset(cnt, 0, sizeof(cnt));
        if(where == 2) {
            int p = n - m + 1;
            for(int i = 0; i < p; ++i) {
                cnt[ a[i] ]++;
                mp.
            }
        }
        else {

        }
    }
    return 0;
}
