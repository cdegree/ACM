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
const int N  =1005;
struct person
{
    string name;
    int val;
    int type;
}A[N],B[N],C[N],P[N];
int len1,len2,len3;
vector<pair<string,string> > vp;
bool vis[N];
struct node
{
    int id;
    int val;
    int type;
    node(int _id,int _val,int _type)
    {
        type = _type;
        id=_id;
        val=_val;
    }
    node(){}
};
bool cmp(node a,node b)
{
    return a.val>b.val;
}
void gao(vector<node> a,vector<node> b)
{
    sort(a.begin(),a.end(),cmp);
    sort(b.begin(),b.end(),cmp);
    int n1 = a.size();
    int n2 = b.size();
    for(int i=0;i<n1;i++)
    {
        int val = a[i].val;
        if( vis[ a[i].id ])continue;
        for(int j=0;j<n2;j++)
        {
            if(vis[ b[j].id ])continue;
            if(b[j].val<val-2)break;
            if(abs(b[j].val-val)==2)
            {
                vis[ b[j].id ]=true;
                vis[ a[i].id ]=true;
                if(a[i].type==1||b[j].type==2)vp.push_back(make_pair( P[a[i].id].name,P[b[j].id ].name));
                else vp.push_back(make_pair( P[b[j].id].name,P[a[i].id ].name));
                break;
            }
        }
    }
}

int main()
{
    int n;
    while(cin>>n)
    {
        string a,b;
        memset(vis,false,sizeof(vis));
        vp.clear();
        int val;
        for(int i=0;i<n;i++)
        {
            cin>>a>>b>>val;
            P[i].name=a;
            P[i].val=val;
            if(b[0]=='a')
            {
                P[i].type=3;
            }
            else if(b[0]=='s')
            {
                P[i].type=1;
            }
            else
            {
                P[i].type=2;
            }
        }
        vector<node> va,vb;
        va.clear();
        vb.clear();
        for(int i=0;i<n;i++)
        {
            if(P[i].type==1)
            {
                vb.push_back(node(i,P[i].val,1));
            }
            else if(P[i].type==2)
            {
                va.push_back(node(i,P[i].val,2));
            }
        }
        gao(va,vb);
        va.clear();
        vb.clear();
        for(int i=0;i<n;i++)
        {
            if(vis[i])continue;
            if(P[i].type==3)
            {
                vb.push_back(node(i,P[i].val,3));
            }
            else if(P[i].type==1)
            {
                va.push_back(node(i,P[i].val,1));
            }
            else if(P[i].type==2)
            {
                va.push_back(node(i,P[i].val,2));
            }
        }
        gao(va,vb);
        va.clear();
        vb.clear();
        for(int i=0;i<n;i++)
        {
            if(vis[i])continue;
            if(P[i].type==3)
            {
                vb.push_back(node(i,P[i].val,3));
                va.push_back(node(i,P[i].val,3));
            }
        }
        gao(va,vb);
        int len = vp.size();
        cout<<len<<endl;
        for(int i=0;i<len;i++)
        {
            cout<<vp[i].first<<" "<<vp[i].second<<endl;
        }
        //printf("why re!\n");
    }
	return 0;
}
