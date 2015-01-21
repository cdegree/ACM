#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 105;
inline bool IsOdd(int k) {
    return k & 1;
}
inline void swap(int &a, int &b) {
    a = a + b;
    b = a - b;
    a = a - b;
}
int main() {
    int a[N];
    int n;
    while(~scanf("%d", &n)) { //输入数据个数。
        for(int i = 0; i < n; ++i) {
            scanf("%d", a + i);
        }
        int front = 0, tail = n - 1;
        while(front <= tail) {
            if(IsOdd(a[front]) && IsOdd(a[tail])) {//a
                ++front;
            }
            else if(IsOdd(a[front]) && !IsOdd(a[tail])) {//b
                ++front, --tail;
            }
            else if(!IsOdd(a[front]) && IsOdd(a[tail])) {//c
                swap(a[front], a[tail]);
            }
            else if(!IsOdd(a[front]) && !IsOdd(a[tail])) {//d
                --tail;
            }
        }

        for(int i = 0; i < n; ++i) {
            printf("%d%c", a[i], i == n - 1 ? '\n' : ' ');
        }
    }
}
