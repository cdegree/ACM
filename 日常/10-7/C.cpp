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

const int N = 1005;
const int M = 100;
int mp[105][105];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int main() {
    int n;
    while(~scanf("%d", &n)) {
        if(n==0)break;
        memset(mp, 0, sizeof(mp));
        for(int i = 0; i < n; ++i) {
            int x, y;
            scanf("%d%d", &x, &y);
            mp[x][y] = 1;
        }
        int res = n * 4;
        for(int i = 0; i <= M; ++i) {
            for(int j = 0; j <= M; ++j) {
                if(mp[i][j] == 1) {
                    for(int k = 0; k < 4; ++k) {
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if(nx >= 0 && ny >= 0 && nx <= M && ny <= M) {
                            if(mp[nx][ny] == 1)

                            {
                                --res;
                            }
                        }
                    }
                }
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
