/********************
CF_203_2
Author:Cdegree

********************/
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
int from[N];
int outd[N], ind[N];
int tp[N];
int main() {
    int n;
    while(cin >> n) {
        for(int i = 1; i <= n; ++i) {
            cin >> tp[i];
        }
        memset(outd, 0, sizeof(outd));
        for(int i = 1; i <= n; ++i) {
            cin >> from[i];
            ++outd[ from[i] ];
        }
        vector<int> path, tmp;
        for(int i = 1; i <= n; ++i) {
            if(tp[i] == 1) {
                tmp.clear();
                int now = i;
                tmp.push_back(now);
                //printf("%d %d %d\n",from[now],tp[from[now]],outd[ from[now] ]);
                while(from[now] && tp[from[now]] == 0 && outd[ from[now] ] == 1) {
                    now = from[now];
                    tmp.push_back(now);
                }
                if(tmp.size() > path.size()) {
                    path = tmp;
                }
            }
        }
        printf("%d\n", path.size());
        for(int i = path.size() - 1; i >= 0; --i) {
            printf("%d%c", path[i], i == 0 ? '\n' : ' ');
        }
    }
    return 0;
}
