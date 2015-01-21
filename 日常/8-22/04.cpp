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
#pragma comment(linker,"/STACK:102400000,102400000")


char s[1000005][2];
int val[1000005];
struct node
{
    int fail;
    int next,pre;
    int val;
};
node root;



int main()
{
    int q;
    while(~scanf("%d",&q))
    {
        for(int i=0;i<q;++i)
        {
            scanf("%s",s);
            if(s[i][0]=='I')
            {
                scanf("%d",val+i);
            }
            else if(s[i][0]=='Q')
            {
                scanf("%d",val+i);
            }
            else if(s[i][0]=='L')
            {

            }
            else if(s[i][0]=='R')
            {

            }
            else if(s[i][0]=='D')
            {

            }

            {

            }
        }

    }
	return 0;
}
