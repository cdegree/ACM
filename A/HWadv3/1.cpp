#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 5005;
char s[N][N];
bool vis[N][N];
int dx[]= {0,0,1,-1};
int dy[]= {1,-1,0,0};
int r,c;
bool in(int x,int y) {
    return x>=0&&x<r&&y>=0&&y<c;
}
void bfs(int x,int y) {
    vis[x][y]=true;
    queue<int> Q;
    Q.push(x);
    Q.push(y);
    while(!Q.empty()) {
        int nr = Q.front();
        Q.pop();
        int nc = Q.front();
        Q.pop();
        for(int k=0; k<4; ++k) {
            int nx = nr+dx[k];
            int ny = nc+dy[k];
            if(in(nx,ny)&&!vis[nx][ny]&&s[nx][ny]!='#') {
                vis[nx][ny]=true;
                Q.push(nx);
                Q.push(ny);
            }
        }
    }
}

int main() {

    memset(vis,false,sizeof(vis));
    scanf("%d%d",&r,&c);
    for(int i=0; i<r; ++i) {
        scanf("%s",s[i]);
    }
    for(int i=0; i<r; ++i) {
        for(int j=0; j<c; ++j) {
            if(s[i][j]=='B') {
                bfs(i,j);
            }
        }
    }
    bool Can=false;
    for(int i=0; i<r; ++i) {
        for(int j=0; j<c; ++j) {
            if(s[i][j]=='H') {
                Can=vis[i][j];
            }
        }
    }
    printf("%c",Can?'Y':'N');
    return 0;
}
