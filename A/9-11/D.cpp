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

struct Matrix {
    LL d[2][2];
    Matrix mul(Matrix a, LL mod) {
        Matrix ret;
        for(int i = 0; i < 2; ++i) {
            for(int j = 0; j < 2; ++j) {
                ret.d[i][j] = 0;
                for(int k = 0; k < 2; ++k) {
                    ret.d[i][j] += d[i][k] * a.d[k][j];
                    ret.d[i][j] %= mod;
                }
            }
        }
        return ret;
    }
};


Matrix P(Matrix x, LL n, LL mod) {
    if(n == 1)return x;
    if(n & 1) {
        Matrix ret = x.mul(P(x, n - 1, mod), mod);
        return ret;
    }
    else {
        Matrix ret = P(x, n / 2, mod);
        ret = ret.mul(ret, mod);
        return ret;
    }
}

LL Gao(LL n, LL mod) {
    if(n == 1)return 1;
    if(n == 0)return 0;
    Matrix x;
    x.d[0][0] = 3;
    x.d[0][1] = 1;
    x.d[1][0] = 1;
    x.d[1][1] = 0;
    x = P(x, n - 1, mod);
    LL ret = x.d[0][0];
    return ret;
}


int main() {
    LL n;
    //freopen("Dout.txt","w",stdout);
    //while(~scanf("%I64d", &n))
    //LL pre1=0,pre2=0;
    for(LL i = 0;i<10; ++i)
    {
        printf("%I64d  %I64d : %I64d\n",i, (LL)pow(3,i), Gao(i,1e9+7));
        //LL res ;
        //res = Gao(Gao(i, 222222224), 1e9 + 7);
        //res = Gao(Gao(Gao(n,183120LL),222222224LL),1000000007LL);
        //printf("%I64d\n",res);
        //if(pre2==0&&pre1==1&&res==10)
        //{ printf("%I64d = %I64d\n", i, res);}
        //pre2=pre1;
        //pre1=res;
    }
    return 0;
}
