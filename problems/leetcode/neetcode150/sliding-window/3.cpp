#include "include.h"
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> cset;
        int ans = 0;
        int start = 0;
        int end = 0;
        while(end < s.size()){
            if(cset.find(s[end]) == cset.end()){
                cset.insert(s[end]);
                ans = max(ans, end-start+1);
                end++;
            }
            else{
                cset.erase(s[start]);
                start++;
            }
        }
        return ans;
    }
};