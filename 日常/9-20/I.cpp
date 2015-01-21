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


vector<int> pos[4];

int p[5000];
int KMP(char *a, int n, char *b, int m, int k) {
    p[0] = -1;
    int i, j = -1;
    for(i = 1; i <= m; i++) {
        while((j > -1) && (b[j+1] != b[i]))
            j = p[j];
        if(b[j+1] == b[i]) j++;
        p[i] = j;
    }
    //for(i=0;i<m;i++) printf("%d   ",p[i]); printf("\n");
    j = -1;
    for(i = 0; i < n; i++) {
        while((j > -1) && (b[j+1] != a[i])) j = p[j];
        if(b[j+1] == a[i]) {
            j++;
        }
        if(j == m - 1) {
            //printf("i=%d\n",i);
            //return i-m+1;
            pos[k].push_back(i - m + 1);
            j = p[j];
        }
    }
    return -1;
}
char S[5000], s[4][66];
int dp_max[5000], dp_min[5000], len[4];
int main() {
    while(~scanf("%s", S)) {
        for(int i = 0; i < 4; ++i) {
            scanf("%s", s[i]);
        }
        int n =  strlen(S);
        for(int k = 0; k < 4; ++k) {
            int m = strlen(s[k]);
            len[k] = m;
            pos[k].clear();
            KMP(S, n, s[k], m, k);
        }
        for(int i = 0; i < 4; ++i) {
            for(int j = 0; j < pos[i].size(); ++j) {
                printf("%d ", pos[i][j]);
            } puts("");
        }
    }
    return 0;
}
