#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;
LL s[155];
LL now[155];
LL b[155];
int n,l;
LL read() {
    char s[155];
    scanf("%s",s);
    LL ret=0;
    for(int i=0; i<l; ++i) {
        ret<<=1;
        ret |= (s[i]-'0');
    }
    return ret;
}
const int N = 155;
LL mt[N][N];

void init() {
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            mt[i][j]=0;
            for(int k=0; k<l; ++k) {
                mt[i][j]<<=1;
                mt[i][j]|=((s[i]>>k)&1)!=((b[j]>>k)&1);
            }
        }
    }
}
int count_bit(LL m) {
    int ret=0;
    for(int i=0; i<l; ++i) {
        if((m>>i)&1)++ret;

    }
    return ret;
}
int uN,vN;//u,v数目
int link[N];
bool used[N];
int g[N][N];
bool dfs(int u) { //从左边开始找增广路径
    int v;
    for(v=0; v<vN; v++) { //这个顶点编号从0开始，若要从1开始需要修改
        if(g[u][v]&&!used[v]) {
            used[v]=true;
            if(link[v]==-1||dfs(link[v])) {
                //找增广路，反向
                link[v]=u;
                return true;
            }
        }
    }
    return false;//这个不要忘了，经常忘记这句
}
int bimatch(int n) {
    uN=vN=n;
    int res=0;
    int u;
    memset(link,-1,sizeof(link));
    for(u=0; u<uN; u++) {
        memset(used,0,sizeof(used));
        if(dfs(u)) res++;
    }
    return res;
}
int main() {
    freopen("A-large-practice.in","r",stdin);
    freopen("A-large-practice.out","w",stdout);
    int T;
    scanf("%d",&T);
    bool vis[155];
    for(int t=1; t<=T; ++t) {

        scanf("%d %d",&n,&l);
        for(int i=0; i<n; ++i) {
            s[i]=read();
        }
        int res=155;
        for(int i=0; i<n; ++i) {
            b[i]=read();
        }
        init();
        for(int i=0; i<n; ++i) {
            LL now = mt[0][i];
            memset(g,0,sizeof(g));
            for(int j=0; j<n; ++j) {
                for(int k=0; k<n; ++k) {
                    if(mt[j][k]==now) {
                        g[j][k]=1;
                    }
                }
            }
            int bi = bimatch(n);
            //printf("bi = %d\n",bi);
            if(bi==n) {
                res = min(res,count_bit(now));
            }
        }
        printf("Case #%d: ",t);
        if(res==155)puts("NOT POSSIBLE");
        else printf("%d\n",res);
    }
    return 0;
}
