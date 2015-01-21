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
#include <cstring>
using namespace std;
set<int> post[55];
vector<int> s,t;
int n;
bool mtr[55][55];
class ShoutterDiv1 {
public:
	int count(vector <string> s1000, vector <string> s100, vector <string> s10, vector <string> s1, vector <string> t1000, vector <string> t100, vector <string> t10, vector <string> t1) {
		memset(mtr,false,sizeof(mtr));
		s.clear();
		t.clear();
		n = s1.size();
		
		n=0;
		for(int i=0;i<s1.size();++i)
		{
			for(int j=0;j<s1[i].size();++j)
			{
				++n;
				s.push_back(get_d(s1000[i][j],s100[i][j],s10[i][j],s1[i][j]));
				t.push_back(get_d(t1000[i][j],t100[i][j],t10[i][j],t1[i][j]));
			}
			
		}
		for(int i=0;i<n;++i)
		{
			post[i].clear();
			post[i].insert(i);
		}
		init();
		bool OK=true;
		for(int i=0;i<n;++i)
		{
			if(post[i].size()<n)
			{
				OK=false;
			}
		}
		int ret=0;
		while(!OK)
		{
			OK=true;
			int pos=-1,mx=0;
			for(int j=0;j<n;++j)
			{
				if(mx<post[j].size())
				{
					pos=j;
					mx=post[j].size();
				}
			}
			for(int i=0;i<n;++i)
			{
				if(mtr[pos][i])
				{
					for(set<int>::iterator j=post[pos].begin();j!=post[pos].end();++j)
					{
						if( post[i].find(*j)==post[i].end()){
							OK=false;
							printf("%d push %d to %d\n",pos,*j,i);
							
						}
					}
				}
			}
			++ret;
		}
		return ret;
	}
	void init()
	{
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<n;++j)
			{
				if(con(s[i],t[i],s[j],t[j]))
				{
					mtr[i][j]=true;
					post[i].insert(j);
				}
			}
		}
	}
	bool con(int s1,int t1,int s2,int t2)
	{
		return s1>=t2&&s2>=t1;
	}
	int get_d(char n1000,char n100,char n10,char n1)
	{
		return (n1000-'0')*1000+(n100-'0')*100+(n10-'0')*10+n1-'0';
	}
};
double test0() {
	string t0[] = {"22", "2"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"00", "0"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"11", "1"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	string t3[] = {"21", "4"};
	vector <string> p3(t3, t3+sizeof(t3)/sizeof(string));
	string t4[] = {"22", "2"};
	vector <string> p4(t4, t4+sizeof(t4)/sizeof(string));
	string t5[] = {"00", "0"};
	vector <string> p5(t5, t5+sizeof(t5)/sizeof(string));
	string t6[] = {"11", "1"};
	vector <string> p6(t6, t6+sizeof(t6)/sizeof(string));
	string t7[] = {"43", "6"};
	vector <string> p7(t7, t7+sizeof(t7)/sizeof(string));
	ShoutterDiv1 * obj = new ShoutterDiv1();
	clock_t start = clock();
	int my_answer = obj->count(p0, p1, p2, p3, p4, p5, p6, p7);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p8 = 2;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p8 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p8 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string t0[] = {"00"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"00"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"00"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	string t3[] = {"13"};
	vector <string> p3(t3, t3+sizeof(t3)/sizeof(string));
	string t4[] = {"00"};
	vector <string> p4(t4, t4+sizeof(t4)/sizeof(string));
	string t5[] = {"00"};
	vector <string> p5(t5, t5+sizeof(t5)/sizeof(string));
	string t6[] = {"00"};
	vector <string> p6(t6, t6+sizeof(t6)/sizeof(string));
	string t7[] = {"24"};
	vector <string> p7(t7, t7+sizeof(t7)/sizeof(string));
	ShoutterDiv1 * obj = new ShoutterDiv1();
	clock_t start = clock();
	int my_answer = obj->count(p0, p1, p2, p3, p4, p5, p6, p7);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p8 = -1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p8 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p8 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string t0[] = {"0000"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"0000"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"0000"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	string t3[] = {"1234"};
	vector <string> p3(t3, t3+sizeof(t3)/sizeof(string));
	string t4[] = {"0000"};
	vector <string> p4(t4, t4+sizeof(t4)/sizeof(string));
	string t5[] = {"0000"};
	vector <string> p5(t5, t5+sizeof(t5)/sizeof(string));
	string t6[] = {"0000"};
	vector <string> p6(t6, t6+sizeof(t6)/sizeof(string));
	string t7[] = {"2345"};
	vector <string> p7(t7, t7+sizeof(t7)/sizeof(string));
	ShoutterDiv1 * obj = new ShoutterDiv1();
	clock_t start = clock();
	int my_answer = obj->count(p0, p1, p2, p3, p4, p5, p6, p7);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p8 = 6;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p8 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p8 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	string t0[] = {"0000000000"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"0000000000"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"0000000000"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	string t3[] = {"7626463146"};
	vector <string> p3(t3, t3+sizeof(t3)/sizeof(string));
	string t4[] = {"0000000000"};
	vector <string> p4(t4, t4+sizeof(t4)/sizeof(string));
	string t5[] = {"0000000000"};
	vector <string> p5(t5, t5+sizeof(t5)/sizeof(string));
	string t6[] = {"0000000000"};
	vector <string> p6(t6, t6+sizeof(t6)/sizeof(string));
	string t7[] = {"9927686479"};
	vector <string> p7(t7, t7+sizeof(t7)/sizeof(string));
	ShoutterDiv1 * obj = new ShoutterDiv1();
	clock_t start = clock();
	int my_answer = obj->count(p0, p1, p2, p3, p4, p5, p6, p7);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p8 = 18;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p8 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p8 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	string t0[] = {"00000000000000000000000000000000000000000000000000"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"00000000000000000000000000000000000000000000000000"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"50353624751857130208544645495168271486083954769538"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	string t3[] = {"85748487990028258641117783760944852941545064635928"};
	vector <string> p3(t3, t3+sizeof(t3)/sizeof(string));
	string t4[] = {"00000000000000000000000000000000000000000000000000"};
	vector <string> p4(t4, t4+sizeof(t4)/sizeof(string));
	string t5[] = {"00000000000000000000000000000000000000000000000000"};
	vector <string> p5(t5, t5+sizeof(t5)/sizeof(string));
	string t6[] = {"61465744851859252308555855596388482696094965779649"};
	vector <string> p6(t6, t6+sizeof(t6)/sizeof(string));
	string t7[] = {"37620749792666153778227385275518278477865684777411"};
	vector <string> p7(t7, t7+sizeof(t7)/sizeof(string));
	ShoutterDiv1 * obj = new ShoutterDiv1();
	clock_t start = clock();
	int my_answer = obj->count(p0, p1, p2, p3, p4, p5, p6, p7);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p8 = 333;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p8 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p8 != my_answer) {
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
	
	time = test4();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}



//Powered by [KawigiEdit] 2.0!