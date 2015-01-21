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
typedef long long LL ;
template<typename T> void checkmin(T &x, T y) {x = min(x, y);}
template<typename T> void checkmax(T &x, T y) {x = max(x, y);}
void FILE_INPUT() { freopen("Jin.txt", "r", stdin);   }
void FILE_OUTPUT() { freopen("out.txt", "w", stdout);   }

char s1[15], s2[15];

const int N = 250002 * 10;
const int CHILD_NUM = 26;
struct Tree {
    int chd[N][CHILD_NUM];
    int val[N];
    int ID[256];
    int sz;
    int cnt;
    void Init() {
        for(int i = 0; i < 26; ++i) {
            ID[i+'a'] = i;
        }
    }
    void Reset() {
        sz = 1;
        cnt = 1;
        memset(chd[0], 0, sizeof(chd[0]));
        val[0] = 0;
    }
    int Insert(char *s) {
        int q = 0;
        for(; *s; ++s) {
            int c = ID[*s];
            if(!chd[q][c]) {
                memset(chd[sz], 0, sizeof(chd[sz]));
                val[sz] = 0;
                chd[q][c] = sz++;
            }
            q = chd[q][c];
        }
        if(val[q])return val[q];
        return val[q] = cnt++;
    }
} Tr;




int deg[N];
int Set[N];
int Find_Set(int x) {
    if(x == Set[x])return x;
    return Set[x] = Find_Set(Set[x]);
}
int main() {
    //FILE_INPUT();
    for(int i = 1; i < N; ++i) {
        Set[i] = i;
    }
    Tr.Init();
    Tr.Reset();
    memset(deg, 0, sizeof(deg));
    while(~scanf("%s %s", s1, s2)) {
        int h1 = Tr.Insert(s1);
        int h2 = Tr.Insert(s2);
        ++deg[h1];
        ++deg[h2];
        Set[Find_Set(h1)] = Find_Set(h2);
    }
    bool ok = 1;
    for(int i = 2; i < Tr.cnt; ++i) {
        if(Find_Set(i) != Find_Set(i - 1)) {ok = 0; break;}
    }
    int cnt1 = 0;
    for(int i = 1; i < Tr.cnt; ++i) {
        if(deg[i] & 1)++cnt1;
    }
    if((cnt1 == 0 || cnt1 == 2) && ok) {
        puts("Possible");
    }
    else {
        puts("Impossible");
    }
    return 0;
}
