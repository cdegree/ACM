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


int cnt[11];
int b[12][12];

int h, w, c;

pair<int, int> get_next(pair<int, int> p) {
    if(p.X % 2 == 0) {
        if(p.Y < w - 1) {
            p.Y++;
        }
        else {
            p.X++;
        }
    }
    else {
        if(p.Y > 0) {
            --p.Y;
        }
        else {
            ++p.X;
        }
    }
    return p;
}
const int N = 300003;
char s[N];

const int MAX_NODE = 300003 * 52 + 3;
const int CHILD_NUM = 2;

int chd[MAX_NODE][2];
int val[MAX_NODE];
int main() {

    while(~scanf("%d%d%d", &h, &w, &c)) {
        for(int i = 0; i < c; ++i) {
            scanf("%d", cnt + i);
        }
        pair<int, int> p;
        for(int i = 0; i < c; ++i) {
            while(cnt[i]--) {
                b[ p.X ][ p.Y ] = i + 1;
                //printf("%d %d\n",p.X,p.Y);
                p = get_next(p);
            }
        }
        for(int i = 0; i < h; ++i) {
            for(int j = 0; j < w; ++j) {
                printf("%d", b[i][j]);
            } puts("");
        }
    }
    return 0;
}
