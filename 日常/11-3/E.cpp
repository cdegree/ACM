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


struct NODE {
    int lson, rson;
} nd[600000+2];

char mt[600002*2];
char s[600002];

set<int> st;
set<int>::iterator it, jt;
int dep[600002];
int rt;
void Insert(int val) {
    if(st.empty()) {
        rt = val;
        st.insert(val);
        nd[val].lson = nd[val].rson = -1;
        dep[val] = 1;
    }
    else {
        it = st.lower_bound(val);
        jt = it;
        if(jt == st.end()) {
            --it;
            if(val < *it)nd[*it].lson = val;
            else nd[*it].rson = val;
            nd[val].lson = nd[val].rson = -1;
            dep[val] = dep[*it] + 1;
        }
        else if(it == st.begin()) {
            if(val < *it)nd[*it].lson = val;
            else nd[*it].rson = val;
            nd[val].lson = nd[val].rson = -1;
            dep[val] = dep[*it] + 1;
        }
        else {
            --it;
            if(dep[*it] > dep[*jt]) {
                if(val < *it)nd[*it].lson = val;
                else nd[*it].rson = val;
                nd[val].lson = nd[val].rson = -1;
                dep[val] = dep[*it] + 1;
            }
            else {
                if(val < *jt)nd[*jt].lson = val;
                else nd[*jt].rson = val;
                nd[val].lson = nd[val].rson = -1;
                dep[val] = dep[*jt] + 1;
            }
        }
        st.insert(val);
    }
}
int len;
struct Snode {
    int u;
    char tp;
};
stack<Snode> S;
void dfs(int u) {
    //printf("u = %d\n",u);
    while(!S.empty())S.pop();
    Snode ab , now;
    ab.u = u;
    ab.tp = 0;
    S.push(ab);
    int cnt = 0;
    while(!S.empty()) {
        now = S.top();
        S.pop();
        int u = now.u;
        //printf("%d   %d\n", now.u, now.tp);
        //if(cnt++>10)break;
        if(now.tp == 0) {
            mt[len++] = (u & 1)+'0';
            if(~nd[u].lson) {
                ab.u = nd[u].lson;
                ab.tp = 0;
                now.tp = 1;
                S.push(now);
                S.push(ab);
            }
            else if(~nd[u].rson) {
                ab.u = nd[u].rson;
                ab.tp = 0;
                now.tp = 2;
                S.push(now);
                S.push(ab);
            }
            else {
                now.tp = 3;
                S.push(now);
            }
        }
        else if(now.tp == 1) {
            mt[len++] = (u & 1)+'0';
            if(~nd[u].rson) {
                ab.u = nd[u].rson;
                ab.tp = 0;
                now.tp = 2;
                S.push(now);
                S.push(ab);
            }
            else {
                now.tp = 3;
                S.push(now);
            }
        }
        else if(now.tp == 2) {
            mt[len++] = (u & 1)+'0';
            now.tp = 3;
            S.push(now);
        }
        else {
            //S.pop();
        }
    }
    /*
    mt[len++] = (u & 1) ;
    if(~nd[u].lson) {
        dfs(nd[u].lson);
        mt[len++] = (u & 1) ;
    }
    if(~nd[u].rson) {
        dfs(nd[u].rson);
        mt[len++] = (u & 1);
    }
    */
}
int p[7007];
int KMP(char *a, int n, char *b, int m) {
    p[0] = -1;
    int i, j = -1;
    for(i = 1; i <= m; ++i) {
        while((j > -1) && b[j+1] != b[i])j = p[j];
        if(b[j+1] == b[i])++j;
        p[i] = j;
    }
    j = -1;
    int ret = 0;
    for(i = 0; i < n; ++i) {
        while((j > -1) && (b[j+1] != a[i]))j = p[j];
        if(b[j+1] == a[i]) {
            ++j;
        }
        if(j == m - 1) {
            j = p[j];
            ++ret;
        }
    }
    return ret;
}

int main() {
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; ++t) {
        int n;
        st.clear();
        scanf("%d", &n);
        int a;
        for(int i = 0; i < n; ++i) {
            scanf("%d", &a);
            Insert(a);
        }
        scanf("%s", s);
        len = 0;
        dfs(rt);
        mt[len] = '\0';
        //printf("%s\n", mt);
        int q = strlen(s);
        int res = KMP(mt, len, s, q);
        printf("Case #%d: %d\n", t, res);
    }
    return 0;
}
