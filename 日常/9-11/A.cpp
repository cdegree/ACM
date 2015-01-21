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
set<int>::iterator it;
typedef long long LL ;
template<typename T> void checkmin(T &x, T y) {x = min(x, y);}
template<typename T> void checkmax(T &x, T y) {x = max(x, y);}

set<int> st;
int main() {
    int n;
    char s[6];
    int v;
    while(~scanf("%d", &n)) {
        st.clear();
        while(n--) {
            scanf("%s", &s);
            if(s[0] == 's') {
                int i = 1;
                LL sum = 0;
                for(it = st.begin(); it != st.end(); ++it, ++i) {
                    if(i % 5 == 3)sum += *it;
                }
                printf("%I64d\n", sum);
            }
            else if(s[0] == 'a') {
                scanf("%d", &v);
                st.insert(v);
            }
            else {
                scanf("%d", &v);
                st.erase(v);
            }
        }
    }
    return 0;
}
