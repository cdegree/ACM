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


const int N = 2005;
int a[N], b[N], c[1000005];
vector<int> pos[N];
set<int> st;
set<int>::iterator it;
int main() {
    int n;
    while(~scanf("%d", &n)) {
        if(n==0)break;
        for(int i = 1; i <= n; ++i) {
            scanf("%d", a + i);
        }
        bool allsame=1;
        for(int i=2;i<=n;++i)
        {
            if(a[i]!=a[i+1])
            {
                allsame=0;
            }
        }
        if(allsame)
        {
            printf("%d\n",n);
            continue;
        }
        int m = 2 * n - 1;
        int res = 0;
        for(int v = 1; v <= n; ++v) {
            int k = n - v + 1;
            for(int j = 1; j <= n; --k, ++j) {
                if(k == 0)k = n;
                b[j] = a[k];
            }
            for(int i = 1; i <= n; ++i) {
                pos[i].clear();
            }
            for(int i = 1; i <= n; ++i) {
                pos[ b[i] ].push_back(i);
            }
            for(int i = 1; i <= n; ++i) {
                sort(pos[i].begin(), pos[i].end());
            }
            st.clear();
            int len = 0;
            for(int i = 1; i <= n; ++i) {
                int m = pos[ a[i] ].size();
                for(int j = m - 1; j >= 0; --j) {
                    c[len++] = pos[ a[i] ][j];
                }
            }

            for(int i = 0; i < len; ++i) {
                it = st.lower_bound(c[i]);
                if(it == st.end()) {
                    st.insert(c[i]);
                }
                else {
                    st.erase(*it);
                    st.insert(c[i]);
                }
            }
            checkmax(res, (int)st.size());
        }
        printf("%d\n", res);
    }
    return 0;
}
