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
#pragma comment(linker,"/STACK:102400000,102400000")
using namespace std;
const double PI = acos(-1.0);
map<int, int>::iterator it;
typedef long long LL ;
template<typename T> void checkmin(T &x, T y) {x = min(x, y);}
template<typename T> void checkmax(T &x, T y) {x = max(x, y);}

string pat="123abcd";

string transform(string s)
{
    int n = s.size();
    for(int i=0;i<n;++i)
    {
        int temp = s[i]*2+10;
        s[i] = (temp>120)?(temp/3):temp;
    }
    for(int i=0;i<n/2;++i)
    {
        swap(s[i],s[n-i-1]);
    }
    return s;
}

int main()
{
    cout<<pat<<endl;
    cout<<transform(pat)<<endl;
	return 0;
}
