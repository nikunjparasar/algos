#include "include.h"
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans = "";
        string r1 = rev(num1);
        string r2 = rev(num2);
        int carry = 0;
        while(r1.size() ||  r2.size() || carry){
            int digit = 0;
            if(r1.size() && r2.size()) digit = (r1[0] - '0') + (r2[0] - '0') + carry;
            else if(!r1.size() && r2.size()) digit = (r2[0] - '0') + carry;
            else if(r1.size() && !r2.size()) digit = (r1[0] - '0') + carry;
            else digit = carry;
            carry = digit/10;
            digit%=10;
            ans += to_string(digit);
            if(r1.size()) r1 = r1.substr(1);
            if(r2.size()) r2 = r2.substr(1);
        }
        return rev(ans);

    }

    string rev(string num){
        int l = 0;
        int r = num.size()-1;
        while(l <= r){
            char temp = num[l];
            num[l] = num[r];
            num[r] = temp;
            r--;
            l++;
        }
        return num;
    }
};