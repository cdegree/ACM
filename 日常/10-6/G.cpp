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

const int MAXK = 4;  //自动机里字符集的大小
const int MAXN = 20000 + 10;
struct  TrieNode {
    int fail;
    int next[MAXK];
    int danger;   //该节点是否为某模式串的终结点
    int idx;
    int len;
    int val;

} NODE[MAXN];

int leng;
//文本字符串

int back[MAXN];

int get_th(char ch) {
    switch(ch) {
        case'A':return 0;
        case'G':return 1;
        case'T':return 2;
        case'C':return 3;
    }
}

void  TrieInsert(char *s, int k) {
    int  i = 0;
    int len = 0;
    int p = 0;
    while(s[i]) {
        len++;
        int  idx = get_th(s[i]);
        if(NODE[p].next[idx] == -1) {
            NODE[p].next[idx] = ++leng;
        }
        p = NODE[p].next[idx];
        i++;
    }
    NODE[p].val = k;
    NODE[p].idx = k;
    NODE[p].danger = 1;
    NODE[p].len = len;
}


void  Build_AC_Automation() {
    int i, pnidx, cnidx;
    queue<int> Q;
    while(!Q.empty())Q.pop();
    int pidx, cidx;
    NODE[0].fail = -1;

    Q.push(0);

    while(!Q.empty()) {
        cidx = Q.front();
        Q.pop();
        //printf("%d\n",cidx);
        for(i = 0; i < MAXK; i++)
            if(NODE[cidx].next[i] != -1) {
                cnidx = NODE[cidx].next[i];
                if(cidx == 0) {
                    NODE[cnidx].fail = 0;
                }
                else {
                    pidx = NODE[cidx].fail;
                    while(pidx != -1) {
                        pnidx = NODE[pidx].next[i];
                        if(pnidx != -1) {
                            NODE[cnidx].fail = pnidx;
                            if(NODE[pnidx].danger == 1 && NODE[cnidx].danger == -1) {
                                NODE[cnidx].danger = 1;
                                NODE[cnidx].idx = NODE[pnidx].idx;
                                NODE[cnidx].len = NODE[pnidx].len;
                            }
                            break;
                        }
                        pidx = NODE[pidx].fail;
                    }
                    if(pidx == -1) NODE[cnidx].fail = 0;
                }
                Q.push(cnidx);
            }
    }
}
int n, l;
char s[105];

LL dp[10005][105];

set<string> ss;
string str;
string pat[22] = { "A", "G", "T", "C", "AA", "AG", "AT", "AC", "GA", "GG", "GT", "GC", "TA", "TG", "TT", "TC", "CA", "CG", "CT", "CC" };
int main() {
    while(~scanf("%d%d", &n, &l)) {
        leng = 0;
        ss.clear();
        memset(NODE, -1, sizeof(NODE));
        int val;
        for(int i = 0; i < n; ++i) {
            scanf("%s%d", s, &val);
            str = s;
            ss.insert(str);
            TrieInsert(s, val);
        }
        for(int i = 0; i < 20; ++i) {
            if(ss.find(pat[i]) == ss.end()) {
                char sp[4];
                for(int j = 0; j < pat[i].size(); ++j) {
                    sp[j] = pat[i][j];
                }
                sp[ pat[i].size()] = '\0';
                TrieInsert(sp, 0);
            }
        }
        Build_AC_Automation();
        for(int i = 0; i <= leng; ++i) {
            for(int j = 0; j <= l; ++j) {
                dp[i][j] = -1e9;
            }
        }
        dp[0][0] = 0;
        for(int i = 0; i < l; ++i) {
            for(int j = 0; j <= leng; ++j) {
                if(dp[j][i] != -1e9) {
                    for(int k = 0; k < 4; ++k) {
                        int v = NODE[j].next[k];
                        int val = NODE[v].val;
                        if(~v) {
                            dp[v][i+1] = max(dp[v][i+1], dp[j][i] + val);
                            int vv = NODE[j].fail;
                            while(vv != -1) {
                                dp[vv][i+1] = max(dp[vv][i+1], dp[j][i] + val);
                                vv = NODE[vv].fail;
                            }
                        }
                    }
                }
            }
        }
        LL res = 0;
        for(int j = 0; j <= leng; ++j) {
            checkmax(res, dp[j][l]);
        }
        printf("%d\n", res);
    }
    return 0;
}
