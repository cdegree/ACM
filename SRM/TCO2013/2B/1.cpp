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
vector<int> v;
int gao[2002];
class FruitTrees {
public:
	int maxDist(int a, int b, int c) {
		int g= __gcd(a,b);
		//printf("%d\n",g);
		//printf("gcd = %d\n",__gcd(g,c));
		v.clear();
		v.push_back(a);
		v.push_back(b);
		v.push_back(c);
		sort(v.begin(),v.end());
		int ans=0;
		for(int i=v[0]/3;i>=0;--i)
		{
			//printf("%d:\n",i);
			//do
			//{
				for(int last=2*i;last<=v[0]-i;++last)
				{
					if(judge(i,last))
					{
						ans = i;
						break;
					}
				}
				//printf("*");
			//}
			//while(next_permutation(id,id+3));
			if(ans!=0)
			{
				break;
			}
		}
		return ans;
	}
	bool judge(int mid,int last)
	{
		int len=0;
		
		for(int i=0;i<=30;++i)
		{
			gao[len++]= i*v[ 0 ] ;
			gao[len++]=mid+i*v[ 1 ] ;
			gao[len++]=last+i*v[ 2] ;
		}
		sort(gao,gao+len);
		int mn=2000;
		for(int i=1;i<len;++i)
		{
			//printf("%d:%d\n",i,gao[i]);
			mn= min(mn,gao[i]-gao[i-1]);
		}
		return mn==mid;
	}
};

double test0() {
	int p0 = 1;
	int p1 = 5;
	int p2 = 8;
	FruitTrees * obj = new FruitTrees();
	clock_t start = clock();
	int my_answer = obj->maxDist(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int p0 = 3;
	int p1 = 3;
	int p2 = 6;
	FruitTrees * obj = new FruitTrees();
	clock_t start = clock();
	int my_answer = obj->maxDist(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int p0 = 40;
	int p1 = 30;
	int p2 = 20;
	FruitTrees * obj = new FruitTrees();
	clock_t start = clock();
	int my_answer = obj->maxDist(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 5;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int p0 = 899;
	int p1 = 1073;
	int p2 = 1147;
	FruitTrees * obj = new FruitTrees();
	clock_t start = clock();
	int my_answer = obj->maxDist(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 14;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	int p0 = 2000;
	int p1 = 2000;
	int p2 = 2000;
	FruitTrees * obj = new FruitTrees();
	clock_t start = clock();
	int my_answer = obj->maxDist(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 666;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
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