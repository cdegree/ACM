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

typedef long long LL ;
template<typename T> void checkmin(T &x, T y) {x = min(x, y);}
template<typename T> void checkmax(T &x, T y) {x = max(x, y);}

const int N = 5000005;

int sg[N], prime[N];
bool isprime[N];
int len;
int dp[N];
void init() {
    memset(isprime, 1, sizeof(isprime));
    for(int i = 2; i < N; ++i) {
        if(isprime[i]) {
            for(int j = i + i; j < N; j += i) {
                isprime[j] = 0;
            }
            prime[len++] = i;
        }
    }
    memset(sg, -1, sizeof(sg));
    //memset(dp, -1, sizeof(dp));
}

int get_nsg(int n) {
    int &ret = sg[n];
    if(~ret)return ret;
    ret = 0;
    for(int i = 0; i < len; ++i) {
        while(n % prime[i] == 0) {
            ++ret;
            n /= prime[i];
        }
        if(isprime[n])break;
    }
    if(n > 1)++ret;
    return ret;
}

int get_sg(int n) {
    int &ret = dp[n];
    //printf("n = %d\n",n);
    if(~ret)return ret;
    if(n == 1)return ret = 0;
    else {
        if(isprime[n])return ret = 1;
        else {
            set<int> st;
            set<int>::iterator it;
            for(LL i = 1; i*i <= n; ++i) {
                if(n % i == 0) {
                    st.insert(get_sg(i));
                    if(n / i != n && n / i != i) {
                        st.insert(get_sg(n / i));
                    }
                }
                //puts("hh");
            }
            //puts("hh");
            int id = 0;
            it = st.begin();
            while(it != st.end() && *it == id) {
                ++it;
                ++id;
            }
            return ret = id;
        }
    }
}

int a[N];
int main() {
    init();
    int n;
    int T = 0;
    while(~scanf("%d", &n)) {
        int res = 0;
        for(int i = 0; i < n; ++i) {
            scanf("%d", a + i);
            res ^= get_nsg(a[i]);
        }
        printf("Test #%d: ", ++T);
        if(res > 0) {
            int id = -1;
            for(int i = 0; i < n; ++i) {
                int tmp = res ^ sg[a[i]];
                if(tmp < sg[a[i]]) {
                    id = i + 1;
                    break;
                }
            }
            printf("Alice %d\n",id);
        }
        else {
            puts("Bob");
        }
    }
    return 0;
}
