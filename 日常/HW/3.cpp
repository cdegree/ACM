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

int ID[256];


char mp[4];

char s[1000];

int cnt[4][10];
int now[4][10];
int tr[4][10];
void pf() {
    for(int i=1; i<=3; ++i) {
        for(int j=1; j<=9; ++j) {
            printf("%2d",cnt[i][j]);
        }
        puts("");
    }
    puts("");
}
void pf(int a[4][10]) {
    puts("aaaaaaaaaa");
    for(int i=1; i<=3; ++i) {
        for(int j=1; j<=9; ++j) {
            printf("%2d",a[i][j]);
        }
        puts("");
    }
    puts("");
}
bool Three() {
    for(int i=1; i<=3; ++i) {
        for(int j=1; j<=9; ++j) {
            tr[i][j]=now[i][j];
        }
    }
    for(int i=1; i<=3; ++i) {
        for(int j=1; j<=9; ++j) {
            if(tr[i][j]>=3) {
                tr[i][j]-=3;
            }
            while(j<=7&&tr[i][j]>=1&&tr[i][j+1]>=1&&tr[i][j+2]>=1) {
                tr[i][j]--;
                tr[i][j+1]--;
                tr[i][j+2]--;
            }
        }
    }
    bool OK=true;
    for(int i=1; i<=3; ++i) {
        for(int j=1; j<=9; ++j) {
            if(tr[i][j]>=1) {
                //printf("%d %d\n",i,j);
                OK=false;
            }
        }
    }
    return OK;
}
bool Fu() {
    for(int i=1; i<=3; ++i) {
        for(int j=1; j<=9; ++j) {
            now[i][j]=cnt[i][j];
        }
    }
    bool OK=false;
    for(int i=1; i<=3&&!OK; ++i) {
        for(int j=1; j<=9&&!OK; ++j) {
            if(now[i][j]>=2) {
                now[i][j]-=2;
                //pf(now);
                if(Three()) {
                    //puts("GOOD");
                    OK=true;
                }
                now[i][j]+=2;
            }
        }
    }
    return OK;
}
bool Check() {
    int Count=0;
    for(int i=1; i<=3; ++i) {
        for(int j=1; j<=9; ++j) {
            if(cnt[i][j]>=1) {
                ++Count;
                break;
            }
        }
    }
    return Count<=2;
}
struct ans {
    int num;
    char ch;
    ans() {};
    ans(int _num,char _ch):num(_num),ch(_ch) {}
};
vector<ans> res;
int main() {
    ID['T']=1;
    ID['D']=2;
    ID['W']=3;
    mp[1]='T';
    mp[2]='D';
    mp[3]='W';
    scanf("%s",s);
    int n = strlen(s);
    memset(cnt,0,sizeof(cnt));
    for(int i=0; i<n; i+=2) {
        int num = s[i]-'0';
        char ch = s[i+1];
        cnt[ID[ch]][num]++;
    }
    //pf();
    res.clear();
    for(int i=1; i<=3; ++i) {
        for(int j=1; j<=9; ++j) {
            if(cnt[i][j]==4)continue;
            ++cnt[i][j];
            //pf();
            if(Fu()&&Check()) {
                res.push_back(ans(j,mp[i]));
                //printf("this is good\n");
            }
            --cnt[i][j];
        }
    }
    int len = res.size();
    printf("%d\n",len);
    for(int i=0; i<len; ++i) {
        printf("%d%c\n",res[i].num,res[i].ch);
    }

    return 0;
}
