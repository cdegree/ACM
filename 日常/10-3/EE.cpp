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

vector<LL> fac;

LL gcd(LL n, LL m) {
    return m == 0 ? n : gcd(m, n % m);
}

const int N = 10000005;
int prime[N];
bool isprime[N];
int len;
void init() {
    len = 0;
    memset(isprime, 1, sizeof(isprime));
    isprime[1] = 0;
    for(int i = 2; i < N; ++i) {
        if(isprime[i]) {
            for(int j = i + i; j < N; j += i) {
                isprime[j] = 0;
            }
            prime[len++] = i;
        }
    }
}

int main() {
    int T;
    int n;
    LL L;
    init();
    //freopen("Ein.txt", "r", stdin);
    scanf("%d", &T);
    while(T--) {
        fac.clear();
        LL G, L;
        scanf("%I64d%I64d", &G, &L);
        if(L % G == 0) {
            L = L / G;
            LL res = 1;
            int ccnt = 0;
            for(int i = 0; prime[i]<= L&&i<len ; ++i) {
                int cnt = 0;
                while(L % prime[i] == 0) {
                    ++cnt;
                    L /= prime[i];
                }
                if(cnt) {
                    res *= cnt;
                    if(ccnt)res *= 6;
                    ++ccnt;
                }
            }
            if(L > 1) {
                if(ccnt)res *= 6;
            }
            //printf("ccnt = %d\n",ccnt);
            printf("%I64d\n", res *6);
        }
        else {
            puts("0");
        }
    }
    return 0;
}
