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
typedef long long LL ;
template<typename T> void checkmin(T &x, T y) {x = min(x, y);}
template<typename T> void checkmax(T &x, T y) {x = max(x, y);}

const int N = 100050;

struct NODE {
    int a, b;
    int id;
} nd[N];

int q[N],res[N];
int main() {
    int n;
    while(~scanf("%d", &n)) {
        int a, b;
        for(int i = 0; i < n; ++i) {
            scanf("%d%d", &a, &b);
            nd[i].a = a;
            nd[i].b = b;
            nd[i].id = i + 1;
        }
        int m;
        scanf("%d", &m);
        for(int i = 0; i < m; ++i) {
            scanf("%d", q + i);
        }
        stack<int> S;
        for(int i = 0, j = 0; i < m; ++i) {
            while(nd[j].a<=q[i]&&j<n)S.push(j++);
            while(!S.empty()&&nd[S.top()].b<q[i])S.pop();
            if(S.empty())res[i]=-1;
            else res[i]=nd[S.top()].id;
        }
        for(int i = 0; i < m; ++i) {
            printf("%d\n", res[i]);
        }
    }
    return 0;
}
