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

class EelAndRabbit {
public:
	int getmax(vector <int> l, vector <int> t) {
		vector<int> cut;
		cut.clear();
		int n =l.size();
		for(int i=0;i<n;++i)
		{
			cut.push_back(-t[i]);
			cut.push_back(-t[i]-l[i]);
		}
		int best=1;
		int m = cut.size();
		for(int i=0;i<m;++i)
		{
			for(int j=0;j<m;++j)
			{
				int ans=0;
				for(int k=0;k<n;++k)
				{
					if(Cut(cut[i],-t[k],l[k])||Cut(cut[j],-t[k],l[k]))
					{
						++ans;
					}
				}
				if(ans>best)
				{
					best=ans;
					printf("%d %d\n",cut[i],cut[j]);
				}
			}
		}
		return best;
	}
	bool Cut(int y,int t,int l)
	{
		return y<=t&&y>=t-l;
	}
};

double test0() {
	int t0[] = {2, 4, 3, 2, 2, 1, 10};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {2, 6, 3, 7, 0, 2, 0};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	EelAndRabbit * obj = new EelAndRabbit();
	clock_t start = clock();
	int my_answer = obj->getmax(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 6;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
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
	int t0[] = {1, 1, 1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {2, 0, 4};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	EelAndRabbit * obj = new EelAndRabbit();
	clock_t start = clock();
	int my_answer = obj->getmax(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 2;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
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
	int t0[] = {1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	EelAndRabbit * obj = new EelAndRabbit();
	clock_t start = clock();
	int my_answer = obj->getmax(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
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
	int t0[] = {8, 2, 1, 10, 8, 6, 3, 1, 2, 5};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {17, 27, 26, 11, 1, 27, 23, 12, 11, 13};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	EelAndRabbit * obj = new EelAndRabbit();
	clock_t start = clock();
	int my_answer = obj->getmax(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 7;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
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