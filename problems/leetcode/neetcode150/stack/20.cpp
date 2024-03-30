#include "include.h"
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> valid;
        valid['}'] = '{';
        valid[']'] = '[';
        valid[')'] = '(';
        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            if(c == '(' || c == '[' || c == '{'){
                st.push(c);
            }
            else{
                if(!st.empty() && st.top() == valid[c]) st.pop();
                else return false;
            }
        }
        return st.empty();

    }
};


