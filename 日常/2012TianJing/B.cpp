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

const int N = 1000005;
int prime[N];
bool isprime[N];
int len;
void Init() {
    memset(isprime, true, sizeof(isprime));
    len = 0;
    for(int i = 2; i < N; ++i) {
        if(isprime[i]) {
            for(int j = i + i; j < N; ++j) {
                isprime[j] = false;
            }
            prime[len++] = i;
        }
    }
}
vector<int> get_fac(int n) {
    vector<int> ret;
    for(LL i = 1; i*i <= n; ++i) {
        if(n % i == 0) {
            ret.push_back(i);
            if(i*i != n) {
                ret.push_back(n / i);
            }
        }
    }
    return ret;
}


LL get_sqs(int a, int m) {
    LL sum = 0;
    while(a > 0) {
        int r = a % m;
        sum += r * r;
        a /= m;
    }
    return sum;
}
void pf(LL res, int m) {
    string ret = "";
    while(res > 0) {
        int r = res % m;
        if(r < 10) {
            ret += r + '0';
        }
        else {
            ret += r-10 + 'A';
        }
        res /= m;
    }
    reverse(ret.begin(),ret.end());
    printf("%s\n", ret.c_str());
}
int main() {
    int n, m;
    Init();
    while(~scanf("%d%d", &n, &m)) {
        vector<int> fac = get_fac(n);
        LL res =  0;
        for(int i = 0; i < fac.size(); ++i) {
            res += get_sqs(fac[i], m);
            //printf("res = %d fac = %d\n", res, fac[i]);
        }
        pf(res, m);
    }
    return 0;
}
