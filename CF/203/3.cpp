/********************

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
struct bombs {
    int x, y;
} B[N];

bool cmp(bombs a, bombs b) {
    return abs(a.x) + abs(a.y) < abs(b.x) + abs(b.y);
}

struct Operation {
    int tp;
    int k;
    char ch;
} Op[N*10];
int len;

char get_ch(int x, int y) {
    if(x == 0) {
        return y > 0 ? 'U' : 'D';
    }
    else {
        return x > 0 ? 'R' : 'L';
    }
}

void gao_x(int id) {
    Op[len].tp = 1;
    Op[len].k = abs(B[id].y);
    Op[len++].ch = get_ch(0, B[id].y);
    Op[len++].tp = 2;
    Op[len].tp = 1;
    Op[len].k = abs(B[id].y);
    Op[len++].ch = get_ch(0, -B[id].y);
    Op[len++].tp = 3;
}
void gao_y(int id) {
    Op[len].tp = 1;
    Op[len].k = abs(B[id].x);
    Op[len++].ch = get_ch(B[id].x, 0);
    Op[len++].tp = 2;
    Op[len].tp = 1;
    Op[len].k = abs(B[id].x);
    Op[len++].ch = get_ch(-B[id].x, 0);
    Op[len++].tp = 3;
}

void gao_xy(int id)
{
    Op[len].tp=1;
    Op[len].k=abs(B[id].x);
    Op[len++].ch = get_ch(B[id].x, 0);
    Op[len].tp = 1;
    Op[len].k = abs(B[id].y);
    Op[len++].ch = get_ch(0, B[id].y);
    Op[len++].tp = 2;
    Op[len].tp = 1;
    Op[len].k = abs(B[id].y);
    Op[len++].ch = get_ch(0, -B[id].y);
    Op[len].tp = 1;
    Op[len].k = abs(B[id].x);
    Op[len++].ch = get_ch(-B[id].x, 0);
    Op[len++].tp = 3;
}
void gao(int id) {
    if(B[id].x == 0) {
        gao_x(id);
    }
    else if(B[id].y == 0) {
        gao_y(id);
    }
    else {
        gao_xy(id);
    }
}
int n;
void gao() {
    len = 0;
    for(int i = 0; i < n; ++i) {
        gao(i);
    }
}
int main() {

    while(cin >> n) {
        for(int i = 0; i < n; ++i) {
            scanf("%d%d", &B[i].x, &B[i].y);
        }
        sort(B, B + n, cmp);
        gao();
        printf("%d\n", len);
        for(int i = 0; i < len; ++i) {
            if(Op[i].tp == 1) {
                printf("%d %d %c\n", 1, Op[i].k, Op[i].ch);
            }
            else {
                printf("%d\n", Op[i].tp);
            }
        }
    }
    return 0;
}
