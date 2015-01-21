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
map<int,int>::iterator it;
typedef long long LL ;

int main()
{
    int n;
    string s;
    while(cin>>n>>s)
    {
        int m = s.size();
        int cnt=0;
        for(int i=0;i<m;++i)
        {
            if(i%n==0&&i>3)
            {
                if(s[i-1]==s[i-2]&&s[i-2]==s[i-3])
                {
                    ++cnt;
                }
            }
        }
        cout<<cnt<<endl;
    }
	return 0;
}
