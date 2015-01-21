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

const int maxn = 50005;

#define lson L , mid , rt << 1
#define rson mid + 1 , R , rt << 1 | 1
#define lc rt<<1
#define rc rt<<1|1

char s[maxn];



struct Segment_Tree {
    int left, right;
    int cnt, comb;
    int len;
    char lefts[3], rights[3];
} Seg[maxn*4];

void Push_Up(Segment_Tree& Rt, Segment_Tree Lc, Segment_Tree Rc) {
    Rt.cnt = Lc.cnt + Rc.cnt + Lc.comb + Rc.comb;

    if(Lc.len == 1 && Rc.len == 1) {
        Rt.comb = 0;
        Rt.lefts[0] = Lc.lefts[0];
        Rt.lefts[1] = Rc.lefts[0];
        Rt.lefts[2] = '\0';
        Rt.rights[0] = Lc.rights[0];
        Rt.rights[1] = Rc.rights[0];
        Rt.rights[2] = '\0';
    }
    else if(Lc.len >= 2 && Rc.len == 1) {
        Rt.rights[0] = Lc.rights[1];
        Rt.rights[1] = Rc.rights[0];
        Rt.rights[2] = '\0';
        strcpy(Rt.lefts, Lc.lefts);
        if(Lc.rights[0] == 'w' && Lc.rights[1] == 'b' && Rc.lefts[0] == 'w') {
            Rt.comb = 1;
        }
        else {
            Rt.comb = 0;
        }
    }
    else if(Lc.len == 1 && Rc.len >= 2) {
        Rt.lefts[0] = Lc.lefts[0];
        Rt.lefts[1] = Rc.lefts[0];
        Rt.lefts[2] = '\0';
        strcpy(Rt.rights, Rc.rights);
        if(Lc.lefts[0] == 'w' && Rc.lefts[0] == 'b' && Rc.lefts[1] == 'w') {
            Rt.comb = 1;
        }
        else {
            Rt.comb = 0;
        }
    }
    else {
        strcpy(Rt.lefts, Lc.lefts);
        strcpy(Rt.rights, Rc.rights);
        if(Lc.rights[0] == 'w' && Lc.rights[1] == 'b' && Rc.lefts[0] == 'w') {
            Rt.comb = 1;
        }
        else if(Lc.rights[1] == 'w' && Rc.lefts[0] == 'b' && Rc.lefts[1] == 'w') {
            Rt.comb = 1;
        }
        else {
            Rt.comb = 0;
        }
    }
    //printf("%d -> %d %s -> %s  %d %d\n", Rt.left, Rt.right, Rt.lefts, Rt.rights, Rt.cnt, Rt.comb);
}


void Build(int L, int R, int rt) {
    Seg[rt].left = L, Seg[rt].right = R;
    Seg[rt].len = R - L + 1;
    Seg[rt].lefts[0] = '\0';
    Seg[rt].rights[0] = '\0';
    Seg[rt].cnt = Seg[rt].comb = 0;
    if(L == R) {
        Seg[rt].lefts[0] = Seg[rt].rights[0] = s[L];
        Seg[rt].rights[1] = Seg[rt].lefts[1] = '\0';
    }
    else {
        int mid = (L + R) >> 1;
        Build(lson);
        Build(rson);
        Push_Up(Seg[rt], Seg[lc], Seg[rc]);
    }
}

void Update(int L, int R, int rt, int pos, char ch) {
    if(pos <= L && R <= pos) {
        Seg[rt].rights[0] = Seg[rt].lefts[0] = ch;
        Seg[rt].rights[1] = Seg[rt].lefts[1] = '\0';
    }
    else {
        int mid = (L + R) >> 1;
        if(pos <= mid) {
            Update(lson, pos, ch);
        }
        if(pos > mid) {
            Update(rson, pos, ch);
        }
        Push_Up(Seg[rt], Seg[lc], Seg[rc]);
    }
}
Segment_Tree Query(int L, int R, int rt, int from, int to) {
    if(from <= L && R <= to) {
        return Seg[rt];
    }
    else {
        int mid = (L + R) >> 1;
        int ret = 0;
        if(to <= mid) {
            return Query(lson, from, to);
        }
        else if(from > mid) {
            return Query(rson, from, to);
        }
        else {
            Segment_Tree ret, Lc, Rc;
            ret.cnt = ret.comb = 0;
            ret.lefts[0] = ret.rights[0] = '\0';
            ret.len = to - from + 1;
            Lc = Query(lson, from, to);
            Rc = Query(rson, from, to);
            Push_Up(ret, Lc, Rc);
            return ret;
        }
    }
}





int main() {
    int T, v, p;
    int n, m, a, b;
    char ch[3];
    //freopen("Gin.txt","r",stdin);
    scanf("%d", &T);
    for(int t = 1; t <= T; ++t) {
        scanf("%d%d", &n, &m);
        scanf("%s", s + 1);
        Build(1, n, 1);
        printf("Case %d:\n", t);
        for(int i = 0; i < m; ++i) {
            scanf("%d", &v);
            if(v == 1) {
                scanf("%d%s", &p, ch);
                Update(1, n, 1, p + 1, ch[0]);
            }
            else {
                scanf("%d%d", &a, &b);
                Segment_Tree res = Query(1, n, 1, a + 1, b + 1);

                printf("%d\n", res.cnt + res.comb);
            }
        }
    }
    return 0;
}
