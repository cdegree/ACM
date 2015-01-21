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

#define N 2005 // 总的点的个数
#define M 2000005// 边的个数

int v[N], cnt, v2[N], cnt2;
struct edge {
    int from, to, next;
} e[M], e2[M];
void insert(int from, int to) {
    e[cnt].from = from, e[cnt].to = to;
    e[cnt].next = v[from];
    v[from] = cnt++;
}
void insert2(int from, int to) {
    e2[cnt2].from = from, e2[cnt2].to = to;
    e2[cnt2].next = v2[from];
    v2[from] = cnt2++;
}
int index, dfn[N], low[N], instack[N], sta[N], top;
int belong[N], cntnum, num[N];
int cf[N], rd[N], que[N], col[N];
bool ans[N];//1表示选择
void tarjan(int id) {
    dfn[id] = low[id] = ++index;
    instack[id] = 1;
    sta[top++] = id;
    int tmp = v[id];
    while(tmp != -1) {
        if(!dfn[e[tmp].to]) {
            tarjan(e[tmp].to);
            if(low[e[tmp].to] < low[id]) low[id] = low[e[tmp].to];
        }
        else if(instack[e[tmp].to] && dfn[e[tmp].to] < low[id])
            low[id] = dfn[e[tmp].to];
        tmp = e[tmp].next;
    }
    if(dfn[id] == low[id]) {
        do {
            tmp = sta[--top];
            instack[tmp] = 0;
            belong[tmp] = cntnum;
            num[cntnum]++;
        }
        while(tmp != id);
        cntnum++;
    }
}
bool solve(int n) {
    index = cntnum = top = 0;
    memset(dfn, 0, sizeof(dfn));
    memset(num, 0, sizeof(num));
    for(int i = 0; i < 2 * n; i++)
        if(!dfn[i]) tarjan(i);
    for(int i = 0; i < n; i++) {
        if(belong[i] == belong[i + n]) {
            return false;
        }
        cf[belong[i]] = belong[i + n];
        cf[belong[i + n]] = belong[i];
    }
    memset(rd, 0, sizeof(rd));
    memset(v2, -1, sizeof(v2));
    memset(col, 0, sizeof(col));
    cnt2 = 0;
    for(int i = 0; i < cnt; i++)
        if(belong[e[i].from] != belong[e[i].to]) {
            insert2(belong[e[i].to], belong[e[i].from]);
            rd[belong[e[i].from]]++;
        }
    int head = 0, tail = 0;
    for(int i = 0; i < cntnum; i++)
        if(rd[i] == 0) que[tail++] = i;
    while(head < tail) {
        int tmp = que[head++];
        if(col[tmp] == 0) {
            col[tmp] = 1;
            col[cf[tmp]] = -1;
        }
        int id = v2[tmp];
        while(id != -1) {
            if(--rd[e2[id].to] == 0)
                que[tail++] = e2[id].to;
            id = e2[id].next;
        }
    }
    memset(ans, 0, sizeof(ans));
    for(int i = 0; i < n; i++)
        if(col[belong[i]] == 1) ans[i] = 1;
    return true;
}
void init() {
    cnt = 0;
    memset(v, -1, sizeof(v));
}

int mp[105][105];

int main() {
    int n;
    while(~scanf("%d", &n)) {
        memset(mp, 0, sizeof(mp));
        for(int i = 0; i < n; ++i) {
            mp[i][i] = 1;
            int v;
            while(1) {
                scanf("%d", &v);
                if(v == 0)break;
                --v;
                mp[i][v] = 1;
            }
        }
        init();
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                if(!mp[j][i] || !mp[i][j]) {
                    insert(i, j + n);
                    insert(j, i + n);
                    insert(j + n, i);
                    insert(i + n, j);
                }
            }
        }
        if(!solve(n)) {
            puts("NO");
        }
        else {
            vector<int> ca, cb;
            for(int i = 0; i < n; ++i) {
                if(ans[i])ca.push_back(i);
                else cb.push_back(i);
                //printf("%d ", ans[i]);
            }
            bool OK = 1;
            for(int i = 0; i < ca.size(); ++i) {
                for(int j = i + 1; j < ca.size(); ++j) {
                    if(!mp[ ca[i] ][ ca[j] ] || !mp[ ca[j] ][ ca[i] ]) {
                        OK = 0;
                    }
                }
            }
            for(int i = 0; i < cb.size(); ++i) {
                for(int j = i + 1; j < cb.size(); ++j) {
                    if(!mp[ cb[i] ][ cb[j] ] || !mp[ cb[j] ][ cb[i] ]) {
                        OK = 0;
                    }
                }
            }
            printf("%s\n",OK?"YES":"NO");
            //puts("");
        }
    }
    return 0;
}
