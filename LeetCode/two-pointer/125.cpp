#include "include.h"
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string q = "";
        for(int i = 0; i < s.size(); i++){
            if(isalnum(s[i])){
                q += tolower(s[i]);
            }
        }

        int l = 0;
        int r = q.size()-1;
        while(l < r){
            if(q[l] != q[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};