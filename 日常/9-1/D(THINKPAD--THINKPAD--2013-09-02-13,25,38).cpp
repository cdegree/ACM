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

const int N = 55;
const int K = 8;
int dp[1<<K][1<<K][N];

int T,n,m,k;

struct edge {
    int u,v,w,pre;
} E[N*N];

int BT[N],FT[N];
int head[N],cnt;
void add_edge(int u,int v,int w) {
    E[cnt].u=u;
    E[cnt].v=v;
    E[cnt].w=w;
    E[cnt].pre=head[u];
    head[u]=cnt++;
}
int ticket[N],attraction[N];
int ccost[1<<K][1<<K];
int W[55][55];
const int inf=1e9;
void init() {
    memset(head,-1,sizeof(head));
    for(int i=0; i<(1<<K); ++i)for(int j=0; j<(1<<K); ++j)for(int k=0; k<N; ++k)dp[i][j][k]=inf;
    for(int i=1;i<N;++i)for(int j=1;j<N;++j)W[i][j]=inf;
    memset(ticket,0,sizeof(ticket));
    memset(attraction,0,sizeof(attraction));
    cnt=0;
}
inline bool test_bit(int mask,int pos) {
    return ((1<<pos)&mask)!=0;
}
inline bool all(int mask) {
    return mask==((1<<k)-1);
}

bool mp[55][55];


void checkmin(int &x,int y) {
    x = min(x,y);
}

int main() {
    scanf("%d",&T);
    for(int t=1; t<=T; ++t) {
        scanf("%d%d%d",&n,&m,&k);
        int u,v,w;
        init();
        for(int i=0; i<m; ++i) {
            scanf("%d%d%d",&u,&v,&w);
            --u,--v;
            W[u][v]=W[v][u]=min(W[u][v],w);
            //add_edge(v,u,w);
        }
        for(int i=0; i<n; ++i)W[i][i]=inf;
        for(int u=0; u<n; ++u) {
            for(int i=0; i<n; ++i) {
                for(int j=0; j<n; ++j) {
                    W[i][j]=min(W[i][u]+W[u][j],W[i][j]);
                }
            }
        }
        int f,fn;
        for(int i=0; i<k; ++i) {
            scanf("%d%d%d%d",&f,BT+i,FT+i,&fn);
            int pk = (1<<i);
            attraction[f-1] |= pk;
            for(int j=0; j<fn; ++j) {
                int fi;
                scanf("%d",&fi);
                ticket[fi-1] |= pk;
            }
        }
        printf("Case #%d: ",t);
        int mask = (1<<k);
        dp[0][0][0]=0;

        for(int Imask=0; Imask<mask; ++Imask) {
            for(int Jmask=0; Jmask<mask; ++Jmask) {
                if(!(Imask & Jmask)) {
                    for(int u=0; u<n; ++u) {
                        if(dp[Imask][Jmask][u]<inf) {
                            for(int v=0; v<n; ++v) {
                                if(v!=u) {
                                    int tmp = dp[ Imask ][ Jmask ][u] + W[u][v];
                                    checkmin( dp[ Imask ][ (Jmask|ticket[v])&(~Imask) ][v] , tmp);
                                    for(int p=0; p<k; ++p) {
                                        if( !((Imask>>p)&1) && ((attraction[v]>>p)&1)  ) {
                                            tmp += (  (Jmask>>p)&1  )?FT[p]:BT[p];
                                        }
                                    }
                                    checkmin(dp[ Imask|attraction[v] ][ (Jmask | ticket[v]) & (~(Imask | attraction[v])) ][v] ,tmp);
                                }
                            }
                        }
                    }
                }
            }
        }

        //dfs(0,0,0);
        int res = 1e8;
        res = dp[ mask-1 ][ 0 ][1];
        printf("%d\n",res);
    }
    return 0;
}
