#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;
const int N = 55;
int u[N];
bool l[N];
int a[N][N], as[N];
long long gauss(int n, int m) {
    int i, j, k, r = 0;
    for(i = 0; i < m; i++)
        l[i] = 0;
    int var = 0;
    for(i = 0; i < m; i++) {
        for(j = r; j < n; j++)
            if(a[j][i]) {
                for(k = i; k <= m; k++)
                    swap(a[j][k], a[r][k]);
                break;
            }
        if(a[r][i] == 0)continue;
        for(j = 0; j < n; j++)
            if(j != r && a[j][i]) {
                for(k = i; k <= m; k++)
                    a[j][k] ^= a[r][k];
            }
        l[i] = 1; r++;
    }
    for(i = 0; i < m; i++) {
        if(l[i]) {
            for(j = 0; j < n; j++)
                if(a[j][i])
                    as[i] = a[j][m];
        }
    }
    //printf("r = %d n = %d m = %d", r, n, m);
    for(i = r; i < n; i++)if(a[i][m] != 0)return -1;
    return 1LL << (m - r);
}
const int bits = 52;
long long gao(vector<long long> c, long long L) {
    int n = c.size();
    int m = bits;
    memset(a, 0, sizeof(a));
    for(int i = 0; i < bits; ++i) {
        a[i][n] = (L >> i & 1);
        for(int j = 0; j < n; ++j) {
            if((c[j] >> i) & 1)a[i][j] = 1;
            else a[i][j] = 0;
        }
    }
    long long res = gauss(m, n);
    //printf("res = %lld\n", res);
    return res == -1 ? 0 : res;
}


class XorCards {
    public:
        long long numberOfWays(vector<long long> number, long long limit) {
            long long res = gao(number, limit);

            int n = number.size();
            for(int i = 0; i < bits; ++i) {
                if((limit >> i & 1)) {
                    long long L = limit >> (i + 1) << 1;
                    vector<long long> na = number;
                    for(int j = 0; j < n; ++j) {
                        na[j] = number[j] >> i;
                    }
                    res += gao(na, L);
                }
            }
            return res;
        }
};
