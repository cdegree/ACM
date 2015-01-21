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
    int n;
    while(~scanf("%d", &n)) {
        LL res = 0;
        set<LL> st;
        set<LL>::iterator it, jt;
        LL b;
        for(int i = 0; i < n; ++i) {
            scanf("%lld", &b);
            LL a = b;
            it = st.lower_bound(a);
            if(st.empty()) {
                res += a;
            }
            else {
                LL mn = 1e12;

                if(it != st.end()) {
                    //printf("*it = %d\n",*it);
                    mn = min(mn, abs(a - *it));
                }
                if(it != st.begin()) {
                    --it;
                    //printf("*it = %d\n",*it);
                    mn = min(mn, abs(a - *it));
                }
                //puts("");
                res += mn;
            }
            st.insert(a);
            //printf("res = %lld\n", res);
        }
        printf("%lld\n",res);
    }
    return 0;
}
