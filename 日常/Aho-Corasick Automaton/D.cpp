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

const int MAX_NODE = 521 * 64 ;
const int CHILD_NUM = 256;


class ACAutomaton {
    private:
        int chd[MAX_NODE][CHILD_NUM];
        int fail[MAX_NODE];
        int val[MAX_NODE];
        int Q[MAX_NODE];
        int sz;
    public:
        void Initialize() {
            fail[0] = 0;
        }
        void Reset() {
            sz = 1;
            memset(chd[0], -1, sizeof(chd[0]));
        }
        void Insert(int *s, int key, int n) {
            int q = 0;
            for(int i = 0; i < n; ++i) {
                int c = s[i];
                if(chd[q][c] == -1) {
                    memset(chd[sz], -1, sizeof(chd[sz]));
                    val[sz] = 0;
                    chd[q][c] = sz++;
                    if(sz == MAX_NODE)while(1);
                }
                q = chd[q][c];
            }
            val[q] = key;
        }
        void Construct() {
            int *s = Q, *e = Q;
            for(int i = 0; i < CHILD_NUM; ++i) {
                if(~chd[0][i]) {
                    fail[ chd[0][i] ] = 0;
                    *e++ = chd[0][i];
                }
            }
            while(s != e) {
                int r = *s++;
                for(int i = 0; i < CHILD_NUM; ++i) {
                    int u = chd[r][i];
                    if(~u) {
                        *e++ = u;
                        int v = fail[r];
                        while(chd[v][i] == -1 && v)v = fail[v];
                        fail[u] = chd[v][i] == -1 ? 0 : chd[v][i];
                    }
                }
            }
        }
        int Query(int *s, int n) {
            int q = 0;
            set<int> st;
            int ret = 0;
            for(int i = 0; i < n ; ++i) {
                int c = s[i];
                //printf("%c:\n", *s);
                while(chd[q][c] == -1 && q)q = fail[q];
                q = chd[q][c];
                if(q == -1)q = 0;
                int p = q;
                while(p) {
                    if(val[p]) {
                        //printf("val[%d]=%d\n", p, val[p]);
                        st.insert(val[p]);
                    }
                    p = fail[p];
                }
            }
            ret = st.size();
            return ret;
        }
} AC;

char mp[256];

void init() {
    for(int i = 0; i < 26; ++i) {
        mp['A'+i] = i;
        mp['a'+i] = 26 + i;
    }
    for(int i = 0; i < 10; ++i) {
        mp['0'+i] = i + 52;
    }
    mp['+'] = 62;
    mp['/'] = 63;
}

string dtos(int d) {
    string ret = "";
    for(int i = 5; i >= 0; --i) {
        if((1 << i)&d)ret += '1';
        else ret += '0';
    }
    return ret;
}

vector<int> Transfor(char *s) {
    int n = strlen(s);
    string ans = "";
    vector<int> ret;
    int cut = 0;
    if(s[n-1] == '=') {
        if(n > 1 && s[n-2] == '=') {
            n -= 2;
            cut = 4;
        }
        else {
            --n;
            cut = 2;
        }
    }
    for(int i = 0; i < n; ++i) {
        ans += dtos(mp[ s[i] ]);
    }
    while(cut--) {
        ans.erase(ans.begin() + ans.size() - 1);
    }
    int d = 0;
    //if((ans.size() % 8) != 0)while(1);
    for(int i = 0; i < ans.size(); ++i) {
        d |= (ans[i] == '1');
        if(i % 8 == 7) {
            ret.push_back(d);
            d = 0;
        }
        d <<= 1;
    }
    //for(int i = 0; i < ans.size(); ++i)printf("%3c", ans[i]); puts("");
    return ret;
}

char s[2056];
int pat[2048*6+3];
int main() {
    init();
    /*
        char s[] = "aGVsbG8=";
        vector<char> tmp = Transfor(s);
        for(int j = 0; j < tmp.size(); ++j) {
            pat[j] = tmp[j];
        }
        pat[ tmp.size()] = '\0';
        printf("%s\n", pat);
    */
    int n, m;
    AC.Initialize();
    while(~scanf("%d", &n)) {
        AC.Reset();
        for(int i = 0; i < n; ++i) {
            scanf("%s", s);
            vector<int> tmp = Transfor(s);
            for(int j = 0; j < tmp.size(); ++j) {
                pat[j] = tmp[j];
            }
            //printf("%s\n", pat);
            AC.Insert(pat, i + 1, (int)tmp.size());
        }
        AC.Construct();
        scanf("%d", &m);
        for(int i = 0; i < m; ++i) {
            scanf("%s", s);
            vector<int> tmp = Transfor(s);
            for(int j = 0; j < tmp.size(); ++j) {
                pat[j] = tmp[j];
            }
            //printf("%s\n", pat);
            int res = AC.Query(pat, (int)tmp.size());
            printf("%d\n", res);
        }
        puts("");
    }
    return 0;
}
