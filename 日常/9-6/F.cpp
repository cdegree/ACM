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

int n, m;
const int N = 100005;
struct enemy {
    LL A, B;
} E[N];


bool cmp(enemy a, enemy b) {
    if(a.B != b.B)return a.B < b.B;

    return a.A < b.A;
}

bool cmp2(enemy a, enemy b) {
    if(a.A != b.A)
        return a.A < b.A;

    return a.B > b.B;
}

void CheckRes(LL &res1, LL &res2, LL t1, LL t2) {
    if(t1 > res1 || (t1 == res1 && t2 < res2)) {
        res1 = t1, res2 = t2;
    }
}
vector<int> vi;
int main() {
    int T;
    scanf("%d", &T);

    for(int t = 1; t <= T; ++t) {
        scanf("%d %d", &n, &m);
        LL mn = 2e9;
        LL reskill = 0, resdur = 0;
        LL cnt = 0;
        LL cntB = 0;
        LL cankill = 0;
        vi.clear();

        for(int i = 0; i < n; ++i) {
            scanf("%I64d %I64d", &E[i].A, &E[i].B);

            if(E[i].B > 0) {
                ++cntB;
                vi.push_back(E[i].A);
                cankill += E[i].B;
                checkmin(mn, E[i].A);
            }
        }

        sort(vi.begin(), vi.end());
        vi.erase(vi.begin());
        sort(E, E + n, cmp);

        int pos = 0;

        while(E[pos].B == 0)++pos;

        LL t1 = 0, t2 = 0;
        LL p = m;

        //printf("pos = %d\n", pos);

        for(int i = 0; i < pos; ++i) {
            if(p >= E[i].A) {
                t2 += E[i].A;
                p -= E[i].A;
                ++t1;
                //puts("zai dou wo?");
            }
        }

        if(p >= mn && pos < n) {
            t2 += mn;
            t1 += cntB;
        }

        CheckRes(reskill, resdur, t1, t2);
        p = m;
        //printf("res = %I64d  %I64d\n", mn);

        if(p >= mn) {
            //puts("ff");
            p -= mn;
            t1 = t2 = 0;
            t2 += mn;

            t1 += cntB;
            cankill -= (cntB - 1);
            t1 += min((LL)pos, cankill);
            pos -= cankill;
            int q = 0;
            int len = vi.size();
            //printf("len = %d %d\n", len , t1);

            for(int i = 0; i < pos; ++i) {
                if(p >= E[i].A || (q < len && p >= vi[q])) {
                    if(q >= len || vi[q] >= E[i].A) {
                        t2 += E[i].A;
                        p -= E[i].A;
                        ++t1;
                        //puts("1");
                    }
                    else {
                        t2 += vi[q];
                        p -= vi[q++];
                        ++t1;
                        --i;
                        --pos;
                        //puts("2");
                    }
                }
            }

            CheckRes(reskill, resdur, t1, t2);
        }

        printf("Case %d: ", t);
        printf("%I64d %I64d\n", reskill, resdur);
    }

    return 0;
}
