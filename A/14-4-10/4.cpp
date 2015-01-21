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

int d[66];
string s[66];
bool cmp(string a,string b) {
    return a<b;
}
int main() {
    int K;
    scanf("%d",&K);
    LL M;
    int n;
    while(K--) {
        cin>>M>>n;

        int m=0;
        LL F = M;
        while(F>0) {
            ++m;
            F>>=1;
        }
        if(m>=64)while(1);
        if(n>m) {
            for(int i=0; i<n; ++i) {
                s[i]="";
                for(int j=0; j<n; ++j) {
                    s[i]+='0';
                }
            }
            for(int i=0; i<n; ++i) {
                if(M>0) {
                    char c= (M&1)+'0';
                    M>>=1;
                    for(int j=0; j<n; ++j) {
                        s[j][(n-i-j-1+n)%n]=c;
                    }
                }
            }
        } else {
            while(1);
            for(int i=0; i<m; ++i) {
                s[i]="";
                for(int j=0; j<m; ++j) {
                    s[i]+='0';
                }
            }
            for(int i=0; i<m; ++i) {
                if(M>0) {
                    char c= (M&1)+'0';
                    M>>=1;
                    for(int j=0; j<m; ++j) {
                        s[j][(m-i-j-1+m)%m]=c;
                    }
                }
            }
        }
        sort(s,s+n,cmp);
        string res="";
        for(int i=0; i<n; ++i) {
            res += s[i][n-1];
        }
        cout<<res<<endl;
    }
    return 0;
}
