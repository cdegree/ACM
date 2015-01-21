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
using namespace std;

typedef long long LL ;
char s[20][29];
int main()
{
    int r,c;
    while(cin>>r>>c)
    {
        for(int i=0; i<r; ++i)scanf("%s",s[i]);
        int cnt=0;
        for(int i=0; i<r; ++i)
        {
            bool have=false;
            for(int j=0; j<c; ++j)
            {
                if(s[i][j]=='S')
                {
                    have=true;
                }
            }
            if(!have)
            {
                for(int j=0; j<c; ++j)
                {
                    if(s[i][j]=='.')
                    {
                        s[i][j]=',';
                        ++cnt;
                    }
                }
            }
        }
        for(int i=0; i<c; ++i)
        {
            bool have=false;
            for(int j=0; j<r; ++j)
            {
                if(s[j][i]=='S')
                {
                    have=true;
                }
            }
            if(!have)
            {
                for(int j=0; j<r; ++j)
                {
                    if(s[j][i]=='.')
                    {
                        s[j][i]=',';
                        ++cnt;
                    }
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
