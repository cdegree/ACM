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
#include <ctime>
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

const int N = 105;
LL dis[N][N];
bool vis[N*10];
LL b[N*10][3];
int main() {
    int n, m;
    LL L;
    while(~scanf("%d%d%lld", &n, &m, &L)) {
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                dis[i][j] =(i == j) ? 0 : L;
            }
        }
        int u, v;
        LL w;
        for(int i = 0; i < m; ++i) {
            scanf("%d%d%lld", &u, &v, &w);
            --u, --v;
            b[i][0] = u, b[i][1] = v, b[i][2] = w;
            dis[u][v] = dis[v][u] = min(w, dis[u][v]);
        }
        memset(vis, 0, sizeof(vis));
        for(int k = 0; k < n; ++k) {
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < n; ++j) {
                    checkmin(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }
        LL res1 = 0, res2 = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                res1 += dis[i][j];
            }
        }
        //printf("%lld %lld\n", res1, res2);
        res2 = res1;
        srand(clock());
        for(int q = 0; q < 900; ++q) {

            int id;
            int cnt = 0;
            do {
                ++cnt;
                if(cnt > 1000)break;
                id = rand() % m;
            }
            while(vis[id]);
            if(cnt > 1000)break;
            vis[id] = 1;
            for(int i = 0; i < m; ++i) {
                if(i == id)continue;
                dis[b[i][0]][b[i][1]] = dis[b[i][1]][b[i][0]] = b[i][2];
            }
            for(int k = 0; k < n; ++k) {
                for(int i = 0; i < n; ++i) {
                    for(int j = 0; j < n; ++j) {
                        checkmin(dis[i][j], dis[i][k] + dis[k][j]);
                    }
                }
            }

            LL tmp = 0;
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < n; ++j) {
                    tmp += dis[i][j];
                }
            }
            checkmax(res2, tmp);
        }
        printf("%lld %lld\n", res1, res2);
    }
    return 0;
}
