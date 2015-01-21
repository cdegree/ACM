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

class UndoHistory {
public:
	int minPresses(vector <string> lines) {
		int n = lines.size();
		string buf="";
		vector<string> his;
		his.clear();
		his.push_back("");
		//his.push_back("ab");
		//if(his[1].substr(0,0)=="")puts("NO");
		int ret=0;
		for(int i=0;i<n;++i)
		{
			if( (int)buf.size()<= (int)lines.size() && lines[i].substr(0,buf.size()) == buf )
			{
				for(int j=buf.size();j<lines[i].size();++j)
				{
					buf+=lines[i][j];
					his.push_back(buf);
					++ret;
				}
				++ret;
			}
			else 
			{
				int mx=-1,pos=-1;
				//cout<<"line:"<<lines[i]<<endl;
				for(int j=lines[i].size();j>=0;--j)
				{
					for( int k=0; k<his.size(); ++k)
					{
						//cout<<his[k]<<endl;
						if( lines[i].substr(0,j) == his[k] && mx<j)
						{
							//cout<<"OK"<<endl;
							buf = his[k];
							mx = j;
							pos = j;
							break;
						}
					}
					if(~pos)
					{
						break;
					}
				}
				ret += 2;
				//printf("pos=%d\n",pos);
				for(int j=pos;j<lines[i].size();++j)
				{
					buf+=lines[i][j];
					his.push_back(buf);
					++ret;
				}
				++ret;
			}
			printf("%d\n",ret);
		}
		return ret;
	}
};

double test0() {
	string t0[] = {"tomorrow", "topcoder"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	UndoHistory * obj = new UndoHistory();
	clock_t start = clock();
	int my_answer = obj->minPresses(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 18;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string t0[] = {"a","b"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	UndoHistory * obj = new UndoHistory();
	clock_t start = clock();
	int my_answer = obj->minPresses(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 6;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string t0[] = {"a", "ab", "abac", "abacus" };
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	UndoHistory * obj = new UndoHistory();
	clock_t start = clock();
	int my_answer = obj->minPresses(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 10;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	string t0[] = {"pyramid", "sphinx", "sphere", "python", "serpent"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	UndoHistory * obj = new UndoHistory();
	clock_t start = clock();
	int my_answer = obj->minPresses(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 39;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	string t0[] = {"ba","a","a","b","ba"}
;
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	UndoHistory * obj = new UndoHistory();
	clock_t start = clock();
	int my_answer = obj->minPresses(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 13;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
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