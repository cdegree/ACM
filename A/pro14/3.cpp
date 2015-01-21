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

const int N = 100005;
vector<int> e[N],c[N];
LL w[N];
int n;
LL res;
void dfs(int u,int pre,int src,LL dis) {
    if(u!=src) {
        res = max(res,dis*min(w[src],w[u])  );
        //printf("res = %lld\n",res);
    }
    for(int i=0; i<e[u].size(); ++i) {
        int v = e[u][i];
        if(v!=pre) {
            dfs(v,u,src,dis+c[u][i]);
        }
    }
}

int main() {
    int T;
    scanf("%d",&T);
    for(int t=1; t<=T; ++t) {
            for(int i=0;i<N;++i)
            {
                e[i].clear();
                c[i].clear();
            }
        scanf("%d",&n);
        for(int i=1; i<=n; ++i) {
            scanf("%lld",w+i);
        }
        for(int i=1; i<n; ++i) {
            int a,b,co;
            scanf("%d %d %d",&a,&b,&co);
            e[a].push_back(b);
            e[b].push_back(a);
            c[a].push_back(co);
            c[b].push_back(co);
        }
        res=0;
        for(int i=1; i<=n; ++i) {
            dfs(i,i,i,0);
        }
        printf("Case %d: ",t);
        printf("%lld\n",res);
    }
    return 0;
}
