#include <cstdio>
#include <algorithm>
#include <map>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <set>
#include <queue>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;
DPLL(formula, assignment){
	necessary = deduction((formula, assignment);
	new_assignment = union(necessary, assignment);
	if(is_satisfied(formula, new_assignment))
        return SATISFIABLE;
    else if(is_confliction(formula, new_assignment))
        return CONFLICT;
    var = choose_free_variable(formula, new_assignment);
    assignment1 = union(new_assignment, assign(var,1));
    if(DPLL(formula, assignment1)==SATISFIABLE)
        return SATISFIABLE;
    else {
        assignment2 = union(new_assignment, assign(var,0));
        return DPLL(formula, assignment2);
    }
}

int main()
{
	return 0;
}
