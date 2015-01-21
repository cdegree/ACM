/********************

LightOJ 1060

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



vector< pair<char, int> > vp;

LL f[22];

void init() {
    f[0] = f[1] = 1;
    for(LL i = 2; i < 22; ++i) {
        f[i] = f[i-1] * i;
    }
}


LL get_fac(vector< pair<char, int> > vp) {
    LL ni = 1;
    LL sum = 0 ;
    for(int i = 0; i < vp.size(); ++i) {
        ni *= f[ vp[i].Y ];
        sum += vp[i].Y;
    }
    return f[sum] / ni;
}



void gao(char *s, LL n) {
    int m = strlen(s);
    sort(s, s + m);
    vp.clear();
    vp.push_back(make_pair(s[0], 1));
    for(int i = 1; i < m; ++i) {
        if(s[i] == s[i-1]) {
            ++vp.back().Y;
        }
        else {
            vp.push_back(make_pair(s[i], 1));
        }
    }
    LL ap = get_fac(vp);
    //printf("ap = %lld\n", ap);
    if(n > ap) {
        puts("Impossible");
        return ;
    }
    for(int i = 0; i < m; ++i) {
        LL cut = 0;
        int j;
        for(j = 0; j < vp.size(); ++j) {
            --vp[j].Y;
            LL tr = get_fac(vp);
            //printf("tr = %lld\n",tr);
            cut += tr;
            if(cut >= n) {
                cut -= tr;
                n -= cut;
                break;
            }
            ++vp[j].Y;
        }
        //printf("cut = %lld n = %lld ch = %c\n",cut,n,vp[j].X);
        printf("%c", vp[j].X);
        if(vp[j].Y == 0) {
            vp.erase(vp.begin() + j);
        }
    }
    puts("");
}


LL n;
char s[22];
int main() {
    int T;
    init();
    scanf("%d", &T);
    for(int t = 1; t <= T; ++t) {
        scanf("%s %lld", s, &n);
        printf("Case %d: ",t);
        gao(s, n);
    }
    return 0;
}
