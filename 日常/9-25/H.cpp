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


struct player {
    int kick[3];
} P[33][2];
char s[3][22];
int get_kick(char *s) {
    if(s[0] == 'y')return 1;
    return 0;
}
int sc[2];
void take_next(int id, int k) {
    int i = id / 11;
    if(i > 2)i = 0;
    int j = id % 11;
    sc[k] += P[j][k].kick[i];
}
void gao() {
    int cnt = 0;
    int id = 0;
    while(cnt < 5) {
        ++cnt;
        //printf("%d %d\n", sc1, sc2);
        take_next(cnt - 1, 0);
        if( sc[0]+ 5-cnt < sc[1] || sc[0] > sc[1] + 5-cnt+1 )break;
        take_next(cnt - 1, 1);
        if(abs(sc[0] - sc[1]) > 5 - cnt)break;
    }
    if(sc[0] != sc[1])return ;
    while(1) {
        ++cnt;
        //
        //printf("%d %d\n", sc1, sc2);
        take_next(cnt - 1, 0);
        take_next(cnt - 1, 1);
        //if(cnt == 34)while(1);
        if(sc[0] != sc[1])break;
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; ++t) {
        for(int k = 0; k < 2; ++k) {
            for(int i = 0; i < 11; ++i) {
                for(int j = 0; j < 3; ++j) {
                    scanf("%s", s[j]);
                    P[i][k].kick[j] = get_kick(s[j]);
                }
            }
        }
        printf("Match %d:\n", t);
        sc[0] = sc[1] = 0;
        gao();

        if(sc[0] > sc[1]) {
            puts("Winner: home");
        }
        else {
            puts("Winner: away");
        }
        printf("Score: %d:%d\n", sc[0], sc[1]);
    }
    return 0;
}
