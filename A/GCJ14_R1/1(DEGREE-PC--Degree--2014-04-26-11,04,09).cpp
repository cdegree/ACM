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
void display(LL*a) {
    for(int i=0; i<n; ++i) {
        printf("s[%5d]=%5d   ",i,a[i]);
        for(int j=0; j<l; ++j) {
            printf("%d",(a[i]>>j)&1);
        }
        puts("");
    }
}
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

void flip(int p) {
    for(int i=0; i<n; ++i) {
        if((s[i]>>p)&1) {
            s[i]&=(~(1LL<<p));
        } else {
            s[i]|=(1LL<<(p));
        }
    }
}
bool vis[155];
bool isOK(int p) {
    ++p;
    //display(s);
   // display(b);
    for(int i=0; i<n; ++i)vis[i]=false;
    bool OK=true;
    for(int i=0; i<n; ++i) {
        int id=-1;
        for(int j=0; j<n; ++j) {
            LL sb = (s[i]&((1LL<<p)-1));
            LL bb = (b[j]&((1LL<<p)-1));
            //printf("%lld %lld  -> %lld %lld\n",s[i],b[i],sb,bb);
            if(!vis[j]&&sb==bb) {
                id=j;
                break;
            }
        }
        //printf("id= %d\n",id);
        if(~id) {
            vis[id]=true;
        } else {
            OK=false;
            break;
        }
    }
    return OK;
}
int main() {
    //freopen("sub-3.in","r",stdin);
    //freopen("my_sub-3.out","w",stdout);
    int T;
    scanf("%d",&T);
    bool vis[155];
    for(int t=1; t<=T; ++t) {

        scanf("%d %d",&n,&l);
        for(int i=0; i<n; ++i) {
            s[i]=read();
        }
        int res;
        for(int i=0; i<n; ++i) {
            b[i]=read();
        }


        bool OK=true;
        int cnt=0;
        for(int i=0; i<l; ++i) {
                display(s);
        display(b);
        puts("***");
            if(!isOK(i)) {
                flip(i);
                ++cnt;
                if(!isOK(i)) {

                    printf("i = %d\n",i);
                    OK=false;
                    break;
                }
            }
        }
        if(OK)res=cnt;
        else res=155;


        /*
        for(int mask=0; mask<(1<<l); ++mask) {
            for(int i=0; i<n; ++i) {
                now[i]=s[i];
            }
            int cnt=0;
            //display();
            for(int i=0; i<l; ++i) {
                if((mask>>i)&1) {
                    ++cnt;
                    for(int j=0; j<n; ++j) {
                        if((now[j]>>i)&1) {
                            now[j]&=(~(1LL<<i));
                        } else {
                            now[j]|=(1LL<<(i));
                        }
                    }
                }
            }
            for(int i=0; i<n; ++i)vis[i]=false;
            bool OK=true;
            for(int i=0; i<n; ++i) {
                int p=-1;
                for(int j=0; j<n; ++j) {
                    if(!vis[j]&&now[j]==b[i]) {
                        p=j;
                    }
                }
                if(~p) {
                    vis[p]=true;
                } else {
                    OK=false;
                    break;
                }
            }
            if(OK&&res>cnt) {
                res=cnt;
            }
        }
        */
        printf("Case #%d: ",t);
        if(res==155)puts("NOT POSSIBLE");
        else printf("%d\n",res);
    }
    return 0;
}
