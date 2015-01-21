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
set<LL> st;
int main() {
    int n;
    st.clear();
    cin>>n;
    LL a;
    for(int i=0; i<n; ++i) {
        cin>>a;
        if(st.find(a)==st.end()) {
            st.insert(a);
        } else {
            st.erase(a);
        }
    }
    if(st.empty()) {
        cout<<-1<<endl;
    } else {
        cout<<*st.begin()<<endl;
    }
    return 0;
}
