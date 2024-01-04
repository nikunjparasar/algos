#include "include.h"
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        stringstream iss(s);
        stack<string> st;
        string word;
        string ans;
        while(iss >> word){
            st.push(word);
        }
        while(!st.empty()){
            if(st.size() == 1){
                ans += st.top();
                st.pop();
            }
            else{
                ans += st.top();
                ans += " ";
                st.pop();
            }
        }
        return ans;
    }
};