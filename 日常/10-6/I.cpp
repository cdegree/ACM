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

const int N = 100005;
LL prime[N];
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
const LL mod = 1000000007LL;

LL Pow(LL x, LL n) {
    if(n == 0)return 1;
    else {
        LL ret = 0;
        if(n & 1) {
            ret = x * Pow(x, n - 1) % mod;
        }
        else {
            ret = Pow(x, n / 2);
            ret = ret * ret % mod;
        }
        return ret;
    }
}

LL get_k4(LL n) {
    LL b = 30;
    LL bp2 = Pow(b, mod - 2);
    LL a = n * (n + 1) % mod * (2 * n + 1) % mod * ((3 * n * n % mod + 3 * n - 1) % mod) % mod;
    LL ret = a * bp2 % mod;
    return ret;
}
vector<LL> fac;
LL res;
LL m;
void dfs(int cur, LL now, int cnt) {
    if(cur == fac.size()) {
        if(cnt & 1) {
            res = (res - now * now % mod * now % mod * now % mod * get_k4(m / now) % mod + mod) % mod;
        }
        else {
            res = (res + now * now % mod * now % mod * now % mod * get_k4(m / now) % mod) % mod;
        }
    }
    else {
        dfs(cur + 1, now * fac[cur], cnt + 1);
        dfs(cur + 1, now, cnt);
    }

}

int main() {
    LL n;
    int T;
    scanf("%d", &T);
    init();
    while(T--) {
        scanf("%lld", &n);
        fac.clear();
        m = n;
        for(int i = 0; i < len; ++i) {
            if(n % prime[i] == 0) {
                n /= prime[i];
                fac.push_back(prime[i]);
                while(n % prime[i] == 0) {
                    n /= prime[i];
                }
            }
        }
        if(n > 1) {
            fac.push_back(n);
        }
        //printf("fac = %lld\n",fac[0]);
        res = 0;
        dfs(0, 1, 0);
        printf("%lld\n", res);
    }
    return 0;
}
