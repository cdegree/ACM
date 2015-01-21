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

typedef long long LL;
const int N = 100005;
vector<int> son[N];
const LL mod = 1e9+7;
LL ans[N];

int dep[N];
int n;

void dfs(int u,int l,int r,int d) {
    if(dep[u]>r)return ;
    if(dep[u]>=l) {
        ans[u]+=d;
    }
    for(int i=0; i<son[u].size(); ++i) {
        int v = son[u][i];
        dfs(v,l,r,d);
    }
}
void dfs1(int u,int dp)
{
    dep[u]=dp;
    for(int i=0; i<son[u].size(); ++i) {
        int v = son[u][i];
        dfs1(v,dp+1);
    }
}
int main() {
    int T;
    scanf("%d",&T);
    for(int t=1; t<=T; ++t) {

        for(int i=0; i<N; ++i)son[i].clear(),ans[i]=0;
        scanf("%d",&n);
        dep[1]=1;
        for(int i=2; i<=n; ++i) {
            int v;
            scanf("%d",&v);
            dep[i]=dep[v]+1;
            son[v].push_back(i);
        }
        dfs1(1,1);
        int q;
        scanf("%d",&q);
        while(q--) {
            int u,l,r,d;
            scanf("%d %d %d %d",&u,&l,&r,&d);
            dfs(u,l,r,d);
        }
        LL res=0;
        LL m=12347;
        for(int i=1; i<=n; ++i) {
            res = (res*m+ans[i]+mod)%mod;
        }
        printf("Case %d: %lld\n",t,res);
    }
    return 0;
}
