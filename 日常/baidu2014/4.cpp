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
    int n;
    while(~scanf("%d",&n)) {
        int a[20];
        for(int i=0; i<n; ++i)a[i]=i+1;
        int cnt=0;
        for(int mask=0; mask<(1<<n); ++mask) {
            vector<int> f;
            for(int i=0; i<n; ++i) {
                if((mask>>i)&1) {
                    f.push_back(a[i]);
                }
            }
            sort(f.begin(),f.end());
            bool OK=true;
            for(int i=0; i<f.size()&&OK; ++i) {
                for(int j=i+1; j<f.size()&&OK; ++j) {
                    if( (f[i]+f[j])%2==0 ) {
                        int r = f[i]+f[j];
                        r/=2;
                        bool ok=false;
                        for(int k=0; k<f.size(); ++k) {
                            if(r==f[k]) {
                                ok=true;
                                break;
                            }
                        }
                        if(!ok) {
                            OK=false;
                            break;
                        }
                    }
                }
            }
            if(OK) {
                for(int i=0;i<f.size();++i)
                {
                    printf("%d ",f[i]);
                }puts("");
                ++cnt;
            }
        }
        printf("cnt = %d\n",cnt);
    }
    int in;
    int T;


    scanf("%d",&T);
    for(int t=1; t<=T; ++t) {

    }

    return 0;
}
