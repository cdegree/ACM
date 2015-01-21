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

class CostOfDancing {
public:
	int minimum(int, vector <int>);
};

int CostOfDancing::minimum(int K, vector <int> danceCost) {
	vector<int> d = danceCost;
	int n =d.size();
	sort(d.begin(),d.end());
	int ret=0;
	for(int i=0;i<K;++i)
    {
        ret += d[i];
    }
    return ret;
}

