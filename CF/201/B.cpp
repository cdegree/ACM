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

const int N = 105;
int dp[N][N];
string s1, s2, s3;
string res;
void gao(int i,int j,int k)
{
    if(k==n3)continue;
    printf("%d %d %d\n",i,j);
    if(dp[i][j]==0)return ;
    if(s1[i-1]==s2[j-1])
    {
        gao(i-1,j-1,k);
    }
    else if(dp[i-1][j]==dp[i][j-1]&&dp[i][j]==dp[i-1][j-1]+1)
    {
    }
    else if(dp[i-1][j]>dp[i][j-1])
    {
        gao(i-1,j,k);
    }
    else
    {
        gao(i-1,j,k);
    }
}
int main() {
    while(cin >> s1 >> s2 >> s3) {
        int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= n1; ++i) {
            for(int j = 1; j <= n2; ++j) {
                dp[i][j] = dp[i-1][j-1];
                if(s1[i-1] == s2[j-1])++dp[i][j];
                else {dp[i][j] = max(dp[i-1][j], dp[i][j-1]);}
            }
        }

        printf("%d 0 ",0);
        for(int i=0;i<n2;++i)printf("%c ",s2[i]);puts("");
        for(int i = 0; i <= n1; ++i) {
            if(i>0)printf("%c ",s1[i-1]);else printf("0 ");
            for(int j = 0; j <= n2; ++j) {
                printf("%d ", dp[i][j]);
            }puts("");
        }
        if(dp[n1][n2]==0)
        {
            puts("0");
            continue;
        }
        reverse(s3.begin(),s3.end());
        res="";
        gao(n1,n2);
        reverse(res.begin(),res.end());
    }

    return 0;
}
