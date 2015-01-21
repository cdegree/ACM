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

LL n, m;
const int N = 100005;
struct enemy {
    LL A, B;
} E[N];

bool cmp(enemy a, enemy b) {
    if(a.B != b.B)return a.B < b.B;

    return a.A < b.A;
}

void CheckRes(LL &res1, LL &res2, LL t1, LL t2) {
    if(t1 > res1 || (t1 == res1 && t2 < res2)) {
        res1 = t1, res2 = t2;
    }
}

int main() {
    int T;
    scanf("%d", &T);

    for(int t = 1; t <= T; ++t) {
        scanf("%I64d %I64d", &n, &m);
        LL mn = 2e9;
        LL reskill = 0, resdur = 0;
        LL cnt = 0;
        LL cntB = 0;
        LL cankill = 0;

        for(int i = 0; i < n; ++i) {
            scanf("%lld %lld", &E[i].A, &E[i].B);

            if(E[i].B) {
                ++cntB;
                cankill += E[i].B;
                checkmin(mn, E[i].A);
            }
        }

        sort(E, E + n, cmp);

        for(int i=0;i<n;++i)
        {
            printf("[%d]. %I64d %I64d\n",i,E[i].A,E[i].B);
        }
        int pos = 0;

        while(E[pos].B == 0)++pos;

        LL t1 = 0, t2 = 0;
        LL p = m;

        printf("pos = %d\n",pos);
        for(int i = 0; i < pos; ++i) {
            if(p >= E[i].A) {
                t2 += E[i].A;
                p -= E[i].A;
                ++t1;
                puts("zai dou wo?");
            }
        }

        CheckRes(reskill, resdur, t1, t2);
        p = m;
        printf("res = %I64d  %I64d\n",mn);
        if(p >= mn) {
            //puts("ff");
            p -= mn;
            t1 = t2 = 0;
            t2 += mn;

            t1 += cntB;
            cankill -= (cntB - 1);
            t1 += min((LL)pos, cankill);
            pos -= cankill;

            for(int i = 0; i < pos; ++i) {
                if(p >= E[i].A) {
                    t2 += E[i].A;
                    p -= E[i].A;
                    ++t1;
                }
            }

            CheckRes(reskill, resdur, t1, t2);
        }

        printf("Case %d: ", t);
        printf("%I64d %I64d\n", reskill, resdur);
    }

    return 0;
}
