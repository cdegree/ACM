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

const int N = 133;
LL dis[N][N];

struct point {
    double x, y;
} P[N];

double eps = 1e-8;
LL get_dis(point a, point b) {
    return ceil(sqrt(sqr(a.x - b.x) + sqr(a.y - b.y)));
}
bool vis[N];
int n;
LL D;
bool BFS() {
    memset(vis, false, sizeof(vis));
    queue<int> Q;
    Q.push(0);
    int cnt = 1;
    vis[0] = 1;
    while(!Q.empty()) {
        int u = Q.front(); Q.pop();
        for(int i = 0; i < n; ++i) {
            if(!vis[i] && dis[u][i] <= D) {
                vis[i] = 1;
                ++cnt;
                Q.push(i);
            }
        }
    }
    return cnt == n;
}
bool used[N];
bool Can() {
    memset(used, 0, sizeof(used));
    queue<int> Q;
    Q.push(0);
    used[0] = 1;
    int cnt = 1;
    while(!Q.empty()) {
        int u = Q.front(); Q.pop();
        for(int i = 0; i < n; ++i) {
            if(vis[i] && !used[i] && dis[u][i] <= D) {
                ++cnt;
                used[i] = 1;
                Q.push(i);
            }
            else if(!vis[i]&&!used[i] && dis[u][i] * 2 <= D) {
                ++cnt;
                used[i]=1;
            }
        }
    }
    return cnt == n;
}

int main() {
    while(~scanf("%d %I64d", &n, &D)) {
        for(int i = 0; i < n; ++i) {
            scanf("%lf %lf", &P[i].x, &P[i].y);
        }
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                dis[i][j] = get_dis(P[i], P[j]);
            }
        }
        if(!BFS()) {
            puts("-1");
        }
        else {
            string res(n, '1');
            for(int i = n - 1; i >= 1; --i) {
                vis[i] = 0;
                if(Can()) {
                    res[i] = '0';
                }
                else {
                    vis[i] = 1;
                }
            }
            while(res[res.size()-1]=='0')res.erase(res.begin()+res.size()-1);
            reverse(res.begin(),res.end());
            printf("%s\n", res.c_str());
        }
    }
    return 0;
}
