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

int a[5][5];
int b[5][5];
int main() {
    int T;
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    scanf("%d",&T);
    for(int t=1; t<=T; ++t) {
        int r1,r2;
        scanf("%d",&r1);
        for(int i=0; i<4; ++i) {
            for(int j=0; j<4; ++j) {
                scanf("%d",&a[i][j]);
            }
        }
        scanf("%d",&r2);
        for(int i=0; i<4; ++i) {
            for(int j=0; j<4; ++j) {
                scanf("%d",&b[i][j]);
            }
        }
        --r1,--r2;
        set<int> st;
        vector<int> res;
        for(int i=0; i<4; ++i) {
            if(st.find(a[r1][i])==st.end()) {
                st.insert(a[r1][i]);
            } else {
                res.push_back(a[r1][i]);
            }
            if(st.find(b[r2][i])==st.end()) {
                st.insert(b[r2][i]);
            } else {
                res.push_back(b[r2][i]);
            }
        }
        int n= res.size();
        printf("Case #%d: ",t);
        if(n==1) {
            printf("%d\n",res[0]);
        } else if(n>1) {
            puts("Bad magician!");
        } else {
            puts("Volunteer cheated!");
        }
    }
    return 0;
}
