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


int cnt[4][10], ncnt[4][10];

int ID[256];
char TP[256];
void Init() {
    ID['m'] = 0;
    ID['s'] = 1;
    ID['p'] = 2;
    ID['c'] = 3;
    TP[0] = 'm';
    TP[1] = 's';
    TP[2] = 'p';
    TP[3] = 'c';
}
void pf() {
    for(int i = 0; i < 3; ++i) {
        for(int j = 1; j <= 9; ++j) {
            printf("%d ", cnt[i][j]);
        } puts("");
    }
    for(int j = 1; j <= 7; ++j) {
        printf("%d ", ncnt[3][j]);
    } puts("");
}

char s[6];
int num;
bool Clear() {
    int sum = 0;
    for(int i = 0; i < 4; ++i) {
        int up = (i == 3) ? 7 : 9;
        for(int j = 1; j <= up; ++j) {
            sum += ncnt[i][j];
            if(sum)break;
        }
        if(sum)break;
    }
    return sum == 0;
}
void cp() {
    for(int i = 0; i < 4; ++i)for(int j = 1; j <= 9; ++j)ncnt[i][j] = cnt[i][j];
}
bool Win2() {
    bool OK = true;
    int pcnt = 0;
    for(int i = 0; i < 3; ++i) {
        if(ncnt[i][1] == 0 || ncnt[i][9] == 0) {
            OK = false;
            break;
        }
        pcnt += ncnt[i][1] + ncnt[i][9];
    }
    for(int i = 1; i <= 7 && OK; ++i) {
        if(ncnt[3][i] == 0) {
            OK = false;
            break;
        }
        pcnt += ncnt[3][i];
    }
    return pcnt == 14 && OK;
}
bool Lwin() {
    bool OK = true;
    for(int i = 0; i < 3; ++i) {
        for(int j = 1; j <= 9; ++j) {
            if(ncnt[i][j] >= 3)ncnt[i][j] -= 3;
            if(j <= 7) {
                while(ncnt[i][j] >= 1 && ncnt[i][j+1] >= 1 && ncnt[i][j+2] >= 1) {
                    --ncnt[i][j];
                    --ncnt[i][j+1];
                    --ncnt[i][j+2];
                }
            }
            if(ncnt[i][j] > 0) {
                OK = false;
                break;
            }
        }
    }
    for(int j = 1; j <= 7 && OK; ++j) {
        if(ncnt[3][j] == 3)ncnt[3][j] -= 3;
        if(ncnt[3][j]>0)OK=false;
    }
    return OK;
}
bool Win() {
    bool OK = true;
    cp();
    for(int i = 0; i < 3; ++i) {
        for(int j = 1; j <= 9 && OK; ++j) {
            if(ncnt[i][j]>=2)ncnt[i][j]-=2;
        }
    }
    for(int j = 1; j <= 7 && OK; ++j) {
        if(ncnt[3][j]>=2)ncnt[3][j]-=2;
    }
    if(Clear()) {
        OK = true;
    }
    else {
        OK = false;
        cp();
        if(Win2()) {
            OK = true;
        }
        else {
            cp();
            for(int i = 0; i < 4; ++i) {
                int up = (i == 3) ? 7 : 9;
                for(int j = 1; j <= up && !OK; ++j) {
                    if(ncnt[i][j] >= 2) {
                        ncnt[i][j] -= 2;
                        if(Lwin()) {
                            OK = true;
                            break;
                        }
                        cp();
                    }
                }
            }
        }
    }
    return OK;
}
struct Res {
    int p;
    char tp;
} R[555];
void gao() {
    int len = 0;
    for(int i = 0; i < 3; ++i) {
        for(int j = 1; j <= 9; ++j) {
            if(cnt[i][j] == 4)continue;
            ++cnt[i][j];
            if(Win()) {
                R[len].p = j;
                R[len++].tp = TP[i];
            }
            --cnt[i][j];
        }
    }
    for(int j = 1; j <= 7; ++j) {
        if(cnt[3][j] == 4)continue;
        ++cnt[3][j];
        if(Win()) {
            R[len].p = j;
            R[len++].tp = TP[3];
        }
        --cnt[3][j];
    }
    if(len == 0) {
        puts("Nooten");
    }
    else {
        printf("%d", len);
        for(int i = 0; i < len; ++i) {
            printf(" %d%c", R[i].p, R[i].tp);
        }
        puts("");
    }
}


int main() {
    int T;
    Init();
    scanf("%d", &T);
    while(T--) {
        memset(cnt, 0, sizeof(cnt));
        for(int i = 0; i < 13; ++i) {
            scanf("%s", s);
            int id = ID[s[1]];
            cnt[id][ s[0]-'0' ]++;
        }
        gao();
    }
    return 0;
}
