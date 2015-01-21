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

int main() {
    long long n,m,v,k;
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%I64d %I64d %I64d %I64d",&n,&m,&v,&k);
        int res=0;
        bool can=true;
        int pre=-1;
        while(m<n) {
            if(m-v<=1) {
                can=false;
            }
            m = (m-v)*k;
            if(m<=pre) {
                can=false;
            }
            pre=m;
            ++res;
            if(!can)break;
        }
        if(can) {
            printf("%d\n",res);
        } else puts("-1");
    }
    return 0;
}
