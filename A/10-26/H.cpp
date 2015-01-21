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

const int N = 505;
int uN, vN; //u,v��Ŀ
int link[N];
bool used[N];
int g[N][N];
bool dfs(int u) { //����߿�ʼ������·��
    int v;
    for(v = 0; v < vN; v++) { //��������Ŵ�0��ʼ����Ҫ��1��ʼ��Ҫ�޸�
        if(g[u][v] && !used[v]) {
            used[v] = true;
            if(link[v] == -1 || dfs(link[v])) {
                //������·������
                link[v] = u;
                return true;
            }
        }
    }
    return false;//�����Ҫ���ˣ������������
}
int bimatch(int n) {
    uN = vN = n;
    int res = 0;
    int u;
    memset(link, -1, sizeof(link));
    for(u = 0; u < uN; u++) {
        memset(used, 0, sizeof(used));
        if(dfs(u)) res++;
    }
    return res;
}
struct person {
    int t;
} P1[N], P2[N];
int main() {
    int a, b;
    while(~scanf("%d %d", &a, &b)) {
        int n;
        scanf("%d", &n);
        int n1 = 0, n2 = 0;
        for(int i = 0; i < n; ++i) {
            int t, tp;
            scanf("%d %d", &t, &tp);
            if(tp == 0) {
                P1[n1++].t = t;
            }
            else {
                P2[n2++].t = t;
            }
        }
        memset(g, 0, sizeof(g));
        for(int i = 0; i < n1; ++i) {
            for(int j = 0; j < n2; ++j) {
                if(P1[i].t < P2[j].t && ((P2[j].t - P1[i].t) >= a || (P2[j].t - P1[i].t) <= b)) {
                    g[i][j] = 1;
                }
            }
        }
        int res = bimatch(n1);
        if(res == n1) {
            puts("No reason");
            for(int i = 0; i < n1; ++i) {
                printf("%d %d\n",  P1[link[ i ]].t,P2[i].t);
            }
        }
        else {
            puts("Liar");
        }
    }
    return 0;
}
