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
#include <iostream>
using namespace std;

int a[6][6];
int res=1e9;
int row[6],col[6];
int mx;
int n,m;
void fuck(int cnt,int r,int c,int sum) {
    if(c==n) {
        c=0;
        ++r;
    }

    if(cnt>=mx) {
        bool ok=1;
        for(int i=0; i<m; ++i) {
            if(row[i]<=0) {
                ok=0;
            }//printf("%d",row[i]);
        }
        for(int i=0; i<n; ++i) {
            if(col[i]<=0) {
                ok=0;

            }//printf("%d",col[i]);
        }
        //puts("");
        if(ok) {
            res = min(res,sum);
        }
    }
    if(c<n&&r<m) {

        fuck(cnt,r,c+1,sum);
        if(sum+a[r][c]>res) {
            return ;
        }
        row[r]++;
        col[c]++;
        fuck(cnt+1,r,c+1,sum+a[r][c]);
        row[r]--;
        col[c]--;

    }
}
int main() {
    int T;
    scanf("%d",&T);
    for(int t=1; t<=T; ++t) {
        scanf("%d%d",&m,&n);
        res=1e9;
        memset(row,0,sizeof(row));
        memset(col,0,sizeof(col));
        mx=max(m,n);
        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                scanf("%d",&a[i][j]);
            }
        }
        fuck(0,0,0,0);
        printf("Case %d: %d\n",t,res);
    }
    return 0;
}
