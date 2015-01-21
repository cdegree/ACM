/********************

A - Graphics Settings

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

typedef long long LL ;
template<typename T> void checkmin(T &x, T y) {x = min(x, y);}
template<typename T> void checkmax(T &x, T y) {x = max(x, y);}


map<string, int> mp;
map<string, int>::iterator it;

char s[13], t[13];
const int N = 1000005;
struct Tree {
    int next[27];
    int v;
} Tr[N];
int len;
void init() {
    len = 1;
    memset(Tr[len-1].next, -1, sizeof(Tr[len-1].next));
    Tr[0].v = 1;
}

void insert(char *s, int v) {
    int i = 0;
    int rt = 0;
    while(s[i]) {
        int id = s[i] - 'a';
        if(~Tr[rt].next[id]) {
            rt = Tr[rt].next[id];
        }
        else {
            Tr[rt].next[id] = len++;
            rt = len - 1;
            memset(Tr[rt].next, -1, sizeof(Tr[rt].next));
            Tr[rt].v = 1;
        }
        ++i;
    }
    Tr[rt].v = v;
}

int query(char *s) {
    int i = 0;
    int rt = 0;
    while(s[i]) {
        int id = s[i] - 'a';
        rt = Tr[rt].next[id];
        ++i;
    }
    return Tr[rt].v;
}

map<string, int> on;


int v[N];
int n;
LL W, H, p, nW, nH;
LL fac;
void gao() {

    for(int i=0;i<n&&)

    if(p >= 60LL * fac * H * W) {
        puts("Perfect");
    }
    else if(p < 10LL * fac * H * W) {
        puts("Slideshow");
    }
    else  {
        puts("So-so");
    }
}
int main() {

    scanf("%d", &n);
    {
        mp.clear();
        string str;
        //init();
        LL fac = 1;
        for(int i = 0; i < n; ++i) {
            scanf("%s %d", s, v + i);

            str = s;
            mp[str] = i;
            on[str] = 1;
        }

        scanf("%I64d %I64d %I64d",&H,&W,&p);
        int m;
        //printf("p = %lld nd = %lld\n",p,60LL*fac * H * W);
        scanf("%d", &m);

        while(m--) {
            scanf("%s", s);
            if(s[0] == 'O') {
                scanf("%s", t);
                str = t;
                int id = mp[str];
                //v = query(t);
                if(s[1] == 'n') {
                    if(on[str] == 1)while(1);
                    fac *= v;
                    on[str] = 1;
                }
                else {
                    if(on[str] == 0)while(1);
                    if(fac % v != 0)while(1);
                    fac /= v;
                    on[str] = 0;
                }
            }
            else {
                scanf("%I64d %I64d", &nW, &nH);
                W = nW;
                H = nH;
            }
            if(60.0 * fac * H * W > 1e18) {
                while(1);
                puts("Perfect");
            }
            else if(p >= 60LL * fac * H * W) {
                puts("Perfect");
            }
            else if(p < 10LL * fac * H * W) {
                puts("Slideshow");
            }
            else  {
                puts("So-so");
            }
        }
    }
    return 0;
}
