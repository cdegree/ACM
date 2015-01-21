/********************

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

int n, m, k;
const int N = 303;
int con[N][N];
int a[N], mark[N];
int main() {
    while(cin >> n >> m >> k) {
        memset(mark, 0, sizeof(mark));
        vector<int> mk,P;
        for(int i = 0; i < k; ++i) {
            cin >> a[i];
            mark[a[i]] = 1;
            if(mk.size() < 2) {
                mk.push_back(a[i]);
            }
            else P.push_back(a[i]);
        }
        int q = -1;
        for(int i = 1; i <= n; ++i)if(!mark[i])q = i;
        memset(con, 0, sizeof(con));
        if(k < n && m >= 2 && m <= n*(n - 1) / 2-k+1) {
            int cnt = 0;
            con[ q ][mk[0]] = con[ mk[0] ][q] = 1;
            con[ q ][ mk[1] ] = con[ mk[1] ][q] = 1;
            con[ mk[0] ][ mk[1] ] = con[ mk[1] ][ mk[0] ] = -1;
            printf("%d %d\n", q , mk[0]);
            printf("%d %d\n", q , mk[1]);
            for(int i=0;i<P.size();++i)
            {
                con[ mk[0] ][ P[i] ] = con[ P[i] ][ mk[0] ]= -1;
            }


            cnt = 2;

            for(int i=1;i<=n;++i)
            {
                if(cnt==m)break;
                if(con[i][ q ]==0&&i!=q)
                {
                    con[i][q]=con[q][i]=-1;
                    printf("%d %d\n", i, q);
                    ++cnt;
                    if(cnt==m)break;
                }
            }

            for(int i = 1; i <= n; ++i) {
                if(cnt == m)break;
                for(int j = i + 1; j <= n; ++j) {
                    if(cnt == m)break;
                    if(con[i][j] == 0) {
                        printf("%d %d\n", i, j);
                        ++cnt;
                    }
                }
            }
        }
        else {
            puts("-1");
        }

    }
    return 0;
}
