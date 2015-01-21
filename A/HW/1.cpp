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

struct Vote {
    string cand;
    long long cnt;
};

vector<Vote> vt;
vector<string> cd;

int main() {
    string a,b;
    vt.clear();
    long long cnt=0;
    while(cin>>a) {
        if(a[0]=='a') {
            cin>>b;
            Vote v;
            v.cand=b;
            v.cnt=0;
            vt.push_back(v);
        } else if(a[0]=='v') {
            cin>>b;
            int p=-1;
            for(int i=0; i<vt.size(); ++i) {
                if(vt[i].cand==b) {
                    p=i;
                    break;
                }
            }
            if(~p) {
                vt[p].cnt++;
            } else {
                ++cnt;
            }
        } else {
            break;
        }
    }
    for(int i=0; i<vt.size(); ++i) {
        cout<<vt[i].cand<<" "<<vt[i].cnt<<endl;
    }
    cout<<cnt<<endl;
    return 0;
}
