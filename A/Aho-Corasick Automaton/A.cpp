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

//MAX_NODE = StringNumber * StringLength
const int MAX_NODE = 500000 + 50;
//�ڵ�����,һ���ַ���ʽ����26��
const int CHILD_NUM = 26;
//�ض���Ŀ��Ҫ
const int mod = 20090717;

class ACAutomaton {
    private:
        //ÿ���ڵ��Ķ���,����ǰ�ڵ���״̬ת��
        int chd[MAX_NODE][CHILD_NUM];
        //��¼��Ŀ���Ĺؼ�����
        int val[MAX_NODE];
        //��˵�е�failָ��
        int fail[MAX_NODE];
        //����,���ڹ������ȼ���failָ��
        int Q[MAX_NODE];
        //��ĸ��Ӧ��ID
        int ID[128];
        //��ʹ�ýڵ�����
        int sz;
    public:
        //��ʼ��,������ĸ��Ӧ�Ķ���ID,��:'a'->0 ... 'z'->25
        void Initialize() {
            fail[0] = 0;
            for(int i = 0 ; i < CHILD_NUM ; i ++) {
                ID[i+'a'] = i;
            }
        }
        //���½�������Reset
        void Reset() {
            memset(chd[0] , -1 , sizeof(chd[0]));
            sz = 1;
        }
        //��ȨֵΪkey���ַ���a���뵽trie��
        void Insert(char *a, int key) {
            int p = 0;
            for(; *a ; ++ a) {
                int c = ID[*a];
                if(chd[p][c] == -1) {
                    memset(chd[sz] , -1 , sizeof(chd[sz]));
                    val[sz] = 0;
                    chd[p][c] = sz ++;
                }
                p = chd[p][c];
            }

            val[p] += key;
        }
        //����AC�Զ���,ȷ��ÿ���ڵ���Ȩֵ�Լ�״̬ת��
        void Construct() {
            int *s = Q , *e = Q;
            for(int i = 0 ; i < CHILD_NUM ; i ++) {
                if(~chd[0][i]) {
                    fail[ chd[0][i] ] = 0;
                    *e ++ = chd[0][i];
                }
            }
            while(s != e) {
                int r = *s++;
                for(int i = 0 ; i < CHILD_NUM ; i ++) {
                    int u = chd[r][i];
                    if(~u) {
                        *e ++ = u;
                        int v = fail[r];
                        while(chd[v][i] == -1 && v)v = fail[v];

                        fail[u] = chd[v][i] == -1 ? 0 : chd[v][i];
                    }
                }
            }
        }
        //ѯ�������ַ����������ٸ�ģʽ��
        int Query(char *s) {
            int q = 0;
            int ret = 0;
            for(; *s; ++s) {
                int c = ID[*s];
                while(chd[q][c] == -1 && q)q = fail[q];
                q = chd[q][c];
                if(q == -1)q = 0;
                int p = q;
                while(p) {
                    if(val[p]) {
                        ret += val[p];
                        val[p] = 0;
                    }
                    else {
                        break;
                    }
                    p = fail[p];
                }
            }
            return ret;
        }
} AC;

char s[1000005], t[10005];
int main() {
    int T;
    AC.Initialize();
    scanf("%d", &T);
    while(T--) {
        AC.Reset();
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) {
            scanf("%s", t);
            AC.Insert(t, 1);
        }
        AC.Construct();
        scanf("%s", s);
        int res = AC.Query(s);
        printf("%d\n", res);
    }
    return 0;
}
