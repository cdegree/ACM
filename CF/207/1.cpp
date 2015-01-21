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

const int N = 300005;

int l[N], r[N], x[N];
int f[N];
int main() {
    int n, m;
    while(~scanf("%d%d", &n, &m)) {
        memset(f, 0, sizeof(f));

        for(int i = 0; i < m; ++i) {
            scanf("%d%d%d", l + i, r + i, x + i);
        }
        set<int> st;
        for(int i = 1; i <= n; ++i) {
            st.insert(i);
        }
        for(int i = 0; i < m; ++i) {
            set<int>::iterator it = st.lower_bound(l[i]);
            set<int>::iterator jt = st.upper_bound(r[i]);
            //printf("%d %d\n", *it, *jt);
            while(it != jt) {
                //printf("%d %d\n", *it, *jt);
                if(*it == x[i]) {
                    ++it;
                }
                else {
                    f[*it] = x[i];
                    int t = *it;
                    ++it;
                    st.erase(t);
                }
            }
        }
        for(int i = 1; i <= n; ++i) {
            printf("%d%c", f[i], i == n ? '\n' : ' ');
        }
    }
    return 0;
}
