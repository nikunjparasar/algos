#include "include.h"
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        backtrack(n, 0, 0, "", ans);
        return ans;
    }

    void backtrack(int n, int openN, int closedN, string curr, vector<string>& ans){
        if(openN == n && closedN == n) ans.push_back(curr);
        if(openN < n)backtrack(n, openN+1, closedN, curr + "(", ans);
        if(closedN < openN) backtrack(n, openN, closedN+1, curr+")", ans);
    }
};