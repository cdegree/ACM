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
char ch1[N], ch2[N];
string s1, s2;
LL cnt[N][26], sum[N];
int main() {
    LL n, m;
    while(~scanf("%I64d%I64d", &n, &m)) {
        scanf("%s%s", ch1, ch2);
        s1 = ch1;
        s2 = ch2;
        if(n < m) {
            swap(n, m);
            swap(s1, s2);
        }
        //printf("n = %I64d m = %I64d\n",n,m);
        //printf("%s\n%s\n",s1.c_str(),s2.c_str());
        LL g = __gcd(n, m);
        n /= g;
        m /= g;
        LL l1 = s1.size();
        LL l2 = s2.size();
        LL m2 = __gcd(l1,l2);
        LL res = 0;
        if(n == m) {
            LL cnt = 0;
            for(int i = 0; i < l1; ++i) {
                cnt += s1[i] != s2[i];
            }
            res = cnt;
        }
        else {
            memset(cnt, 0, sizeof(cnt));
            for(int i = 0; i < l2; ++i) {
                ++cnt[i%m2][ s2[i] - 'a' ];
            }
            for(int i = 0; i < m2; ++i) {
                sum[i%m2] = 0;
                for(int j = 0; j < 26; ++j) {
                    sum[i%m2] += cnt[i%m2][j];
                }
                //printf("=%I64d\n",sum[i%m2]);
            }

            res = 0;
            for(int i = 0; i < l1; ++i) {
                res += sum[i%m2] - cnt[i%m2][ s1[i] - 'a' ];
            }
            //printf("res= %I64d\n",res);
        }
        res *= g;
        printf("%I64d\n", res);
    }
    return 0;
}
