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
typedef long long LL;

void set_bit(LL &mask, int pos) {
    mask |= (1LL << pos);
}
class BitwiseAnd {
    public:
        vector<LL> lexSmallest(vector<LL> a, int N) {
            int n = a.size();
            sort(a.begin(), a.end());
            vector<LL> ret;
            int m = N * (N - 1) / 2;
            if(m > 60)return ret;
            else {
                bool wujie = false;
                for(int i = 0; i < n; ++i) {
                    for(int j = i + 1; j < n; ++j) {
                        if((a[i]&a[j]) == 0)wujie = 1;
                    }
                }
                for(int i = 0; i < n; ++i) {
                    for(int j = i + 1; j < n; ++j) {
                        for(int k = j + 1; k < n; ++k) {
                            if((a[i]&a[j]&a[k])) {
                                wujie = 1;
                            }
                        }
                    }
                }
                if(wujie) {
                    return ret;
                }
                else {
                    LL vismask = 0, havemask = 0;
                    m = N - 1;
                    //printf("m = %d\n", m);
                    for(int i = 0; i < N; ++i) {
                        if(i < n) {
                            for(int j = 0; j < ret.size(); ++j) {
                                vismask |= (ret[j] & a[i]);
                            }
                            ret.push_back(a[i]);
                            havemask |= a[i];
                        }
                        else {
                            LL mask = 0;
                            bool ok = 1;
                            int pre = -1;
                            for(int j = 0; j < m; ++j) {
                                int pos = -1;
                                if(j < ret.size()) {
                                    for(int k = 0; k < 60; ++k) {
                                        if(!((vismask >> k) & 1) && ((ret[j] >> k) & 1)) {
                                            pos = k;
                                            break;
                                        }
                                    }
                                    if(~pos) {
                                        vismask |= (1LL << pos);
                                    }
                                }
                                else {
                                    for(int k = pre + 1; k < 60; ++k) {
                                        if(!((vismask >> k) & 1) && !((havemask >> k) & 1)) {
                                            pos = k;
                                            break;
                                        }
                                    }
                                }
                                //printf("j = %d pos =%d\n", j, pos);
                                if(~pos) {
                                    mask |= 1LL << pos;
                                    pre = pos;
                                }
                                else {
                                    ok = 0;
                                    break;
                                }
                            }
                            //printf("i = %d ok = %d  mask = %lld\n", i, ok, mask);
                            if(ok) {
                                //printf("%d = %lld\n", i, mask);
                                ret.push_back(mask);
                                havemask |= mask;
                            }
                            else {
                                //puts("fff");
                                vector<LL> tmp;
                                return tmp;
                            }
                        }
                    }
                }
                sort(ret.begin(), ret.end());
                if(ret[ ret.size()-1 ] > (1LL << 60) - 1) {
                    vector<LL> tmp;
                    return tmp;
                }
                return ret;
            }
        }
};



//Powered by [KawigiEdit] 2.0!
