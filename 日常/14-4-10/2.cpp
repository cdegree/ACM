#include <cstdio>
#include <algorithm>
#include <map>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <set>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

int dp[105][105];
char s[105];
bool B(char a,char b) {
    return (a=='('&&b==')')||(a=='['&&b==']');
}
int best[105];
int main() {
    int N;
    scanf("%d",&N);
    while(N--) {
        scanf("%s",s);
        int n = strlen(s);
        memset(dp,0,sizeof(dp));

        for(int l=1; l<n; ++l) {
            for(int i=0; i<n; ++i) {
                if(i+l>n-1)continue;
                for(int j=i; j<i+l; ++j) {
                    dp[i][i+l]=max(dp[i][i+l],dp[i][j]+dp[j+1][i+l]);
                }
                if(B(s[i],s[i+l])) {
                    if(l==1||l==2) {
                        dp[i][i+l]=2;
                    } else {
                        dp[i][i+l]=max(dp[i][i+l],dp[i+1][i+l-1]+2);
                    }
                } else {
                    dp[i][i+l]=max(dp[i][i+l],dp[i][i+l-1]);
                    dp[i][i+l]=max(dp[i][i+l],dp[i+1][i+l]);
                }
            }
        }
/*
        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j) {
                printf("%4d",dp[i][j]);
            }
            puts("");
        }
        */
        printf("%d\n",n-dp[0][n-1]);
    }

    return 0;
}
