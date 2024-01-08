#include "include.h"
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        long long ans = 0;
        bool neg = false;
        bool started = false;
        for(int i = 0; i < s.size(); i++){
            if(started && !(s[i] >= '0' && s[i] <= '9')) break;
            if(s[i] == ' ') continue;
            else if(s[i] == '+' && i != s.size()-1 && s[i+1] >= '0' && s[i+1] <= '9') continue;
            else if(s[i] == '-' && i != s.size()-1 && s[i+1] >= '0' && s[i+1] <= '9') neg = true;
            else if(s[i] >= '0' && s[i] <= '9'){
                started = true;
                ans*=10;
                ans += (s[i]-'0');
                if(ans > INT_MAX) return neg ? INT_MIN : INT_MAX;
            }
            else break;
            
        }
        if(neg) ans*=-1;
        return ans;
    }
};