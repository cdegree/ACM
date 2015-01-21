#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long LL ;
int ID[256], offset[52];
void init() {
    for(int i = 0; i < 26; ++i) {
        ID[i+'a'] = i;
        ID[i+'A'] = i + 26;
    }
    for(int i = 0; i < 52; ++i) {
        offset[i] = 1LL << i;
    }
}
const int N = 300003;
char s[N];

unsigned int hasha(char*url, int mod) {
    unsigned int n = 0;
    char *b = (char*) &n;
    for(int i = 0; url[i]; ++i) b[i % 4] ^= url[i];
    return n % mod;
}
unsigned int hashb(char*url, int mod) {
    unsigned int h = 0, g;
    while(*url) {
        h = (h << 4) + *url++;
        g = h & 0xF0000000;
        if(g) h ^= g >> 24;
        h &= ~g;
    }
    return h % mod;
}
int hashc(char*p, int prime = 25013) {
    unsigned int h = 0, g;
    for(; *p; ++p) {
        h = (h << 4) + *p;
        if(g = h & 0xf0000000) {
            h = h ^(g >> 24);
            h = h ^ g;
        }
    }
    return h % prime;
}

int cnt[10000022];
const int mod = 10000019;
void dtos(LL n, char *s) {
    int i = 0;
    while(n) {
        s[i++] = (n & 1) + '0';
        n /= 10;
    }
    s[i] = '\0';
}
char ch[55];
int main() {
    int n;
    init();
    //freopen("Hin.txt", "r", stdin);
    while(~scanf("%d", &n)) {
        scanf("%s", s);
        memset(cnt, 0, sizeof(cnt));
        dtos(0, ch);
        int h = hashb(ch, mod);
        printf("h = %d\n",h);
        cnt[ h] = 1;
        LL res = 0;
        LL t, p, q = 0;
        int pos, i, j;
        for(i = 0; i < n; ++i) {
            pos = ID[s[i]];
            q ^= offset[pos];
            //res += mp[q];
            dtos(q, ch);
            int h = hashb(ch, mod);
            printf("h = %d\n",h);
            res += cnt[h];
            //res += Cnt[ q%mod ];
            t = 1;
            for(j = 0; j < 52; ++j) {
                p = t ^ q;
                t <<= 1;
                //pf(p);
                //res += mp[p];
                dtos(p, ch);
                res += cnt[hashb(ch, mod)];
                //res += Cnt[p%mod];
            }
            ++cnt[h];
        }

        printf("%lld\n", res);
    }
    return 0;
}
