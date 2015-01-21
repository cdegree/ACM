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


int a[500005];
deque<int> QL, QR, QM;
char s[11], t[3];
bool reversed;

void Insert(int k, int val) { //0 rep left
    if((!reversed && !k)  || (reversed && k)) {
        QM.push_front(val);
    }
    else {
        QM.push_back(val);
    }
}
int Pop(int k) {
    if((!reversed && !k)  || (reversed && k)) {
        int val = QM.front();
        QM.pop_front();
        return val;
    }
    else {
        int val = QM.back();
        QM.pop_back();
        return val;
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        QL.clear();
        QM.clear();
        QR.clear();
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) {
            scanf("%d", a + i);
        }
        int L, R;
        scanf("%d %d", &L, &R);
        reversed = 0;
        for(int i = 1; i < L; ++i) {
            QL.push_back(a[i]);
        }
        for(int i = L; i <= R; ++i) {
            QM.push_back(a[i]);
        }
        for(int i = R + 1; i <= n; ++i) {
            QR.push_back(a[i]);
        }
        int m;
        scanf("%d", &m);
        while(m--) {
            scanf("%s", s);
            if(strcmp(s, "MoveLeft") == 0) {
                scanf("%s", t);
                if(t[0] == 'L') {
                    --L;
                    int val = QL.back();
                    QL.pop_back();
                    Insert(0, val);
                }
                else {
                    --R;
                    int val = Pop(1);
                    QR.push_front(val);
                }
            }
            else if(strcmp(s, "MoveRight") == 0) {
                scanf("%s", t);
                if(t[0] == 'L') {
                    ++L;
                    int val = Pop(0);
                    QL.push_back(val);
                }
                else {
                    ++R;
                    int val = QR.front();
                    QR.pop_front();
                    Insert(1, val);
                }
            }
            else if(strcmp(s, "Insert") == 0) {
                scanf("%s", t);
                int val;
                scanf("%d", &val);
                if(t[0] == 'L') {
                    ++R;
                    Insert(0, val);
                }
                else {
                    ++R;
                    Insert(1, val);
                }
            }
            else if(strcmp(s, "Delete") == 0) {
                scanf("%s", t);
                if(t[0] == 'L') {
                    --R;
                    Pop(0);
                }
                else {
                    --R;
                    Pop(1);
                }
            }
            else if(strcmp(s, "Reverse") == 0) {
                reversed = !reversed;
            }
        }
        while(!QL.empty()) {
            printf("%d ", QL.front());
            QL.pop_front();
        }
        while(!QM.empty()) {
            if(!reversed) {
                printf("%d", QM.front());
                QM.pop_front();
            }
            else {
                printf("%d", QM.back());
                QM.pop_back();
            }
            if(QM.empty() && QR.empty())putchar('\n');
            else putchar(' ');
        }
        while(!QR.empty()) {
            printf("%d", QR.front());
            QR.pop_front();
            printf("%c", QR.empty() ? '\n' : ' ');
        }
    }
    return 0;
}
