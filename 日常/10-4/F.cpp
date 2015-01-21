/********************

Game Optimization

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

int n, m;
const int N = 1005;
char s[N][N];

int dis[N][N];
int from[N][N][2];
bool vis[N][N];
int main() {
    //freopen("Fin.txt","r",stdin);
    //freopen("Fout.txt","w",stdout);
    while(~scanf("%d%d", &n, &m)) {
        for(int i = 0; i < n; ++i) {
            scanf("%s", s[i]);
        }
        queue<int> Q;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(s[i][j] == '1') {
                    Q.push(i);
                    Q.push(j);
                    dis[i][j] = 0;
                    from[i][j][0] = i;
                    from[i][j][1] = j;
                    vis[i][j] = 1;
                }
                else {
                    vis[i][j] = 0;
                    dis[i][j] = 1e8;
                    from[i][j][0] = from[i][j][1] = -1;
                }
            }
        }
        while(!Q.empty()) {
            int x = Q.front();
            Q.pop();
            int y = Q.front();
            Q.pop();
            vis[x][y] = 0;
            int ox = from[x][y][0];
            int oy = from[x][y][1];
            for(int dx = -6; dx <= 6; ++dx) {
                for(int dy = -6; dy <= 6; ++dy) {
                    if(dx == 0 && dy == 0)continue;
                    else
                    {
                        int nx = dx + x;
                        int ny = dy + y;
                        if(nx >= 0 && nx < n && ny >= 0 && ny < m) {
                            if(sqr(ox - nx) + sqr(oy - ny) < dis[nx][ny]) {
                                dis[nx][ny] = sqr(ox - nx) + sqr(oy - ny);
                                from[nx][ny][0] = ox;
                                from[nx][ny][1] = oy;
                                if(!vis[nx][ny]) {
                                    vis[nx][ny] = 1;
                                    Q.push(nx);
                                    Q.push(ny);
                                }
                            }
                        }
                    }
                }
            }
        }
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                printf("%d%c", dis[i][j], j == m - 1 ? '\n' : ' ');
            }
        }
    }
    return 0;
}
