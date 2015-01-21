#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL ;

const int N = 3200000;
const int K = 26;

struct Tree {
    int next[K], cnt,  visit, mark;
    void init() {
        memset(next, -1, sizeof(next));
        cnt = visit = mark = 0;
    }
} Tr[N];

int tot;

void init() {
    tot = 0;
    Tr[0].init();
}

void insert(char *s) {
    int rt = 0;
    while(*s) {
        int id = *s - 'a';
        if(Tr[rt].next[id] == -1) {
            Tr[rt].next[id] = ++tot;
            Tr[tot].init();
        }
        rt = Tr[rt].next[id];
        ++Tr[rt].cnt;
        ++s;
    }
}

void Solve(int rt, char *s, int d, int mark) {
    if(d < 0)return ;
    if(*s == '\0')Tr[rt].mark = mark;
    Tr[rt].visit = mark;
    if(Tr[rt].mark == mark)return ;
    int id = *s - 'a';
    if(~Tr[rt].next[id])Solve(Tr[rt].next[id], s + 1, d, mark);
    if(d) {
        for(int i = 0; i < K; ++i) {
            if(~Tr[rt].next[i]) {
                Solve(Tr[rt].next[i], s, d - 1, mark);
            }
        }
        Solve(rt, s + 1, d - 1, mark);
        for(int i = 0; i < K; ++i) {
            if(~Tr[rt].next[i]) {
                Solve(Tr[rt].next[i], s + 1, d - 1, mark);
            }
        }
    }
}

int res;
void Calc(int rt, int mark) {
    if(Tr[rt].visit != mark)return ;
    if(Tr[rt].mark == mark)res += Tr[rt].cnt;
    else {
        for(int i = 0; i < K; ++i) {
            if(~Tr[rt].next[i]) {
                Calc(Tr[rt].next[i], mark);
            }
        }
    }
}


char s[11];
int main() {
    int n, m, d;
    while(~scanf("%d", &n)) {
        init();
        for(int i = 0; i < n; ++i) {
            scanf("%s", s);
            insert(s);
        }
        scanf("%d", &m);
        for(int i = 1; i <= m; ++i) {
            scanf("%s%d", s, &d);
            Solve(0, s, d, i);
            res = 0;
            Calc(0, i);
            printf("%d\n", res);
        }
    }
    return 0;
}
