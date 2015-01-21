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
using namespace std;
const double PI = acos(-1.0);
map<int,int>::iterator it;
typedef long long LL ;
#pragma comment(linker,"/STACK:102400000,102400000")
const int N = 100005;
int a[N],b[N],c[N],pos[N];

int main()
{
    int T;
    int n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=0; i<n; ++i)
        {
            int q;
            scanf("%d",&q);
            pos[q]=i;
            b[i]=q;
        }



        for(int i=0; i<n; ++i)printf("%d ",b[i]);
        puts("");
        for(int i=0; i<n; ++i)printf("%d ",c[i]);
        puts("");
    }
    return 0;
}
