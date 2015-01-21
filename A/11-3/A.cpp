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

const int N = 11;
int mp[N][N], atk[N][N];
int n, x, y;
int ID[256];
void init() {
    ID['G'] = 0;
    ID['R'] = 1;
    ID['H'] = 2;
    ID['C'] = 3;
}
struct qizi {
    int x, y, id;
    char s[3];
} Q[9];
int dx[] = {1, -1, 1, -1, 2, 2, -2, -2};
int dy[] = {2, 2, -2, -2, 1, -1, 1, -1};
int odx[] = {0, 0, 1, -1};
int ody[] = {1, -1, 0, 0};
bool In(int x, int y) {
    return x >= 1 && y >= 1 && x <= 10 && y <= 10;
}
bool inside(int x, int y) {
    return x >= 1 && x <= 3 && y >= 4 && y <= 6;
}
bool gao() {
    memset(mp, -1, sizeof(mp));
    memset(atk, 0, sizeof(atk));
    for(int i = 0; i < n; ++i) {
        mp[ Q[i].x ][ Q[i].y ] = Q[i].id;
    }
    for(int i = 1; i <= 10; ++i) {
        for(int j = 1; j <= 10; ++j) {
            if(~mp[i][j]) {
                if(mp[i][j] == 2) {
                    for(int k = 0; k < 8; ++k) {
                        int nx = dx[k] + i;
                        int ny = dy[k] + j;
                        //printf("%d %d\n",nx,ny);
                        if(In(nx, ny) && mp[ i+odx[k/2] ][ j+ody[k/2] ] == -1) {
                            atk[nx][ny] = 1;
                        }
                    }
                }
                else if(mp[i][j] == 0) {
                    int nx = i - 1, ny = j;
                    while(In(nx, ny)) {
                        atk[nx][ny] = 1;
                        if(~mp[nx][ny])break;
                        --nx;
                    }
                }
                else if(mp[i][j] == 1) {
                    int nx = i - 1, ny = j;
                    while(In(nx, ny)) {
                        atk[nx][ny] = 1;
                        if(~mp[nx][ny])break;
                        --nx;
                    }
                    nx = i + 1, ny = j;
                    while(In(nx, ny)) {
                        atk[nx][ny] = 1;
                        if(~mp[nx][ny])break;
                        ++nx;
                    }
                    nx = i, ny = j - 1;
                    while(In(nx, ny)) {
                        atk[nx][ny] = 1;
                        if(~mp[nx][ny])break;
                        --ny;
                    }
                    nx = i, ny = j + 1;
                    while(In(nx, ny)) {
                        atk[nx][ny] = 1;
                        if(~mp[nx][ny])break;
                        ++ny;
                    }
                }
                else {
                    for(int k = 0; k < 4; ++k) {
                        int adx = odx[k];
                        int ady = ody[k];
                        int nx = i + adx;
                        int ny = j + ady;
                        while(In(nx, ny) && mp[nx][ny] == -1) {
                            nx += adx;
                            ny += ady;
                        }
                        if(In(nx, ny)) {
                            nx += adx;
                            ny += ady;
                            while(In(nx, ny)) {
                                atk[nx][ny] = 1;
                                if(~mp[nx][ny])break;
                                nx += adx;
                                ny += ady;
                            }
                        }
                    }
                }
            }
        }
    }
    /*
    for(int i = 1; i <= 10; ++i) {
        for(int j = 1; j <= 10; ++j) {
            printf("%3d", atk[i][j]);
        }
        puts("");
    }
    */
    int ok = 1;
    for(int k = 0; k < 4; ++k) {
        int nx = x + odx[k];
        int ny = y + ody[k];
        if(inside(nx, ny) && !atk[nx][ny]) {
            ok = 0;
        }
    }
    return ok;
}
int main() {
    init();
    while(~scanf("%d %d %d", &n, &x, &y)) {
        if(n == 0 && x == 0 && y == 0)break;
        for(int i = 0; i < n; ++i) {
            scanf("%s %d %d", Q[i].s, &Q[i].x, &Q[i].y);
            Q[i].id = ID[ Q[i].s[0] ];
        }
        bool win = gao();
        for(int i = 0; i < n; ++i) {
            if(Q[i].id == 0 && Q[i].y == y) {
                bool clear = 1;
                for(int j = x + 1; j < Q[i].x; ++j) {
                    if(~mp[j][y]) {
                        clear = 0;
                    }
                }
                if(clear) {
                    win = 0;
                }
            }
        }
        printf("%s\n", win ? "YES" : "NO");
    }
    return 0;
}
