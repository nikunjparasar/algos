#include "include.h"
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(ans, "", 0, 0, n);
        return ans;
    }

    void solve(vector<string>& ans, string curr, int openN, int closedN, int n){
        if(openN == closedN && openN == n) ans.push_back(curr);
        if(openN < n) solve(ans, curr+'(', openN+1, closedN, n);
        if(closedN < openN) solve(ans, curr+')', openN, closedN+1, n);
    }
};
