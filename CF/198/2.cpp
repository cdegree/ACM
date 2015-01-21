#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <iostream>
#include <string>
#include <set>
#define X first
#define Y second
#define sqr(x) (x)*(x)
using namespace std;
const double PI = acos(-1.0);
typedef long long LL ;
#pragma comment(linker,"/STACK:102400000,102400000")
const int N = 100005;
int a[N];
int main()
{
    int n;
    while(cin>>n)
    {
        for(int i=1;i<=n;++i)cin>>a[i];
        set<int> st;
        set<int>::iterator it;
        st.insert(a[1]);
        for(int i=2;i<=n;++i)
        {
            it = st.lower_bound(a[i]);
            if(it==st.end())st.insert(a[i]);
            else
            {
                st.erase(it);
                st.insert(a[i]);
            }
        }
        printf("%d\n",(int)st.size());
    }
	return 0;
}
