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

const int N = 16;
int cnt4[N][N][N][N];
int cnt3[N][N][N][N];
int cnt2[N][N][N][N];
int cnt1[N][N];
int a[4];
char s[6];
int tod(char c)
{
    if(c<='9')return c-'0';
    else return c-'a'+10;
}
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;++i)
        {
            scanf("%s",s);
            for(int j=0;j<4;++j)
            {
                a[j]=tod(s[j]);
            }
            ++cnt4[ a[0] ][ a[1] ][ a[2] ][ a[3] ];
        }
    }
	return 0;
}
