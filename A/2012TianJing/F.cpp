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

const int maxn = 100005 + 10000;
int wa[maxn], wb[maxn], wv[maxn], Ws[maxn];
int cmp(int *r, int a, int b, int l) {
    return r[a] == r[b] && r[a+l] == r[b+l];
}
void da(int *r,int *sa,int n,int m)
{
    int i,j,p,*x=wa,*y=wb,*t;
    for(i=0; i<m; i++) Ws[i]=0;
    for(i=0; i<n; i++) Ws[x[i]=r[i]]++;
    for(i=1; i<m; i++) Ws[i]+=Ws[i-1];
    for(i=n-1; i>=0; i--) sa[--Ws[x[i]]]=i;
    for(j=1,p=1; p<n; j*=2,m=p)
    {
        for(p=0,i=n-j; i<n; i++) y[p++]=i;
        for(i=0; i<n; i++) if(sa[i]>=j) y[p++]=sa[i]-j;
        for(i=0; i<n; i++) wv[i]=x[y[i]];
        for(i=0; i<m; i++) Ws[i]=0;
        for(i=0; i<n; i++) Ws[wv[i]]++;
        for(i=1; i<m; i++) Ws[i]+=Ws[i-1];
        for(i=n-1; i>=0; i--) sa[--Ws[wv[i]]]=y[i];
        for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1; i<n; i++)
            x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
    }
}


int rank[maxn], height[maxn];
void calheight(int *r, int *sa, int n) {
    int i, j, k = 0;
    for(i = 1; i <= n; ++i)rank[sa[i]] = i;
    for(i = 0; i < n; height[rank[i++]] = k)
        for(k ? k-- : 0, j = sa[rank[i] - 1]; r[i+k] == r[j+k]; ++k);
    return ;
}
int sa[maxn], r[maxn];
char sb[maxn];
void pf(int *s) {
    for(; *s; ++s) {
        printf("%c", *s);
    }
    puts("");
}
int main() {
    int m;
    freopen("Fin.txt", "r", stdin);
    while(~scanf("%d", &m)) {
        int n = 0;
        for(int i = 0; i < m; ++i) {
            scanf("%s", sb);
            printf("%s\n", sb);
            int len = strlen(sb);
            for(int j = 0; j < len; ++j) {
                r[n++] = sb[j];
            }
            r[n++] = 128+i;
        }
        r[n] = 0;
        pf(r);
        da(r, sa, n + 1, 256);
        calheight(r, sa, n);
        for(int i = 0; i < n; ++i) {
            printf("sa[%d] = %d\t", i, sa[i]  );
            pf(&r[sa[i]]);
            puts("");
        }
    }
    return 0;
}
