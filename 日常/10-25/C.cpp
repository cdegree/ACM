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

const int N = 256;
int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[] = {1, -1, 0, 0, 1, -1, -1, 1};
int n, m;
char s[N*2][N*2];
int dis[N][N][8];
bool vis[N][N][8];
int pass[N][N][4];
inline bool In(int x, int y) {
    return x >= 1 && y >= 1 && x <= 2 * n && y <= 2 * m;
}

void init() {
    memset(pass, -1, sizeof(pass));
    for(int i = 0; i <= n + 1; ++i) {

        pass[i][0][2] = 0;
        pass[i][m+1][2] = 0;
        pass[i][0][3] = 0;
        pass[i][m+1][3] = 0;
    }
    for(int i = 0; i <= m + 1; ++i) {
        pass[0][i][0] = 0;
        pass[n+1][i][0] = 0;
        pass[0][i][1] = 0;
        pass[n+1][i][1] = 0;
    }
    pass[0][0][1] = -1, pass[0][0][3] = -1;
    pass[0][m+1][0] = -1, pass[0][m+1][3] = -1;
    pass[n+1][0][2] = -1, pass[n+1][0][1] = -1;
    pass[n+1][m+1][0] = -1, pass[n+1][m+1][2] = -1;

    for(int i = 1; i <= m; ++i) {
        int ny = i * 2 - 1;
        if(s[0][ny] == '.') {
            pass[0][i][2] = 1;
        }
        if(s[2*n][ny] == '.') {
            pass[n+1][i][3] = 1;
        }
    }
    for(int i = 1; i <= n; ++i) {
        int nx = i * 2 - 1;
        if(s[nx][0] == '.') {
            pass[i][0][0] = 1;
        }
        if(s[nx][2*m] == '.') {
            pass[i][m+1][1] = 1;
        }
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            int x = 2 * i + 1;
            int y = 2 * j + 1;
            for(int k = 0; k < 4; ++k) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if(nx >= 0 && ny >= 0 && nx < 2 * n + 1 && ny < 2 * m + 1 && s[nx][ny] == '.') {
                    pass[i+1][j+1][k] = 1;
                }
            }
        }
    }
}

int get_dir(int ox, int oy, int x2, int y2) {
    for(int k = 0; k < 8; ++k) {
        int nx = ox + dx[k];
        int ny = oy + dy[k];
        if(nx == x2 && ny == y2) {
            return k;
        }
    }
    return -1;
}
bool OUT(int x, int y) {
    return x < 1 || x > n || y < 1 || y > m;
}
bool inside(int x, int y) {
    return x >= 0 && x <= n + 1 && y >= 0 && y <= m + 1;
}
int BFS(int ox, int oy, int _dir) {
    memset(vis, false, sizeof(vis));
    queue<int> Q;
    Q.push(ox);
    Q.push(oy);
    Q.push(_dir);
    for(int i = 0; i < N; ++i)for(int j = 0; j < N; ++j)for(int k = 0; k < 8; ++k)dis[i][j][k] = 2e8;
    dis[ox][oy][_dir] = 0;
    vis[ox][oy][_dir] = 1;
    while(!Q.empty()) {
        int x = Q.front(); Q.pop();
        int y = Q.front(); Q.pop();
        int dir = Q.front(); Q.pop();

        vis[x][y][dir] = false;
        int x2 = x + dx[dir];
        int y2 = y + dy[dir];
        //printf("1: (%d,%d)\t2: (%d,%d)\n", x, y, x2, y2);
        for(int k = 0; k < 4; ++k) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(inside(nx, ny) && abs(nx - x2) <= 1 && abs(ny - y2) <= 1 && (nx != x2 || ny != y2) && ~pass[x][y][k]) {
                int ndir = get_dir(nx, ny, x2, y2);
                //printf("1 to (%d,%d) ndir = %d\n", nx, ny, ndir);
                if(dis[x][y][dir] + pass[x][y][k] < dis[nx][ny][ndir]) {
                    dis[nx][ny][ndir] = dis[x][y][dir] + pass[x][y][k];
                    if(!vis[nx][ny][ndir]) {
                        vis[nx][ny][ndir] = true;
                        Q.push(nx);
                        Q.push(ny);
                        Q.push(ndir);
                        //puts("push");
                    }
                }
            }
        }

        for(int k = 0; k < 4; ++k) {
            int nx = x2 + dx[k];
            int ny = y2 + dy[k];
            if(inside(nx, ny) && abs(nx - x) <= 1 && abs(ny - y) <= 1 && (nx != x || ny != y) && ~pass[x2][y2][k]) {
                int ndir = get_dir(x, y, nx, ny);
                //printf("2 to (%d,%d)  ndir = %d\n", nx, ny, ndir);
                if(dis[x][y][dir] + pass[x2][y2][k] < dis[x][y][ndir]) {
                    dis[x][y][ndir] = dis[x][y][dir] + pass[x2][y2][k];
                    if(!vis[x][y][ndir]) {
                        vis[x][y][ndir] = true;
                        Q.push(x);
                        Q.push(y);
                        Q.push(ndir);
                        //puts("push");
                    }
                }
            }
        }
    }
    int ret = 2e8;
    for(int i = 0; i <= n + 1; ++i) {
        for(int j = 0; j <= m + 1; ++j) {
            if(OUT(i, j)) {
                for(int k = 0; k < 8; ++k) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(OUT(nx, ny) && nx >= 0 && ny >= 0 && nx <= n + 1 && ny <= m + 1) {
                        checkmin(ret, dis[i][j][k]);
                    }
                }
            }
        }
    }
    return ret == 2e8 ? -1 : ret;
}
int main() {
    //freopen("Cin.txt", "r", stdin);
    while(~scanf("%d %d ", &n, &m)) {
        //gets(s[0]);
        for(int i = 0; i < n * 2 + 1; ++i) {
            gets(s[i]);
        }
        for(int i = 0; i < n * 2 + 1; ++i) {
            //puts(s[i]);
        }
        init();
        bool found = false;
        int ox = -1, oy = -1, dir = -1;
        for(int i = 0; i < n && !found; ++i) {
            for(int j = 0; j < m && !found; ++j) {
                int x = 2 * i + 1;
                int y = 2 * j + 1;
                if(s[x][y] == '1') {
                    for(int k = 0; k < 8 && !found; ++k) {
                        int nx = (i + dx[k]) * 2 + 1;
                        int ny = (j + dy[k]) * 2 + 1;
                        if(In(nx , ny) && s[nx][ny] == '2') {
                            found = true;
                            ox = i + 1, oy = j + 1, dir = k;
                        }
                    }
                }
            }
        }
        //printf("%d %d  dir = %d\n", ox, oy, dir);
        int res = BFS(ox, oy, dir);
        if(res == -1)puts("Death");
        else printf("%d\n", res);
    }
    return 0;
}
