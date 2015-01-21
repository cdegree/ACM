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

char s[4999];

int main() {

    while(gets(s)) {
        int n = strlen(s);
        int row = (n + 15) / 16;
        for(int i = 0; i < row; ++i) {
            printf("%04x: ", i * 16);
            for(int j = 0; j < 8; ++j) {
                if(i * 16 + j * 2 < n) {
                    char ch = s[i*16+j*2];
                    printf("%02x", ch);
                }
                else printf("  ");
                if(i * 16 + j * 2 + 1 < n) {
                    char ch = s[i*16+j*2+1];
                    printf("%02x", ch);
                }
                else printf("  ");
                putchar(' ');
            }
            for(int j = 0; j < 16; ++j) {
                if(s[i*16+j] == '\0')break;
                char ch = s[i*16+j];
                if(ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z') {
                    if(ch >= 'a' && ch <= 'z') {
                        ch = ch - 'a' + 'A' ;
                    }
                    else {
                        ch = ch - 'A' + 'a';
                    }
                }
                printf("%c", ch);
            }
            puts("");
        }
    }
    return 0;
}
