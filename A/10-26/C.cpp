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

const int N = 500005;
int h1[N], h2[N];
char s[22];
struct NODE {
    int val, pre, next;
} nd[N*3];

int cnt;
int main() {
    int n, m;
    int c, p;
    while(~scanf("%d%d", &n, &m)) {
        cnt = 0;
        memset(h1, -1, sizeof(h1));
        memset(h2, -1, sizeof(h2));
        int len = 1;
        for(int i = 0; i < n; ++i) {
            scanf("%s", s);
            if(strcmp(s, "learn") == 0) {
                scanf("%d%d", &c, &p);
                if(h1[c] == -1) {
                    nd[cnt].val = p;
                    nd[cnt].pre = -1;
                    h1[c] = cnt++;
                }
                else {
                    nd[cnt].val = p;
                    nd[cnt].pre = h1[c];
                    nd[h1 [c] ].next = cnt;
                    h1[c] = cnt++;
                }
            }
            else if(strcmp(s, "rollback") == 0) {
                scanf("%d",&c);
                int pre = nd[ h1[c] ].pre;
                int val = nd[ h1[c] ].val;
                h1[c] = pre;
                if(h2[c]==-1)
                {
                    nd[cnt].val = val;
                    nd[cnt].pre = -1;
                    h2[c] = cnt++;
                }
                else
                {
                    nd[cnt].val = val;
                    nd[cnt].pre = h2[c];
                    nd[h2 [c] ].next = cnt;
                    h2[c] = cnt++;
                }
            }
            else if(strcmp(s, "relearn") == 0) {
                scanf("%d",&c);
                int pre = nd[ h2[c] ].pre;
                int val = nd[ h2[c] ].val;
                h2[c] = pre;
                if(h1[c]==-1)
                {
                    nd[cnt].val = val;
                    nd[cnt].pre = -1;
                    h1[c] = cnt++;
                }
                else
                {
                    nd[cnt].val = val;
                    nd[cnt].pre = h1[c];
                    nd[h1 [c] ].next = cnt;
                    h1[c] = cnt++;
                }
            }
            else if(strcmp(s, "clone") == 0) {
                scanf("%d", &c);
                h1[++len] = h1[c];
                h2[len] = h2[c];
            }
            else if(strcmp(s, "check") == 0) {
                scanf("%d", &c);
                if(h1[c] == -1) {
                    puts("basic");
                }
                else {
                    printf("%d\n", nd[ h1[c] ].val);
                }
            }
        }
    }
    return 0;
}
