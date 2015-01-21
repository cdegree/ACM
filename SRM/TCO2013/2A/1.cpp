#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class TheLargestString {
public:
	int n;
	string  res;
	string cao1,cao2;
	int pri[55];
	void gao(int cur,string s,string t)
	{
		gao(cur+1,s+cao1[cur],t+cao2[cur]);
		gao(cur+1,s,t);
	}
	string find(string s, string t) {
		int pos=0;
		cao1=s;
		cao2=t;
		char c='a'-1;
		res="zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
		n=s.size();
		for(int i=0;i<n;i++)
		{
			if(s[i]>c)
			{
				c=s[i];
				pos=i;
			}
			else if(s[i]==c)
			{
				if(t[i]>t[pos])
				{
					pos=i;
				}
			}
		}
		for(int i=pos;i<n;)
		{
			for(int j=pos+1;j<n;j++)
			{

			}
		}
		bool vis[55];
		for(int i=0;i<55;i++){
			vis[i]=false;
		}
		printf("pos = %d\n",pos);
		string a="",b="";
		a+=s[pos];
		b+=t[pos];
		gao(pos+1,a,b)
		for(int i=pos;i<n;)
		{
			vis[i]=true;
			printf("i = %d\n",i );
			int idx=-1;
			char cc = 'a'-1;
			for(int j=i+1;j<n;j++)
			{
				if(s[j]>cc)
				{
					idx=j;
					cc=s[j];
				}
				else 
				{

				}
			}
			printf("idx = %d\n",idx);
			if(idx!=-1)
			{
				if(s[idx]>=t[i])
				{
					i=idx;
				}
				else 
				{
					break;
				}
			}
			else 
			{
				break;
			}
		}
		string ret="";
		for(int i=0;i<n;i++)
		{
			if(vis[i])
			{
				ret +=s[i];
			}
		}
		for(int i=0;i<n;i++)
		{
			if(vis[i])
			{
				ret +=t[i];
			}
		}
		return ret;
	}
};

double test0() {
	string p0 = "ab";
	string p1 = "zy";
	TheLargestString * obj = new TheLargestString();
	clock_t start = clock();
	string my_answer = obj->find(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "by";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string p0 = "abacaba";
	string p1 = "zzzaaaa";
	TheLargestString * obj = new TheLargestString();
	clock_t start = clock();
	string my_answer = obj->find(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "cbaaaa";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string p0 = "x";
	string p1 = "x";
	TheLargestString * obj = new TheLargestString();
	clock_t start = clock();
	string my_answer = obj->find(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "xx";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	string p0 = "abbabbabbababaaaabbababab";
	string p1 = "bababbaabbbababbbbababaab";
	TheLargestString * obj = new TheLargestString();
	clock_t start = clock();
	string my_answer = obj->find(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "bbbbbbbbbbbbbbbbbbaaab";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
int main() {
	int time;
	bool errors = false;
	
	time = test0();
	if (time < 0)
		errors = true;
	
	time = test1();
	if (time < 0)
		errors = true;
	
	time = test2();
	if (time < 0)
		errors = true;
	
	time = test3();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}


//Powered by [KawigiEdit] 2.0!
