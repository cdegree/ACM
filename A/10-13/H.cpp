#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>
#include <string>
#include <cmath>

using namespace std;
typedef long long LL ;


int ID[256];
LL offset[55];
void init() {
    for(int i = 0; i < 26; ++i) {
        ID[i+'a'] = i;
        ID[i+'A'] = i + 26;
    }
    for(int i = 0; i < 52; ++i) {
        offset[i] = 1LL << i;
    }
}
const int N = 3 * 100100;
char s[N];

struct hash_map {
    int sz;
    static const int mod = 2000007;
    int head[mod];
    struct NODE {
        LL key;
        int cnt, pre;
    } nd[mod];
    void Init() {
        sz = 0;
        memset(head, -1, sizeof(head));
    }
    int Find(LL n) {
        int h = n % mod;
        for(int e = head[h]; ~e; e = nd[e].pre) {
            if(n == nd[e].key) {
                return e;
            }
        }
        return -1;
    }
    int Query(LL n) {
        int f = Find(n);
        if(~f) {
            return nd[f].cnt;
        }
        return 0;
    }
    void Insert(LL n) {
        int h = n % mod;
        int f = Find(n);
        if(~f) {
            ++nd[f].cnt;
        }
        else {
            nd[sz].key = n;
            nd[sz].cnt = 1;
            nd[sz].pre = head[h];
            head[h] = sz++;
        }
    }
} hash;

int main() {
    int n;
    init();
    //freopen("Hin.txt", "r", stdin);
    while(scanf("%d", &n) != EOF) {
        hash.Init();
        hash.Insert(0);
        scanf("%s", s);
        LL res = 0;
        LL q = 0;
        for(int i = 0; i < n; ++i) {
            int pos = ID[s[i]];
            q ^= offset[pos];
            q ^= (1LL << x);
            res += hash.Query(q);
            LL t = 1;
            for(int j = 0; j < 52; ++j) {
                LL p = t ^ q;
                t <<= 1;
                res += hash.Query(p);
            }
            hash.Insert(q);
        }
        printf("%lld\n", res);
    }
    return 0;
}
