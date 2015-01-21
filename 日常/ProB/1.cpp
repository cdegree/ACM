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

int gete(char *ch) {
    if(strlen(ch)==1)return 9;
    switch(ch[0]) {
    case'n':
        return 0;
    case'u':
        return 3;
    case'm':
        return 6;
    case'c':
        return 7;
    case'd':
        return 8;
        return 9;
    }
}
LL read() {
    string s;
    cin>>s;
    int n = s.size();

}
int main() {
    int T;
    scanf("%d",&T);
    for(int t=1; t<=T; ++t) {
        double x[3];
        char s[3][5];
        int e[3];

        for(int i=0; i<3; ++i) {
            scanf("%lf%s",&x[i],s[i]);
            e[i]=gete(s[i]);
        }
        //printf("%d %d %d\n",e[0],e[1],e[2]);
        while(e[0]<e[1])
        {
            x[1]*=10;
            e[1]--;
        }
        while(e[1]<e[0])
        {
            x[0]*=10;
            e[0]--;
        }
        //printf("%d %d %d\n",e[0],e[1],e[2]);
        //printf("%.2f %.2f %.2f\n",x[0],x[1],x[2]);
        double res = x[0]*x[2]/x[1];
        printf("Case %d: %.2fpx\n",t,res);





    }
    return 0;
}
